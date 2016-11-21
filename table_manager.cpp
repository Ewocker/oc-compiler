#include "table_manager.h"

// constructor
TableManager::TableManager(astree *root, FILE *out) {
    this->out = out;
    this->root = root;
    scope_nr = 0;
    errors = 0;

    current_struct = nullptr;
    current_function = nullptr;

    // attribute primitive
    attr_prim[ATTR_char] = 1;
    attr_prim[ATTR_int] = 1;
    attr_prim[ATTR_bool] = 1;

    // attribute reference
    attr_ref[ATTR_array] = 1;
    attr_ref[ATTR_struct] = 1;
    attr_ref[ATTR_string] = 1;
    attr_ref[ATTR_null] = 1;

    // attribute reference or primitive
    attr_prim_or_ref[ATTR_char] = 1;
    attr_prim_or_ref[ATTR_int] = 1;
    attr_prim_or_ref[ATTR_bool] = 1;
    attr_prim_or_ref[ATTR_array] = 1;
    attr_prim_or_ref[ATTR_struct] = 1;
    attr_prim_or_ref[ATTR_string] = 1;
    attr_prim_or_ref[ATTR_null] = 1;


    // attribute array
    attr_array[ATTR_char] = 1;
    attr_array[ATTR_int] = 1;
    attr_array[ATTR_bool] = 1;
    attr_array[ATTR_struct] = 1;
    attr_array[ATTR_string] = 1;
}

// convert TOK_... to ATTR_...
// e.g. TOK_BOOL -> ATTR_bool
int TableManager::tok2attr(int token) {
    switch (token) {
        case TOK_INT: return ATTR_int;
        case TOK_BOOL: return ATTR_bool;
        case TOK_CHAR: return ATTR_char;
        case TOK_STRING: return ATTR_string;
        case TOK_ARRAY: return ATTR_array;
        case TOK_VOID: return ATTR_void;
        case TOK_TYPEID: return ATTR_struct;
        default: return -1;
    }
}

// attributes to string
string TableManager::attrs2str(symbol *s, int skip) {
    string attrs[] = {"void", "bool", "char", "int", "null", "string",
        "struct", "array", "function", "variable", "field", "typeid",
        "param", "lval", "const", "vreg", "vaddr", "bitset_size",
        "invalid"};

    string attr_str = "";

    for (int i = 0; i < ATTR_bitset_size; i++) {
        if (i != skip and s->attributes.test(i)) {
            attr_str += attrs[i] + " ";
            if (i == ATTR_struct && s->type_name)
                attr_str += "\"" + *s->type_name + "\"" + " ";
        }
    }

    return attr_str;
}

// print a new line, helper function
void print_new_line(FILE* out) { fprintf(out, "\n"); }

symbol *TableManager::get_declared_symbol(
    attr_bitset attrs, symtable *table, astree *node, size_t block_nr) {
    if (node->symbol == TOK_VOID && !attrs.test(ATTR_function)) {
        // error: void declaration
        fprintf(stderr, "%zu:%zu:%zu: void declaration",
                node->lloc.filenr, node->lloc.linenr, node->lloc.offset);
        errors++;
        return nullptr;
    }

    astree *ident_node;  // node of identifier
    const string *type_name;

    // check array: void[] is not allowed
    // array: children[0] is type node, children[1] is identifer node
    // else: children[0] is identifier node, node is type node
    if (attrs[ATTR_array]) {
        astree *type_node = node->children[0];

        if (type_node->symbol == TOK_VOID) {
            // error: void array is not allowed
            fprintf(stderr, "%zu:%zu:%zu: void array is not allowed",
                    node->lloc.filenr, node->lloc.linenr, node->lloc.offset);
            errors++;
            return nullptr;
        }

        attrs[tok2attr(type_node->symbol)] = 1;
        ident_node = node->children[1];
        type_name = type_node->lexinfo;
    } else {
        ident_node = node->children[0];
        type_name = node->lexinfo;
    }

    symbol *symbol = symtable_search(table, ident_node);

    // check duplicate declaration
    if (symbol) {
        if (!attrs[ATTR_function]) {
            // error: duplicate declaration
            fprintf(stderr, "%zu:%zu:%zu: duplicate declaration",
                    node->lloc.filenr, node->lloc.linenr, node->lloc.offset);
            errors++;
            return nullptr;
        }
    }

    symbol = symtable_insert(table, ident_node);
    symbol->attributes = attrs;
    symbol->block_nr = block_nr;
    node->block_nr = block_nr;
    ident_node->block_nr = block_nr;

    // store struct name for printing
    if (attrs[ATTR_struct]) {
        ident_node->type_name = type_name;
        symbol->type_name = type_name;
    }

    return symbol;
}

