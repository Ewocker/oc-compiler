
#include <assert.h>
#include <iostream>
#include <stdio.h>
#include <vector>

#include "auxlib.h"
#include "lyutils.h"
#include "symtable.h"
#include "astree.h"
#include "emitter.h"

using namespace std;

size_t reg_nr = 1;  // register number
size_t strcon_nr = 1;
vector<string> queue_stringcon;

FILE *out;

void emit(astree*);

// get child string
string emit_code(astree* tree, size_t child) {
    return *tree->children[child]->emit_code;
}

// get lexinfo
string lexinfo(astree* tree) {
    return *tree->lexinfo;
}

// get TYPEID
string typeid_field(astree* tree) {
    return *tree->sym->node->parent->parent->children[0]->lexinfo;
}

string block_nr(astree* tree) {
    return to_string(tree->sym->block_nr);
}

string register_nr(astree* tree) {
    return to_string(tree->register_nr);
}

string reg_string(string type, astree* tree) {
    return type + register_nr(tree);
}

// record register number
void register_nr_record(astree* tree) {
    tree->register_nr = reg_nr;
    reg_nr += 1;
}

// add STRINGCON AST nodes into the 'queue_stringcon' queue
void emit_stringcon(astree* tree) {
    tree->emit_code = new string("s" + to_string(strcon_nr));
    strcon_nr += 1;
    queue_stringcon.push_back(lexinfo(tree));
}

// while and break use the serial number of while token
void emit_while(astree* tree) {
    fprintf(out, "while_%lu_%lu_%lu:;\n", tree->lloc.linenr, tree->lloc.offset,
        tree->lloc.offset);
    emit(tree->children[0]);

    fprintf(out, "%*sif (!%s) goto break_%lu_%lu_%lu;\n", 8, "",
        emit_code(tree, 0).c_str(), tree->lloc.linenr, tree->lloc.offset,
        tree->lloc.offset);

    emit(tree->children[1]);

    fprintf(out, "%*sgoto while_%lu_%lu_%lu;\n", 8, "",
        tree->lloc.linenr, tree->lloc.offset, tree->lloc.offset);

    fprintf(out, "break_%lu_%lu_%lu:;\n", tree->lloc.linenr, tree->lloc.offset,
        tree->lloc.offset);
}

// if else statement
void emit_ifelse(astree* tree) {
    emit(tree->children[0]);

    fprintf(out, "%*sif (!%s) goto else_%lu_%lu_%lu;\n", 8, "",
        emit_code(tree, 0).c_str(), tree->lloc.linenr, tree->lloc.offset,
        tree->lloc.offset);
    emit(tree->children[1]);

    fprintf(out, "%*sgoto fi_%lu_%lu_%lu;\n", 8, "", tree->lloc.linenr,
        tree->lloc.offset, tree->lloc.offset);

    fprintf(out, "else_%lu_%lu_%lu:;\n", tree->lloc.linenr, tree->lloc.offset,
        tree->lloc.offset);
    emit(tree->children[2]);

    fprintf(out, "fi_%lu_%lu_%lu:;\n", tree->lloc.linenr, tree->lloc.offset,
        tree->lloc.offset);
}

// if without else
void emit_if(astree* tree) {
    emit(tree->children[0]);

    fprintf(out, "%*sif (!%s) goto fi_%lu_%lu_%lu;\n", 8, "",
        emit_code(tree, 0).c_str(), tree->lloc.linenr, tree->lloc.offset,
        tree->lloc.offset);
    emit(tree->children[1]);

    fprintf(out, "fi_%lu_%lu_%lu:;\n", tree->lloc.linenr, tree->lloc.offset,
        tree->lloc.offset);
}

// TYPEID IDENT
void emit_typeid(astree* tree) {
    string base = "struct s_" + lexinfo(tree) + "*";
    if (!tree->children.size()) {
        tree->emit_code = new string(base);
    } else {
        tree->emit_code = new string(base + " " + emit_code(tree, 0));
    }
}

// string IDENT
void emit_string(astree* tree) {
    if (!tree->children.size()) {
        tree->emit_code = new string("char*");
    } else {
        tree->emit_code = new string("char* " + emit_code(tree, 0));
    }
}

// bool IDENT
void emit_bool(astree* tree) {
    if (!tree->children.size()) {
        tree->emit_code = new string("char");
    } else {
        tree->emit_code = new string("char "  +
            emit_code(tree, 0));
    }
}

