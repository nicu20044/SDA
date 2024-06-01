//
// Created by nicud on 5/8/2024.
//

#ifndef LAB4_FUNC_H
#define LAB4_FUNC_H

#include "struct.h"

/**
 * @brief Function to create a new node in the tree
 * @param key Key of the new node
 * @param name Name of the new node
 * @param age Age of the new node
 * @param height Height of the new node
 * @param position Position of the new node
 * @return Pointer to the new node
 */
struct TreeNode* create_node(int key, const char* name, int age, double height, char position);

/**
 * @brief Inserts a new node into the binary search tree.
 *
 * This function inserts a new node with the given key, name, age, height, and position into the binary search tree.
 * If the tree is empty, the new node becomes the root of the tree.
 * If the key already exists in the tree, the function does nothing.
 *
 * @param tree The binary search tree.
 * @param key The key of the new node.
 * @param name The name of the new employee.
 * @param age The age of the new employee.
 * @param height The height of the new employee.
 * @param position The position of the new employee.
 *
 * @return void
 */
void insert_node(struct Tree* tree, struct TreeNode* node);

/**
 * @brief Prints the tree in in-order (left-root-right) fashion.
 *
 * This function is a recursive helper function for printing the tree in
 * in-order (left-root-right) fashion. It prints the left subtree, the root,
 * and then the right subtree.
 *
 * @param root The root of the tree to be printed.
 *
 * @return void
 */
void _svd_helper(struct TreeNode* root);

/**
 * @brief Prints the node data in a pre-order (VSD) manner.
 *
 * This function prints the data of a given tree node in a pre-order manner.
 * It starts by printing the root node, then recursively calls itself for the left subtree,
 * and finally for the right subtree.
 *
 * @param root The root node of the tree.
 * @return void
 */
void _vsd_helper(struct TreeNode* root);

/**
 * @brief Prints the tree in SDV (In-Order) traversal.
 *
 * This function prints the tree in SDV (In-Order) traversal order.
 * It starts from the leftmost node, then the root, and finally the rightmost node.
 *
 * @param root The root of the tree to be printed.
 *
 * @return void.
 */
void _sdv_iterator(struct TreeNode* root);

/**
 * @brief Performs a Depth-First Search (DFS) traversal on the binary tree.
 *
 * This function recursively visits each node in the binary tree in a depth-first manner.
 * It starts from the root node and explores as far as possible along each branch before backtracking.
 * The function uses a stack to keep track of the nodes to visit.
 *
 * @param root The root node of the binary tree.
 *
 * @return void.
 */
void _dfs_helper(struct TreeNode* root);

/**
 * @brief Performs a breadth-first search (BFS) on a binary tree.
 *
 * This function uses a queue to perform a level-order traversal of the binary tree.
 * It starts from the root node and visits all nodes at the current level before moving to the next level.
 * The function prints each node's data using the print_node function.
 *
 * @param root The root node of the binary tree.
 *
 * @return void.
 */
void bfs(struct TreeNode* root);

/**
 * @brief Mirrors the binary tree by swapping the left and right child pointers of each node.
 *
 * @param root The root node of the binary tree.
 *
 * @details This function recursively mirrors the binary tree by swapping the left and right child pointers of each node.
 * The function starts from the root node and recursively mirrors the left and right subtrees.
 * If the root node is NULL, the function does nothing.
 *
 * @return void.
 */
void mirror_tree(struct TreeNode* root);

/**
 * @brief Prints the tree in DVS (Depth-First Search, Right-Left-Root) order.
 *
 * This function recursively traverses the tree in DVS order, starting from the node.
 * It prints the node data using the print_node function for each visited node.
 *
 * @param node The node of the tree to be printed.
 */
void _dvs_helper(struct TreeNode* node);

/**
 * @brief Searches for a node in the binary search tree based on the given key.
 *
 * @param root The root of the binary search tree.
 * @param key The key to search for.
 *
 * @note This function uses a recursive approach to search for the node.
 *
 * @return A pointer to the node with the given key if found, or NULL if not found.
 */
