#ifndef _FUNCS_H_
#define _FUNCS_H_

#include "struct.h"
/**
 * Creates a new node with the given person data.
 *
 * @param person the person data to store in the node
 * @return the new node
 */
Node *create_node(Person *person);

/**
 * Deletes a node and its associated data.
 *
 * @param tree_node the node to delete
 */
void delete_tree_node(Node *tree_node);

/**
 * Creates a new binary tree.
 *
 * @return the new tree
 */
BinaryTree *create_tree();

/**
 * Deletes all nodes in a binary tree, but does not delete the tree itself.
 *
 * @param current the current node in the tree
 */
void delete_all_tree_nodes_from_node(Node *current);

/**
 * Deletes a binary tree and all its nodes.
 *
 * @param tree the tree to delete
 */
void clear_tree(BinaryTree *tree);

/**
 * Deletes a binary tree and all its nodes.
 *
 * @param tree the tree to delete
 */
void delete_tree(BinaryTree *tree);

/**
 * Inserts a new node into a binary tree.
 *
 * @param current the current node in the tree
 * @param new_node the node to insert
 */
void insert_node(Node *current, Node *new_node);

/**
 * Prints the contents of a node.
 *
 * @param node the node to print
 */
void print_tree_node(Node *node);

/**
 * Prints the contents of a binary tree using a given iterator function.
 *
 * @param tree the tree to print
 * @param tree_iterator the function to use for iterating over the tree
 */
void print_tree(BinaryTree *tree, TreeIterator tree_iterator);

/**
 * Performs a SDV operation on a node.
 *
 * @param current the current node in the tree
 * @param execution_node the node to execute the operation on
 */
void SDV_initiator(Node *current, ExecutionNode execution_node);

/**
 * Performs a SVD operation on a node.
 *
 * @param current the current node in the tree
 * @param execution_node the node to execute the operation on
 */
void SVD_initiator(Node *current, ExecutionNode execution_node);

/**
 * Performs a VSD operation on a node.
 *
 * @param current the current node in the tree
 * @param execution_node the node to execute the operation on
 */
void VSD_initiator(Node *current, ExecutionNode execution_node);

/**
 * Inserts a new node into a binary tree.
 *
 * @param tree the tree to insert into
 * @param node the node to insert
 */
void insert_node_in_tree(BinaryTree *tree, Node *node);

/**
 * Searches for a node with a given key in a binary tree using depth-first search.
 *
 * @param current the current node in the tree
 * @param key the key to search for
 * @return the node with the given key, or NULL if no node was found
 */
Node *DFS_helper(Node *current, int key);

/**
 * Searches for a node with a given key in a binary tree using depth-first search.
 *
 * @param tree the tree to search in
 * @param key the key to search for
 * @return the node with the given key, or NULL if no node was found
 */
Node *DFS(BinaryTree *tree, int key);

/**
 * Prints a list of options.
 *
 * @param options the list of options to print
 */
void print_options(const ListOptionsStruct *options);

/**
 * Prints a list of options.
 *
 * @param options the list of options to print
 */
ListOptionsStruct *create_struct_of_options(ListOption *list_options, int length);

/**
 * Creates a new Person object.
 *
 * @return the new Person object
 */
Person *create_person();

/**
 * Reads a Person object from a file.
 *
 * @param file the file to read from
 * @return the Person object read from the file
 */
void *_read_person_form_file(FILE *file);

/**
 * Frees a Person object and its associated data.
 *
 * @param person the Person object to free
 */
void free_person(Person *person);

/**
 * Frees a Node object and its associated data.
 *
 * @param node the Node object to free
 */
void free_node(Node *node);

/**
 * Prints a Person object to the console.
 *
 * @param person the Person object to print
 */
void print_person(const Person *person);

/**
 * Reads Person objects from a file and inserts them into a binary tree.
 *
 * @param file the file to read from
 * @param binary_tree the binary tree to insert the Person objects into
 */
void import_data_from_file_in_binary_tree(const char *file, BinaryTree *binary_tree);

/**
 * Reads a position from the console.
 *
 * @param position a pointer to an integer to store the position in
 */
void read_position(int *position);

/**
 * Reads an option from the console.
 *
 * @return the option that was selected
 */
int read_option();

/**
 * Returns the height of a binary tree.
 *
 * @param binary_tree the binary tree to get the height of
 * @return the height of the binary tree
 */
int get_height_of_binary_tree(BinaryTree *binary_tree);

/**
 * Reads a key from the console.
 *
 * @param key a pointer to an integer to store the key in
 */
void read_key(int *key);

/**
 * Returns the height of a node in a binary tree.
 *
 * @param binary_tree the binary tree to get the height of
 * @param target_key the key of the node to get the height of
 * @return the height of the node with the given key, or -1 if the node does not exist
 */
int get_height_of_node_in_binary_tree(BinaryTree *binary_tree, int target_key);

/**
 * Returns the depth of a node in a binary tree by key.
 *
 * @param binary_tree the binary tree to get the depth of
 * @param target_key the key of the node to get the depth of
 * @return the depth of the node with the given key, or -1 if the node does not exist
 */
int get_depth_of_node_in_tree_by_key(BinaryTree *binary_tree, int target_key);

/**
 * Prints the leaves of a binary tree.
 *
 * @param binary_tree the binary tree to print the leaves of
 */
void print_tree_leaves(BinaryTree *binary_tree);

/**
 * Prints a Node object to the console.
 *
 * @param node the Node object to print
 */
void print_node(const Node *node);

/**
 * Builds a binary tree from a binary tree.
 *
 * @param binary_tree the binary tree to build the new tree from
 * @return the new binary tree
 */
Node * build_tree(BinaryTree *binary_tree);

#endif //_FUNCS_H_