// void IDENT
void emit_void(astree* tree) {
    if (!tree->children.size()) {
        tree->emit_code = tree->lexinfo;
    } else {
        tree->emit_code = new string(lexinfo(tree) + " " +
            emit_code(tree, 0));
    }
}

// field
void emit_field(astree* tree) {
    tree->emit_code = new string("f_" + typeid_field(tree) + "_" +
        lexinfo(tree));
}

// char IDENT
void emit_char(astree* tree) {
    if (!tree->children.size()) {
        tree->emit_code = tree->lexinfo;
    } else {
        tree->emit_code = new string(lexinfo(tree) + " " +
            emit_code(tree, 0));
    }
}

// CHARCON
void emit_charcon(astree* tree) {
    tree->emit_code = tree->lexinfo;
}

// int IDENT
void emit_int(astree* tree) {
    if (!tree->children.size()) {
        tree->emit_code = tree->lexinfo;
    } else {
        tree->emit_code = new string(lexinfo(tree) + " " +
            emit_code(tree, 0));
    }
}

// delete leading zeros
string* lead_zeros_delete(const string* input) {
    string tempstring = *input;
    if (tempstring.size() == 0) {
        return new string("");
    }
    while (tempstring.size() > 0 && tempstring.at(0) == '0') {
        tempstring.erase(0,1);
    }
    if (tempstring.size() == 0) {
        return new string("0");
    } else {
        return new string(tempstring);
    }
}

// INTCON
void emit_intcon(astree* tree) {
    tree->emit_code = lead_zeros_delete(tree->lexinfo);
}

// false
void emit_false(astree* tree) {
    tree->emit_code = new string("0");
}

// null
void emit_null(astree* tree) {
    tree->emit_code = new string("0");
}

// true
void emit_true(astree* tree) {
    tree->emit_code = new string("1");
}

// return not void
void emit_return(astree* tree) {
    fprintf(out, "%*sreturn %s;\n", 8, "", emit_code(tree, 0).c_str());
}

// return void
void emit_returnvoid() {
    fprintf(out, "%*sreturn;\n", 8, "");
}

void emit_assign(astree *tree) {
    tree->emit_code = tree->children[0]->emit_code;

    fprintf(out, "%*s%s = %s;\n", 8, "", emit_code(tree, 0).c_str(),
        emit_code(tree, 1).c_str());
}

// array
void emit_array(astree* tree) {
    tree->emit_code = new string(emit_code(tree, 0) + "* " +
        emit_code(tree, 1));
}

// new
void emit_new(astree* tree) {
    register_nr_record(tree);
    tree->emit_code = new string("p" + register_nr(tree));

    fprintf(out,
        "%*sstruct s_%s* %s = xcalloc (1, sizeof (struct s_%s));\n",
        8, "", tree->children[0]->type_name->c_str(),
        tree->emit_code->c_str(),
        tree->children[0]->type_name->c_str());
}

// new string
void emit_newstring(astree* tree) {
    register_nr_record(tree);
    tree->emit_code = new string("p" + register_nr(tree));

    fprintf(out, "%*schar* %s = xcalloc (%s, sizeof (char));\n", 8, "",
        tree->emit_code->c_str(), emit_code(tree, 0).c_str());
}

// get the node's type return string
string get_type_name(astree* tree) {
    attr_bitset attr = get_attrs(tree);
    string return_str = "";

    if (attr.test(ATTR_bool)) {
        return_str += "char";
    } else if (attr.test(ATTR_int)) {
        return_str += "int";
    } else if (attr.test(ATTR_string)) {
        return_str += "char*";
    } else if (attr.test(ATTR_char)) {
        return_str += "char";
    } else if (attr.test(ATTR_struct)) {
        return_str += "struct";
    }

    if (attr.test(ATTR_struct)) {
        return_str += (string(" ") + string("s_") + *tree->type_name +
            string("*"));
    }

    if (tree->symbol == '.') {
        return_str += "*";
    }

    if (attr.test(ATTR_array)) {
        return_str += "*";
    }

    return return_str;
}

// new array
void emit_newarray(astree* tree) {
    register_nr_record(tree);
    string type_string = get_type_name(tree->children[0]);
    tree->emit_code = new string("p" + register_nr(tree));

    fprintf(out, "%*s%s* %s = xcalloc (%s, sizeof (%s));\n", 8, "",
        type_string.c_str(), tree->emit_code->c_str(),
        emit_code(tree, 1).c_str(), type_string.c_str());
}

