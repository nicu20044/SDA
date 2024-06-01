#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#include "funcs.h"

Node *create_node(Person *person) {
	Node *tree_node = calloc(sizeof(Node), 1);
	tree_node->person = person;
	return tree_node;
}

void delete_tree_node(Node *tree_node) {
	if (tree_node) {
		free(tree_node);
	}
}

BinaryTree *create_tree() {
	BinaryTree *local = calloc(sizeof(BinaryTree *), 1);
	return local;
}

void delete_all_tree_nodes_from_node(Node *current) {
	if (current) {
		delete_all_tree_nodes_from_node(current->left);
		delete_all_tree_nodes_from_node(current->right);
		delete_tree_node(current);
	}
}

void clear_tree(BinaryTree *tree) {
	assert(tree);

	if (tree->root) {
		delete_all_tree_nodes_from_node(tree->root);
		tree->root = NULL;
	}
}

void delete_tree(BinaryTree *tree) {
	assert(tree);

	clear_tree(tree);
	free(tree);
}

void insert_node(Node *current, Node *new_node) {
	assert(current);


	if (current->key > new_node->key) {
		if (current->left) {
			insert_node(current->left, new_node);
		} else {
            current->left = new_node;
		}
	} else {
		if (current->right) {
			insert_node(current->right, new_node);
		} else {
            current->right = new_node;
		}
	}

}

void insert_node_in_tree(BinaryTree *tree, Node *node) {
	if (!tree) {
		return;
	}

	if (tree->root) {
		insert_node(tree->root, node);
	} else {
		tree->root = node;
	}

}

void print_node(const Node *node) {
	printf("%d ", node->key);
	print_person(node->person);
}

void print_tree_node(Node *node) {
	assert(node);
	print_node(node);
}

void print_tree(BinaryTree *tree, TreeIterator tree_iterator) {
	assert(tree);
	assert(tree_iterator);

	if (tree->root) {
		printf("\n Tree elements:\n");
		tree_iterator(tree->root, print_tree_node);
	} else {
		printf("Tree has no nodes");
	}
}

void SDV_initiator(Node *current, ExecutionNode execution_node) {
	if (current) {
		SDV_initiator(current->left, execution_node);
		SDV_initiator(current->right, execution_node);
		execution_node(current);
	}
}

void SVD_initiator(Node *current, ExecutionNode execution_node) {
	if (current) {
		SVD_initiator(current->left, execution_node);
		execution_node(current);
		SVD_initiator(current->right, execution_node);
	}
}

void VSD_initiator(Node *current, ExecutionNode execution_node) {
	if (current) {
		execution_node(current);
		VSD_initiator(current->left, execution_node);
		VSD_initiator(current->right, execution_node);
	}
}

Node *DFS_helper(Node *current, int key) {
	if (!current) {
		return NULL;
	}

	if (current->key == key) {
		return current;
	}

	Node *tmp = DFS_helper(current->left, key);
	return tmp ? tmp : DFS_helper(current->right, key);
}

Node *DFS(BinaryTree *tree, int key) {
	if (!tree) {
		return NULL;
	}
	if (!tree->root) {
		return NULL;
	}

	return DFS_helper(tree->root, key);
}

ListOptionsStruct *create_struct_of_options(ListOption *list_options, int length) {
	assert(list_options);
	assert(length);

	ListOptionsStruct *list_options_array = calloc(1, sizeof(ListOptionsStruct));
	list_options_array->list_options = list_options;
	list_options_array->length = length;
	return list_options_array;
}

Person *create_person() {
	Person *person = calloc(1, sizeof(Person));
	person->name = calloc(MAX_SIZE_STRING, sizeof(char));
	person->occupation = calloc(MAX_SIZE_STRING, sizeof(char));
	return person;
}

void *_read_person_form_file(FILE *file) {
	assert(file);

	Person *person = create_person();

	fscanf(file, "%10s %u %u %u %10s",
	       person->name,
	       &(person->age),
	       &(person->height),
	       &(person->year_of_birth),
	       person->occupation);

	return person;
}

void free_person(Person *person) {
	assert(person);

	free(person->name);
	free(person->occupation);
	free(person);
}

void free_node(Node *node) {
	assert(node);

	free_person(node->person);
	free(node);
}

void print_person(const Person *person) {
	assert(person);

	printf("%s | %d | %d | %hu | %s\n",
	       person->name, person->age, person->height, person->year_of_birth, person->occupation);
}

void import_data_from_file_in_binary_tree(const char *file, BinaryTree *binary_tree) {
	assert(file);
	assert(binary_tree);

	FILE *file_ptr = fopen(file, "r");

	assert(file_ptr);

	srand(time(NULL));

	int key;


	while (!feof(file_ptr)) {
		key = rand() % 100;
		printf("key: %d\n", key);
		Person *person = _read_person_form_file(file_ptr);
		Node *new_node = create_node(person);
		new_node->key = key;
		insert_node_in_tree(binary_tree, new_node);

	}
	fclose(file_ptr);
}

void read_position(int *position) {
	assert(position);
	printf("Input position: ");
	scanf("%d", position);
}

int read_option() {
	int option;
	printf("Choose option: ");
	scanf("%d", &option);
	return option;
}

void print_options(const ListOptionsStruct *options) {
	assert(options);

	for (int i = 0; i < options->length; ++i) {
		printf("%d %s\n", ((options->list_options) + i)->type, ((options->list_options) + i)->label);
	}
}

int get_depth_of_node_in_tree_by_key_helper(Node *node, int target_key) {
	if (node == NULL)
		return -1;

	int depth = -1;

	if (node->key == target_key) {
		return depth + 1;
	}

	depth = get_depth_of_node_in_tree_by_key_helper(node->left, target_key);
	if (depth >= 0) {
		return depth + 1;
	}

	depth = get_depth_of_node_in_tree_by_key_helper(node->right, target_key);
	if (depth >= 0) {
		return depth + 1;
	}

	return -1;
}

int get_depth_of_node_in_tree_by_key(BinaryTree *binary_tree, int target_key) {
	return get_depth_of_node_in_tree_by_key_helper(binary_tree->root, target_key);
}

int find_height_of_node_in_binary_tree_helper(Node *node, int target_key, int *height_to_target_node) {
	if (node == NULL) {
		return -1;
	}

	int left_height = find_height_of_node_in_binary_tree_helper(node->left, target_key, height_to_target_node);

	int right_height = find_height_of_node_in_binary_tree_helper(node->right, target_key, height_to_target_node);

	int current_height;

	if (left_height > right_height) {
		current_height = left_height + 1;
	} else {
		current_height = right_height + 1;
	}

	if (node->key == target_key) {
		*height_to_target_node = current_height;
	}

	return current_height;
}

int get_height_of_node_in_binary_tree(BinaryTree *binary_tree, int target_key) {
	int height_to_target_node = -1;

	find_height_of_node_in_binary_tree_helper(binary_tree->root, target_key, &height_to_target_node);

	return height_to_target_node;
}

void show_tree_leaves_helper(Node *node) {
	if (node == NULL) {
		return;
	}

	if (node->left == NULL && node->right == NULL) {
		print_node(node);
		return;
	}

	show_tree_leaves_helper(node->left);
	show_tree_leaves_helper(node->right);
}

void print_tree_leaves(BinaryTree *binary_tree) {
	printf("\nLeaves of binary tree:\n");
	show_tree_leaves_helper(binary_tree->root);
}

void read_key(int *key) {
	assert(key);

	printf("Input key: ");
	scanf("%d", key);
}