void TableManager::process_field(symtable *table, astree *node) {
    // set field attributes
    attr_bitset attrs;
    attrs[ATTR_field] = 1;
    attrs[tok2attr(node->symbol)] = 1;

    // get the newly declared symbol
    symbol *symbol = get_declared_symbol(attrs, table, node, 0);

    // print the field to out file
    // format: foo (0.1.18) field {node} int
    // indentation: 3 spaces
    if (symbol) {
        fprintf(out, "%*s%s (%zu.%zu.%zu) field {%s} %s\n",
                (int)scope_nr * 3, "",
                symbol->node->lexinfo->c_str(),
                symbol->node->lloc.filenr,
                symbol->node->lloc.linenr,
                symbol->node->lloc.offset,
                current_struct->c_str(),
                attrs2str(symbol, ATTR_field).c_str());
    }
}

void TableManager::traverse_fields(
    symbol *symbol, astree *node, astree *type_id_node) {
    scope_nr++;

    // store the current traversing struct name
    current_struct = type_id_node->lexinfo;

    // loop through all fields
    for (size_t i = 1; i < node->children.size(); i++) {
        process_field(symbol->fields, node->children[i]);
    }

    scope_nr--;
    current_struct = nullptr;
    print_new_line(out);
}

void TableManager::traverse_struct(astree *node) {
    if (symstack->symtable_stack.size() > 1) {
        // error: struct should be global
        fprintf(stderr, "%zu:%zu:%zu: struct should be global",
                node->lloc.filenr, node->lloc.linenr, node->lloc.offset);
        errors++;
        return;
    }

    astree *type_id_node = node->children[0];
    symbol *symbol = symtable_search(type_names, type_id_node);
    if (symbol) {
        // error: duplicate symbol declaration
        fprintf(stderr, "%zu:%zu:%zu: duplicate symbol declaration",
                node->lloc.filenr, node->lloc.linenr, node->lloc.offset);
        ++errors;
        return;
    }

    // print struct declaration
    // format: node (0.1.7) {0} struct "node"
    fprintf(out, "%s (%zu.%zu.%zu) {0} struct \"%s\"\n",
            type_id_node->lexinfo->c_str(),
            node->lloc.filenr, node->lloc.linenr, node->lloc.offset,
            type_id_node->lexinfo->c_str());

    // insert the newly declared type into type names symbol table
    symbol = symtable_insert(type_names, type_id_node);
    symbol->attributes[ATTR_typeid] = 1;
    symbol->fields = new symtable;
    symbol->block_nr = 0;

    type_id_node->sym = symbol;
    type_id_node->block_nr = 0;

    // remember to print a new line at the end of traverse_fields
    traverse_fields(symbol, node, type_id_node);
}

// handle a single paramenter
symbol *TableManager::process_parameter(symtable *table, astree *node) {
    // attributes for parameter:
    // ATTR_param, ATTR_variable, ATTR_lval
    attr_bitset attrs;
    attrs[ATTR_param] = 1;
    attrs[ATTR_variable] = 1;
    attrs[ATTR_lval] = 1;
    attrs[tok2attr(node->symbol)] = 1;

    symbol *symbol = get_declared_symbol(attrs, table, node,
        symstack->block_stack.back());

    if (!symbol) return nullptr;

    // print parameter
    // format: head (0.2.15) {1} struct "node" variable lval param
    fprintf(out, "%*s%s (%zu.%zu.%zu) {%zu} %s\n",
            int(scope_nr) * 3, "",
            symbol->node->lexinfo->c_str(),
            symbol->node->lloc.filenr,
            symbol->node->lloc.linenr,
            symbol->node->lloc.offset,
            symbol->block_nr,
            attrs2str(symbol, ATTR_bitset_size).c_str());

    return symbol;
}