// IDENT
void emit_ident(astree* tree) {
    if (!tree->sym->block_nr) {
        tree->emit_code = new string("__" + lexinfo(tree));
    } else {
        tree->emit_code = new string("_" + block_nr(tree) + "_" +
            lexinfo(tree));
    }
}

// DECLID
void emit_declid(astree* tree) {
    if (!tree->block_nr) {
        tree->emit_code = new string("__" + lexinfo(tree));
    } else {
        tree->emit_code = new string("_" + block_nr(tree) + "_" +
            lexinfo(tree));
    }
}

// array index
void emit_index(astree* tree) {
    register_nr_record(tree);
    string type_string = get_type_name(tree);
    tree->emit_code = new string("(*a" + register_nr(tree) + ")");

    fprintf(out, "%*s%s* %s = &%s[%s];\n", 8, "", type_string.c_str(),
        reg_string("a", tree).c_str(), emit_code(tree, 0).c_str(),
        emit_code(tree, 1).c_str());
}

// address operator
void emit_selector(astree* tree) {
    register_nr_record(tree);
    string type_string = get_type_name(tree);
    tree->emit_code = new string("(*a" + register_nr(tree) + ")");

    fprintf(out, "%*s%s %s = &%s->%s;\n", 8, "", type_string.c_str(),
        reg_string("a", tree).c_str(), emit_code(tree, 0).c_str(),
        emit_code(tree, 1).c_str());
}

// function call
void emit_call(astree* tree) {
    attr_bitset attrs = get_attrs(tree);

    // non void function
    if (!attrs.test(ATTR_void)) {
        register_nr_record(tree);
        string type_string = get_type_name(tree);
        string reg_type;

        if (attrs.test(ATTR_bool)) {
            reg_type = "b";
        } else if (attrs.test(ATTR_char)) {
            reg_type = "c";
        } else if (attrs.test(ATTR_int)) {
            reg_type = "i";
        } else if (type_string.find('*')) {
            reg_type = "p";
        }

        tree->emit_code = new string(reg_type + register_nr(tree));

        fprintf(out, "%*s%s %s = ", 8, "",
            type_string.c_str(), tree->emit_code->c_str());
    } else {
        fprintf(out, "%*s", 8, "");
    }

    fprintf(out, "__%s (", lexinfo(tree->children[0]).c_str());

    for (size_t i = 1; i < tree->children.size(); i++) {
        fprintf(out, "%s", emit_code(tree, i).c_str());
        if (i != tree->children.size() - 1) {
            fprintf(out, ", ");
        }
    }

    fprintf(out, ");\n");
}

// global variable declarations
void emit_global_vardecl(astree* tree) {
    if (tree->symbol == TOK_ARRAY) {
        fprintf(out, "%*s%s", 8, "", emit_code(tree, 1).c_str());
    } else {
        fprintf(out, "%*s%s", 8, "", emit_code(tree, 0).c_str());
    }
}

// variable declarations
void emit_vardecl(astree* tree) {
    if (tree->parent->symbol == TOK_ROOT) {
        emit_global_vardecl(tree->children[0]);
    } else {
        fprintf(out, "%*s%s", 8, "", emit_code(tree, 0).c_str());
    }

    fprintf(out, " = %s;\n", emit_code(tree, 1).c_str());
}

// binary operators
void emit_binop(astree* tree) {
    string type_string = get_type_name(tree);

    fprintf(out, "%*s%s %s = %s %s %s;\n", 8, "", type_string.c_str(),
        tree->emit_code->c_str(), emit_code(tree, 0).c_str(),
        lexinfo(tree).c_str(), emit_code(tree, 1).c_str());
}

// emitting expression 3.3 for binary operator
void emit_binop_expression_i(astree* tree) {
    register_nr_record(tree);
    tree->emit_code = new string("i" + register_nr(tree));
    emit_binop(tree);
}

// plus, minus, multiply, divide, and mod
void emit_plus(astree* tree) {
    emit_binop_expression_i(tree);
}

void emit_minus(astree* tree) {
    emit_binop_expression_i(tree);
}

void emit_multiply(astree* tree) {
    emit_binop_expression_i(tree);
}

void emit_divide(astree* tree) {
   emit_binop_expression_i(tree);
}

void emit_mod(astree* tree) {
   emit_binop_expression_i(tree);
}

// emitting expression 3.3 for binary operator
void emit_binop_expression_b(astree* tree) {
    register_nr_record(tree);
    tree->emit_code = new string("b" + register_nr(tree));
    emit_binop(tree);
}

