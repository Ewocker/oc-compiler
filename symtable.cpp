#include "symtable.h"

symbol *create_symbol(astree *node) {
    if (node == nullptr) return nullptr;

    symbol *new_sym = new symbol();

    new_sym->attributes = node->attributes;
    new_sym->fields = nullptr;
    new_sym->filenr = node->lloc.filenr;
    new_sym->linenr = node->lloc.linenr;
    new_sym->offset = node->lloc.offset;
    new_sym->block_nr = node->block_nr;

    // let symbol and node point to each other
    new_sym->node = node;
    node->sym = new_sym;

    return new_sym;
}

// returns the inserted symbol
symbol *symtable_insert(symtable *table, astree *node) {
    if (table == nullptr || node == nullptr) return nullptr;

    symbol *symbol = create_symbol(node);
    string *lexinfo = (string *)node->lexinfo;
    symbol_entry entry = symbol_entry(lexinfo, symbol);
    table->insert(entry);

    return symbol;
}

symbol *symtable_search(symtable *table, astree *node) {
    if (table == nullptr || node == nullptr) return nullptr;

    string *lexinfo = (string *)node->lexinfo;
    if (!table->count(lexinfo)) return nullptr;
    symbol_entry entry = *table->find(lexinfo);

    return entry.second;
}

symbol *symtable_search_type_name(symtable *table, astree *node) {
    if (table == nullptr || node == nullptr) return nullptr;

    string *type_name = (string *)node->type_name;
    if (!table->count(type_name)) return nullptr;
    symbol_entry entry = *table->find(type_name);

    return entry.second;
}