struct TreeNode* search(struct TreeNode* root, int key);

/**
 * @brief Function to clear the tree and free all allocated memory.
 *
 * This function recursively traverses the tree in post-order (left, right, root)
 * and frees the memory allocated for each node. It also frees the memory allocated
 * for the employee's name.
 *
 * @param root The root of the tree to be cleared.
 */
void clear_tree(struct TreeNode* root);

/**
 * @brief Function to free the memory allocated for the tree and its nodes.
 *
 * This function recursively frees the memory allocated for each node in the tree.
 * It starts from the root node and traverses the tree in post-order (left, right, root).
 * It frees the memory allocated for the name of each node and the node itself.
 *
 * @param root The root node of the tree.
 */
void free_tree(struct TreeNode* root);

/**
 * @brief Function to get the height of a node in the tree.
 *
 * This function calculates the height of a given node in the tree.
 * The height of a node is the number of edges on the longest path from the node to a leaf node.
 * If the node is NULL, the function returns 0.
 *
 * @param node The node for which the height needs to be calculated.
 * @return The height of the node.
 */
int get_height(struct TreeNode* node);

/**
 * @brief Updates the height of a given tree node.
 *
 * This function calculates the height of a given tree node by comparing the heights of its left and right subtrees.
 * The height of a node is defined as the maximum height of its left or right subtree plus one.
 *
 * @param node The tree node whose height needs to be updated.
 * @return void
 */
void update_height(struct TreeNode* node);

/**
 * @brief Function to check if a binary tree is balanced.
 *
 * This function calculates the balance factor of a given node in a binary tree.
 * The balance factor is the difference between the heights of the left and right subtrees.
 * If the balance factor is greater than 1 or less than -1, the tree is considered unbalanced.
 *
 * @param node The node for which to calculate the balance factor.
 * @return The balance factor of the given node. If the node is NULL, the function returns 0.
 */
int is_tree_balanced(struct TreeNode* node);

/**
 * @brief Performs a left rotation on a binary tree node.
 *
 * This function performs a left rotation on a binary tree node.
 * The left child of the original node becomes the new root,
 * and the original node becomes the right child of the new root.
 * The heights of the original node and its new parent are updated.
 *
 * @param x The original node on which the rotation is performed.
 * @return The new root of the rotated subtree.
 */
struct TreeNode* left_rotate(struct TreeNode* x);

/**
 * @brief Performs a right rotation on a given node in a binary tree.
 *
 * This function is used to balance an AVL tree after a left-right imbalance.
 * It performs a right rotation on the given node, rearranging the tree structure.
 *
 * @param y The node to perform the right rotation on.
 * @return The new root of the subtree after the rotation.
 */
struct TreeNode* right_rotate(struct TreeNode* y);

/**
 * @brief Function to balance a node in a binary search tree.
 *
 * This function is used to balance a node in a binary search tree. It checks the balance factor of the node,
 * and performs rotations if necessary to balance the tree.
 *
 * @param node The node to be balanced.
 * @return The balanced node.
 */
struct TreeNode* balance_node(struct TreeNode* node);

/**
 * @brief Prints the details of a given tree node.
 *
 * This function prints the key, name, age, height, and position of a given tree node.
 * If the node is NULL, the function does nothing.
 *
 * @param node The tree node to be printed.
 */
void print_node(struct TreeNode * node);

/**
 * @brief Displays a menu for the user to interact with the tree.
 *
 * @param choice Pointer to an integer that will hold the user's choice.
 * @param key Pointer to an integer that will hold the key of the new node.
 * @param age Pointer to an integer that will hold the age of the new employee.
 * @param height Pointer to a double that will hold the height of the new employee.
 * @param name Pointer to a character array that will hold the name of the new employee.
 * @param position Pointer to a character that will hold the position of the new employee.
 * @param tree Pointer to the tree structure.
 * @param found_node Pointer to a pointer to a TreeNode structure that will hold the found node.
 *
 * @return void
 */
void menu(struct Tree *tree);

#endif //LAB4_FUNC_H
