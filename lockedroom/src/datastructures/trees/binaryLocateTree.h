#ifndef binaryLocateTree_h
#define binaryLocateTree_h

#include "../dist/node.h"

// MARK: DATA TYPES

struct binaryLocateTree {
	struct Node *head;
	int (*compare)(void *data_one, void *data_two);
	void * (*search)(struct binaryLocateTree *tree, void *data);
	void (*insert)(struct binaryLocateTree* tree, void* data, int size);
};

// MARK: CONSTRUCTORS

struct binaryLocateTree binaryLocateTree_constructor(int (*compare)(void* data_one, void* data_two));
void binaryLocateTree_destructor(struct binaryLocateTree* tree);

// MARK: PUBLIC FUNCTIONS

int binaryLocateTree_int_compare(void *data_one, void *data_two);
int binaryLocateTree_float_compare(void *data_one, void *data_two);
int binaryLocateTree_char_compare(void *data_one, void *data_two);
int binaryLocateTree_str_compare(void *data_one, void *data_two);



#endif /* binaryLocateTree_h */