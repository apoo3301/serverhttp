#ifndef Dictionary_h
#define Dictionary_h

#include "../trees/binaryLocateTree.h"
#include "entry.h"

struct Dictionary {
	struct binaryLocateTree binary_search_tree;
	void (*insert)(struct Dictionary *dictionary, void *key, int *key_size, void *value, int value_size);
	void* (*search)(struct Dictionary* dictionary, void* key, int key_size);
};

struct Dictionary dictionary_constructor(int (*compare)(void *entry_one, void *entry_two));
struct Dictionary dictionary_destructor(struct Dictionary *dictionary);

int compare_string_keys(void *entry_one, void *entry_two);