// traverse all paramenters
void TableManager::traverse_parameters(symbol *sym, astree *node) {
    astree *params_node = node->children[1];
    params_node->block_nr = symstack->block_stack.back();

    for (size_t i = 0; i < params_node->children.size(); i++) {
        symbol *param_symbol = process_parameter(symstack->peek(),
            params_node->children[i]);

        if (param_symbol) sym->parameters.push_back(param_symbol);
    }

    print_new_line(out);
}

void TableManager::traverse_block(astree *node) {
    astree *block_node = node->children[2];
    block_node->block_nr = symstack->block_stack.back();

    for (size_t i = 0; i < block_node->children.size(); i++) {
        traverse_ast(block_node->children[i]);
    }

    print_new_line(out);
}

void TableManager::traverse_function(astree *node) {
    if (symstack->symtable_stack.size() > 1) {
        // error: function/prototype should be global
        fprintf(stderr, "%zu:%zu:%zu: function should be global",
                node->lloc.filenr, node->lloc.linenr, node->lloc.offset);
        errors++;
        return;
    }

    astree *type_node = node->children[0];  // node of return type

    if (node->children.size() == 2) {
        astree *ident_node;

        if (type_node->symbol == TOK_ARRAY) {
            ident_node = type_node->children[1];
        } else {
            ident_node = type_node->children[0];
        }

        if (symtable_search(symstack->symtable_stack[0], ident_node))
            return;
    }

    attr_bitset attrs;
    attrs[ATTR_function] = 1;
    attrs[tok2attr(type_node->symbol)] = 1;

    symbol *symbol = get_declared_symbol(attrs,
        symstack->symtable_stack[0], type_node,
        symstack->block_stack.back());

    if (!symbol) return;

    // print function declaration
    // format: func (0.2.5) {0} struct "node" function
    fprintf(out, "%*s%s (%zu.%zu.%zu) {%zu} %s\n",
            (int)scope_nr * 3, "",
            symbol->node->lexinfo->c_str(),
            symbol->node->lloc.filenr,
            symbol->node->lloc.linenr,
            symbol->node->lloc.offset,
            symbol->block_nr,
            attrs2str(symbol, ATTR_bitset_size).c_str());

    symstack->enter_block();
    scope_nr++;
    current_function = symbol->node->lexinfo;

    traverse_parameters(symbol, node);

    if (node->symbol == TOK_FUNCTION) {
        traverse_block(node);
    }

    symstack->leave_block();
    scope_nr--;
    current_function = nullptr;
}

void TableManager::process_decl(astree *node) {
    attr_bitset attrs;
    attrs[ATTR_variable] = 1;
    attrs[ATTR_lval] = 1;
    attrs[tok2attr(node->symbol)] = 1;

    symbol *symbol = get_declared_symbol(
        attrs, symstack->peek(), node, symstack->block_stack.back());
    if (!symbol) return;

    // print variable declaration
    // format: a (0.3.7) {1} int variable lval
    fprintf(out, "%*s%s (%zu.%zu.%zu) {%zu} %s\n",
            (int)scope_nr * 3, "",
            symbol->node->lexinfo->c_str(),
            symbol->node->lloc.filenr,
            symbol->node->lloc.linenr,
            symbol->node->lloc.offset,
            symbol->block_nr,
            attrs2str(symbol, ATTR_bitset_size).c_str());
}

void TableManager::check_field(astree *node) {
    symbol *type_name = symtable_search_type_name(
        type_names, node->children[0]);
    if (!type_name) return;

    symbol *field_ident = symtable_search(
        type_name->fields, node->children[1]);
    if (!field_ident) {
        // error: no such field for typeid ___
        fprintf(stderr, "%zu:%zu:%zu: no such field",
                node->lloc.filenr, node->lloc.linenr, node->lloc.offset);
        errors++;
        return;
    }

    node->sym = field_ident;
    node->children[1]->sym = field_ident;

    node->type_name = field_ident->type_name;
    node->children[1]->type_name = field_ident->type_name;
}