// equal, ne, lt, le, gt, ge
void emit_eq(astree* tree) {
    emit_binop_expression_b(tree);
}

void emit_ne(astree* tree) {
    emit_binop_expression_b(tree);
}

void emit_lt(astree* tree) {
    emit_binop_expression_b(tree);
}

void emit_le(astree* tree) {
    emit_binop_expression_b(tree);
}

void emit_gt(astree* tree) {
    emit_binop_expression_b(tree);
}

void emit_ge(astree* tree) {
    emit_binop_expression_b(tree);
}

// unary operators
void emit_unop(astree* tree, string unary_str) {
    string type_string = get_type_name(tree);

    fprintf(out, "%*s%s %s = %s%s;\n", 8, "", type_string.c_str(),
        tree->emit_code->c_str(), unary_str.c_str(),
        emit_code(tree, 0).c_str());
}

// positive, negative
void emit_pos(astree* tree) {
    register_nr_record(tree);
    tree->emit_code = new string("i" + register_nr(tree));
    emit_unop(tree, lexinfo(tree));
}

void emit_neg(astree* tree) {
    register_nr_record(tree);
    tree->emit_code = new string("i" + register_nr(tree));
    emit_unop(tree, lexinfo(tree));
}

void emit_exclaim(astree* tree) {
    register_nr_record(tree);
    tree->emit_code = new string("b" + register_nr(tree));
    emit_unop(tree, lexinfo(tree));
}

void emit_ord(astree* tree) {
    register_nr_record(tree);
    tree->emit_code = new string("i" + register_nr(tree));
    emit_unop(tree, "(int)");
}

void emit_chr(astree* tree) {
    register_nr_record(tree);
    tree->emit_code = new string("c" + register_nr(tree));
    emit_unop(tree, "(char)");
}

// check if the symbol is already found in the tree
bool emit_found(astree* node) {
    switch(node->symbol) {
        case TOK_PROTOTYPE: case TOK_FUNCTION:
        case TOK_STRUCT: case TOK_STRINGCON:
            return true;
        default:
            return false;
    }
}

bool post_skip(astree* node) {
    switch (node->symbol) {
        case TOK_IF:
            emit_if(node);
            return true;
        case TOK_IFELSE:
            emit_ifelse(node);
            return true;
        case TOK_WHILE:
            emit_while(node);
            return true;
        default:
            return false;
    }
}

// emit recursively
void emit(astree *tree) {
    if (!tree || post_skip(tree) || emit_found(tree)) return;


    // post-order traversal
    for (size_t i = 0; i < tree->children.size(); i++) {
        emit(tree->children[i]);
    }

    // cout << "Before switch " << *(tree->lexinfo) << endl;

    switch (tree->symbol) {
        case TOK_VARDECL:
            emit_vardecl(tree);
            break;
        case '=':
            emit_assign(tree);
            break;
        case TOK_CALL:
            emit_call(tree);
            break;
        // binops
        case '+':
            emit_plus(tree);
            break;
        case '-':
            emit_minus(tree);
            break;
        case '*':
            emit_multiply(tree);
            break;
        case '/':
            emit_divide(tree);
            break;
        case '%':
            emit_mod(tree);
            break;
        case TOK_EQ:
            emit_eq(tree);
            break;
        case TOK_NE:
            emit_ne(tree);
            break;
        case '<': case TOK_LT:
            emit_lt(tree);
            break;
        case TOK_LE:
            emit_le(tree);
            break;
        case '>': case TOK_GT:
            emit_gt(tree);
            break;
        case TOK_GE:
            emit_ge(tree);
            break;
        // unops
        case TOK_POS:
            emit_pos(tree);
            break;
        case TOK_NEG:
            emit_neg(tree);
            break;
        case '!':
            emit_exclaim(tree);
            break;
        case TOK_ORD:
            emit_ord(tree);
            break;
        case TOK_CHR:
            emit_chr(tree);
            break;
        case TOK_INDEX:
            emit_index(tree);
            break;
        case TOK_NEW:
            emit_new(tree);
            break;
        case TOK_ARRAY:
            emit_array(tree);
            break;
        case TOK_NEWARRAY:
            emit_newarray(tree);
            break;
        case TOK_NEWSTRING:
            emit_newstring(tree);
            break;
        case TOK_DECLID:
            emit_declid(tree);
            break;
        case TOK_FIELD:
            emit_field(tree);
            break;
        case '.':
            emit_selector(tree);
            break;
        // operand
        case TOK_IDENT:
            emit_ident(tree);
            break;
        case TOK_INTCON:
            emit_intcon(tree);
            break;
        case TOK_CHARCON:
            emit_charcon(tree);
            break;
        // type
        case TOK_VOID:
            emit_void(tree);
            break;
        case TOK_TYPEID:
            emit_typeid(tree);
            break;
        case TOK_TRUE:  // don't forget this case!
            emit_true(tree);
            break;
        case TOK_NULL:
            emit_null(tree);
            break;
        case TOK_FALSE:
            emit_false(tree);
            break;
        case TOK_RETURN:
            emit_return(tree);
            break;
        case TOK_RETURNVOID:
            emit_returnvoid();
            break;
        // type declarations
        case TOK_BOOL:
            emit_bool(tree);
            break;
        case TOK_CHAR:
            emit_char(tree);
            break;
        case TOK_INT:
            emit_int(tree);
            break;
        case TOK_STRING:
            emit_string(tree);
            break;
        default:
            // do nothing for default
            break;
    }

    // cout << "After switch: " << *(tree->lexinfo) << endl;
}

