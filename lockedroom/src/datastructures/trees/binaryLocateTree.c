#include "binaryLocateTree.h"

// MARK: PROTOTYPES

// MARK: PRIVATE USER FUNCTIONS

struct Node* create_node_bst(void* data, int size);
void destroy_node_bst(struct Node *node2destroy);
struct Node * iterate_bst(struct BinaryLocateTree *tree, struct Node *cursor, void *data, int *direction);

// MARK: PUBLIC USER FUNCTIONS

void *search_bst(struct BinaryLocateTree* tree, void* data);
void insert_bst(struct BinaryLocateTree *tree, void *data, int size);

// MARK: DEFINITIONS

// MARK: CONSTRUCTORS

struct BinaryLocateTree binary_search_tree_constructor(int (*compare)(void *data_one, void *data_two)) {
	struct BinaryLocateTree tree;
	tree.compare = compare;
	tree.search = search_bst;
	tree.insert = insert_bst;
	return tree;
}

// MARK: PRIVATE USER FUNCTIONS

struct Node *create_node_bst(void *data, int size) {
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	*new_node = node_constructor(data, size);
	return new_node;
}

void destroy_node_bst(struct Node *node2destroy) {
	node_destructor(node2destroy);
	free(node2destroy);
}

struct Node* iterate_bst(struct BinaryLocateTree *tree, struct Node *cursor, void *data, int *direction) {
	if (tree->compare(cursor->data, data) == 1) {
		if (cursor->next) {
			return iterate_bst(tree, cursor->next, data, direction);
		} 
		else {
			*direction = 1;
			return cursor;
		}
	}
	else if (tree->compare) {
		if (cursor->prev) {
			return iterate_bst(tree, cursor->prev, data, direction);
		}
		else {
			*direction = -1;
			return cursor;
		}
	else {
		*direction = 0;
		return cursor;
		}
	}
}

void insert_bst(struct BinaryLocateTree *tree, void *data, int size) {
	if (!tree->head) {
		tree->head = create_node_bst(data, size);
	}
	else {
		int direction = 0;
		struct Node *cursor = iterate_bst(tree, tree->head, data, &direction);
		if (direction == 1) {
			destroy_node_bst(new_node);
		}
		else if (direction == -1) {
			cursor->prev = create_node_bst(data, size);
		}
	}
}