void TableManager::check_array(astree *node) {
    node->attributes[ATTR_lval] = 1;
    node->attributes[ATTR_vaddr] = 1;
    node->attributes[ATTR_char] = 1;

    if (!get_attrs(node->children[0]).test(ATTR_string)) {
        if (get_attrs(node->children[0]).any()) {
            // error: wrong index type
            fprintf(stderr, "%zu:%zu:%zu: wrong index type",
                    node->lloc.filenr, node->lloc.linenr, node->lloc.offset);
            errors++;
        } else {
            node->attributes[ATTR_lval] = 1;
            node->attributes[ATTR_vaddr] = 1;
        }
    }
}

void TableManager::process_base_type(astree *node) {
    if (node->children.size() == 0) {
        attr_bitset attrs;
        attrs[ATTR_variable] = 1;
        attrs[tok2attr(node->symbol)] = 1;

        if (attrs.test(ATTR_array)) {
            astree *type_node = node->children[0];

            if (type_node->symbol == TOK_VOID) {
                // error: void array is not allowed
                fprintf(stderr,
                        "%zu:%zu:%zu: void array is not allowed",
                        node->lloc.filenr, node->lloc.linenr, node->lloc.offset);
                errors++;
                return;
            }

            attrs[tok2attr(type_node->symbol)] = 1;
        }

        if (node->symbol == TOK_TYPEID) {
            node->type_name = node->lexinfo;
        }
        node->attributes = attrs;
    } else {
        if (node->symbol == TOK_ARRAY) {
            node->attributes = get_attrs(node->children[1]);
            node->type_name = node->children[1]->type_name;
        } else {
            node->attributes = get_attrs(node->children[0]);
            node->type_name = node->children[0]->type_name;
        }
    }
}

void TableManager::check_type(astree *node) {
    switch (node->symbol) {
        case TOK_WHILE: case TOK_IF: case TOK_IFELSE:
            break;
        case TOK_RETURN: case TOK_RETURNVOID:
            break;
        case '=':
            node->type_name = node->children[1]->type_name;
            node->attributes = get_attrs(node->children[1]);
            node->attributes =
                (node->attributes & attr_prim_or_ref);
            node->attributes[ATTR_vreg] = 1;
            break;
        case TOK_EQ: case TOK_NE:
            node->attributes[ATTR_bool] = 1;
            node->attributes[ATTR_vreg] = 1;
            break;
        case '<': case '>': case TOK_LT:
        case TOK_LE: case TOK_GT: case TOK_GE:
            node->attributes[ATTR_bool] = 1;
            node->attributes[ATTR_vreg] = 1;
            break;
        case '+': case '-': case '*': case '/': case '%':
            node->attributes[ATTR_int] = 1;
            node->attributes[ATTR_vreg] = 1;
            break;
        case TOK_POS: case TOK_NEG:
            node->attributes[ATTR_int] = 1;
            node->attributes[ATTR_vreg] = 1;
            break;
        case '!':
            node->attributes[ATTR_bool] = 1;
            node->attributes[ATTR_vreg] = 1;
            break;
        case TOK_ORD:
            node->attributes[ATTR_int] = 1;
            node->attributes[ATTR_vreg] = 1;
            break;
        case TOK_CHR:
            node->attributes[ATTR_char] = 1;
            node->attributes[ATTR_vreg] = 1;
            break;
        case TOK_NEW:
            node->attributes = get_attrs(node->children[0]);
            node->attributes[ATTR_vreg] = 1;
            break;
        case TOK_NEWSTRING:
            node->attributes[ATTR_string] = 1;
            node->attributes[ATTR_vreg] = 1;
            break;
        case TOK_NEWARRAY:
            node->attributes = get_attrs(node->children[0]);
            node->attributes = (node->attributes & attr_array);
            node->attributes[ATTR_array] = 1;
            node->attributes[ATTR_vreg] = 1;
            break;
        case TOK_CALL:
            if (node->children[0]->sym) {
                node->attributes = node->children[0]->sym->attributes;
                node->attributes[ATTR_vreg] = 1;
                node->attributes.flip(ATTR_function);
                node->type_name = node->children[0]->sym->type_name;
            }
            break;
        case TOK_INDEX:
            if (!get_attrs(node->children[0]).test(ATTR_array)) {
                check_array(node);
            } else {
                node->attributes = get_attrs(node->children[0]);
                node->attributes = (node->attributes & attr_array);
                node->attributes[ATTR_vaddr] = 1;
                node->attributes[ATTR_lval] = 1;
                node->type_name = node->children[0]->type_name;
            }
            break;
        case '.':
            node->attributes =
                (get_attrs(node->children[1]) & attr_prim_or_ref);
            node->attributes[ATTR_lval] = 1;
            node->attributes[ATTR_vaddr] = 1;
            node->type_name = node->children[1]->type_name;
            break;
        case TOK_VARDECL:
            break;
        case TOK_INTCON:
            node->attributes[ATTR_int] = 1;
            node->attributes[ATTR_const] = 1;
            break;
        case TOK_CHARCON:
            node->attributes[ATTR_char] = 1;
            node->attributes[ATTR_const] = 1;
            break;
        case TOK_STRINGCON:
            node->attributes[ATTR_string] = 1;
            node->attributes[ATTR_const] = 1;
            break;
        case TOK_FALSE: case TOK_TRUE:
            node->attributes[ATTR_bool] = 1;
            node->attributes[ATTR_const] = 1;
            break;
        case TOK_NULL:
            node->attributes[ATTR_null] = 1;
            node->attributes[ATTR_const] = 1;
            break;
        case TOK_VOID:
            // error: void declaration
            fprintf(stderr, "%zu:%zu:%zu: void declaration",
                    node->lloc.filenr, node->lloc.linenr, node->lloc.offset);
            errors++;
            break;
        case TOK_BOOL: case TOK_CHAR: case TOK_INT:
        case TOK_STRING: case TOK_TYPEID: case TOK_ARRAY:
            process_base_type(node);
            break;
    }
}