void emit_fielddef(astree* node) {
    emit(node);
    fprintf(out, "%*s%s\n", 8, "", node->emit_code->c_str());
}

// structdefs
void emit_structdef(astree* tree) {
    for (size_t i = 0; i < tree->children.size(); i++) {
        astree* node = tree->children[i];

        if (node->symbol == TOK_STRUCT) {
            const char* ident = node->children[0]->lexinfo->c_str();

            fprintf(out, "struct s_%s {\n", ident);

            for (size_t j = 1; j < node->children.size(); j++) {
                emit_fielddef(node->children[j]);
            }

            fprintf(out, "};\n");
        }
    }
}

// stringdefs
void emit_stringdef() {
    for (size_t i = 1; i <= queue_stringcon.size(); i++) {
        fprintf(out, "char* s%lu = %s;\n", i,
            queue_stringcon[i-1].c_str());
    }
}

// global identifiers
void emit_global_idents(astree* node) {
    for (size_t i = 0; i < node->children.size(); i++) {
        astree* ident_node = node->children[i];

        if (ident_node->symbol == TOK_VARDECL) {
            emit(ident_node->children[0]);
            fprintf(out, "%s;\n", emit_code(ident_node, 0).c_str());
        }
    }
}

// '{'[statement]'}' | ';'
void emit_function_body(astree* body_node) {
    fprintf(out, "{\n");
    emit(body_node);
    fprintf(out, "}\n");
}

// parameters
void emit_params(astree* params) {
    fprintf(out, " (");

    if (!params->children.size()) {
        fprintf(out, "void");
    } else {
        fprintf(out, "\n");

        for (size_t i = 0; i <params->children.size(); i++) {
            astree *param = params->children[i];
            emit(param);
            fprintf(out, "%*s%s", 8, "", param->emit_code->c_str());

            if ( i != params->children.size() - 1) {
                fprintf(out, ",\n");
            }
        }
    }
    fprintf(out, ")\n");
}

// emit function name
void emit_function_name(astree* name_node) {
    emit(name_node);

    fprintf(out, "%s", name_node->emit_code->c_str());
}

// function
void emit_functions(astree* node) {
    for (size_t i = 0; i < node->children.size(); i++) {
        astree* function_node = node->children[i];

        if (function_node->symbol == TOK_FUNCTION) {
            emit_function_name(function_node->children[0]);
            emit_params(function_node->children[1]);
            emit_function_body(function_node->children[2]);
        }
    }
}

// emit the program
// a program is divided into four parts
void emit_program(astree *node) {
    //struct def
    emit_structdef(node);

    // string def
    emit_stringdef();

    // golbal identifiers
    emit_global_idents(node);

    // functions
    emit_functions(node);
}

// emit main function
void emit_main_function(astree* tree) {
    fprintf(out, "void __ocmain (void)\n{\n");
    emit(tree);
    fprintf(out, "}\n");
}

// include oclib header file
void emit_header() {
    fprintf(out, "#define __OCLIB_C__\n");
    fprintf(out, "#include \"oclib.oh\"\n");
}

void emit_everything (FILE *oil_file, astree *root, unsigned error_nr) {
    out = oil_file;

    emit_header();

    // if there are some error(s), emit nothing instead of everything
    if (!error_nr) {
        // emit program first
        // at last, emit main function
        emit_program(root);
        emit_main_function(root);
     } else {
         fprintf(out, "void __ocmain (void)\n{\n");
         fprintf(out, "}\n");
     }
}
