#ifndef _STRUCT_H_
#define _STRUCT_H_

#define MAX_SIZE_STRING 100

typedef struct Person {
	char *name;
	unsigned int age;
	unsigned int height;
	unsigned int year_of_birth;
	char *occupation;
} Person;

typedef struct Node {
	int key;
	Person *person;
	struct Node *left;
	struct Node *right;

} Node;

typedef struct BinaryTree {
	Node *root;
} BinaryTree;

enum MainOptionsEnum {
	MAIN_EXIT = 0,
	MAIN_PRINT_TREE = 1,
	MAIN_PRINT_LEAVES = 2,
	MAIN_SEARCH_NODE = 3,
	MAIN_HEIGHT_OF_TREE = 4,
	MAIN_DEPTH_OF_NODE = 5,
	MAIN_HEIGHT_OF_NODE = 6,

};

enum TypeCrossingTreeEnum {
	SVD = 1,
	SDV = 2,
	VSD = 3,
};

typedef union OptionsType {
	enum TypeCrossingTreeEnum type_crossing_tree_enum;
	enum MainOptionsEnum main_option;
} OptionsType;

typedef struct ListOption {
	char *label;
	OptionsType type;
} ListOption;

typedef struct ListOptionsStruct {
	ListOption *list_options;
	int length;
} ListOptionsStruct;

typedef void (*ExecutionNode)(Node *);

typedef void (*TreeIterator)(Node *, ExecutionNode);

#endif //_STRUCT_H_