void TableManager::process_node(astree *node) {
    if (node->symbol == TOK_IDENT) {
        symbol *symbol = symstack->search_ident(node);

        if (!symbol) {
            // error: undefined identifier
            fprintf(stderr, "%zu:%zu:%zu: undefined identifier",
                    node->lloc.filenr, node->lloc.linenr, node->lloc.offset);
            errors++;
        } else {
            node->sym = symbol;
            node->type_name = symbol->type_name;
        }
    } else {
        check_type(node);
    }
}

// use as a recursion helper
void TableManager::traverse_next(astree *node) {
    printf("In traverse_next\n");
    if (node->symbol == TOK_BLOCK) {
        scope_nr++;
        symstack->enter_block();
    }
    printf("node childrens size : %lu \n", node->children.size());
    for (size_t i = 0; i < node->children.size(); i++) {
        traverse_ast(node->children[i]);
    }
}

void TableManager::end_block(astree *node) {
    int symbol = node->symbol;

    if (symbol != TOK_VOID && symbol != TOK_FUNCTION &&
        symbol != TOK_STRUCT && symbol != TOK_PROTOTYPE) {
        process_node(node);
        node->block_nr = symstack->block_stack.back();

        if (symbol == TOK_BLOCK) {
            scope_nr--;
            symstack->leave_block();
        }
    }
}

void TableManager::traverse_ast(astree *node) {
    printf("%d\n", node->symbol);
    switch (node->symbol) {
        case TOK_STRUCT:
            traverse_struct(node);
            break;
        case TOK_FUNCTION: case TOK_PROTOTYPE:
            traverse_function(node);
            break;
        case TOK_VOID:
            // error: void variable
            fprintf(stderr, "%zu:%zu:%zu: void variable",
                    node->lloc.filenr, node->lloc.linenr, node->lloc.offset);
            errors++;
            break;
        case TOK_BOOL: case TOK_CHAR: case TOK_INT: case TOK_STRING:
        case TOK_TYPEID: case TOK_ARRAY:
            process_decl(node);
            break;
        case '.':
            traverse_ast(node->children[0]);
            traverse_ast(node->children[1]);
            check_field(node);
            break;
        case TOK_NEW:
            process_node(node->children[0]);
            process_node(node);
            break;
        case TOK_NEWARRAY:
            traverse_ast(node->children[1]);
            process_node(node->children[0]);
            break;
        case TOK_NEWSTRING:
            traverse_ast(node->children[0]);
            break;
        default:
            traverse_next(node);
            break;
    }

    end_block(node);
}

void TableManager::print_symtables() {
    symstack = new Symstack();
    type_names = new symtable;
    traverse_ast(root);
}
