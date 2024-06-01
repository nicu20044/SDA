//
// Created by nicud on 5/89/2024.
//

#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Menu_Option
{
    ADD_NODE = 1,
    PRINT_TREE_VSD ,
    PRINT_TREE_SVD ,
    PRINT_TREE_SDV ,
    PRINT_TREE_DFS ,
    PRINT_TREE_BFS ,
    SEARCH_NODE ,
    MIRROR_TREE ,
    BALANCE_TREE ,
    EXIT
};

struct TreeNode* create_node(int key, const char* name, int age, double height, char position) {
    struct TreeNode* new_node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (new_node == NULL) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    new_node->key = key;
    new_node->person.name = strdup(name);
    if (new_node->person.name == NULL) {
        printf("Memory allocation error\n");
        free(new_node);
        exit(EXIT_FAILURE);
    }
    new_node->person.age = age;
    new_node->person.height = height;
    new_node->person.position = position;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void print_node(struct TreeNode * node)
{
    if( node == NULL)
    {
        return;
    }
    printf("Key: %d, Name: %s, Age: %d, Height: %.2f, Position: %c\n", node->key, node->person.name, node->person.age, node->person.height, node->person.position);
}
void insert_node(Tree* tree, struct TreeNode* node) {
    if (tree->root == NULL) {
        tree->root = node;
        return;
    }

    struct TreeNode* current_node = tree->root;
    while (1) {
        if (node->key < current_node->key) {
            if (current_node->left == NULL) {
                current_node->left = node;
                return;
            }
            current_node = current_node->left;
        } else if (node->key > current_node->key) {
            if (current_node->right == NULL) {
                current_node->right = node;
                return;
            }
            current_node = current_node->right;
        } else {
            return;
        }
    }
}


void _svd_helper(struct TreeNode* root) /*inorder*/{
    if (root != NULL) {
        _svd_helper(root->left);
        print_node(root);
        _svd_helper(root->right);
    }
}

void SVD_helper(Tree *tree ) {
    if (!tree) {
        return;
    }
    _svd_helper(tree->root);
}


void _vsd_helper(struct TreeNode* root) /*preorder*/ {
    if (root != NULL) {
        print_node(root);
        _vsd_helper(root->left);
        _vsd_helper(root->right);
    }
}

void VSD_helper(Tree *tree ) {
    if (!tree) {
        return;
    }
    _dvs_helper(tree->root);
}


void _sdv_iterator(struct TreeNode* root) /*postorder*/{
    if (root != NULL) {
        _sdv_iterator(root->left);
        _sdv_iterator(root->right);
        print_node(root);
    }
}

void SDV_helper(Tree *tree ) {
    if (!tree) {
        return;
    }
    _sdv_iterator(tree->root);
}


void _dfs_helper(struct TreeNode* root) {
    if (root != NULL) {
        print_node(root);
        _dfs_helper(root->left);
        _dfs_helper(root->right);
    }
}

void DFS_helper(Tree *tree ) {
    if (!tree) {
        return;
    }
    _dfs_helper(tree->root);
}

void bfs(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct TreeNode* queue[1000];
    int front = 0, back = 0;
    queue[back++] = root;

    while (front < back) {
        struct TreeNode* current = queue[front++];
        print_node(current);

        if (current->left != NULL)
            queue[back++] = current->left;
        if (current->right != NULL)
            queue[back++] = current->right;
    }
}

void mirror_tree(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror_tree(root->left);
    mirror_tree(root->right);
}

void _dvs_helper(struct TreeNode* node) {
    if (node != NULL) {
        _dvs_helper(node->right);
        print_node(node);
        _dvs_helper(node->left);
    }
}

void DVS_helper(Tree *tree ) {
    if (!tree) {
        return;
    }
    _dvs_helper(tree->root);
}

struct TreeNode* search(struct TreeNode* root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (key < root->key)
        return search(root->left, key);

    return search(root->right, key);
}

void clear_tree(struct TreeNode* root) {
    if (root != NULL) {
        clear_tree(root->left);
        clear_tree(root->right);
        free(root->person.name);
        free(root);
    }
}

void free_tree(struct TreeNode* root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root->person.name);
        free(root);
    }
}

int get_height(struct TreeNode* node) {
    if (node == NULL)
        return 0;
    return node->person.height;
}

void update_height(struct TreeNode* node) {
    int left_height = get_height(node->left);
    int right_height = get_height(node->right);
    node->person.height = (left_height > right_height ? left_height : right_height) ;
}

int is_tree_balanced(struct TreeNode* node) {
    if (node == NULL)
        return 0;
    return get_height(node->left) - get_height(node->right);
}

struct TreeNode* left_rotate(struct TreeNode* x) {
    struct TreeNode* y = x->right;
    struct TreeNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    update_height(x);
    update_height(y);

    return y;
}

struct TreeNode* right_rotate(struct TreeNode* y) {
    struct TreeNode* x = y->left;
    struct TreeNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    update_height(y);
    update_height(x);

    return x;
}

struct TreeNode* balance_node(struct TreeNode* node) {
    update_height(node);

    int balance = is_tree_balanced(node);

    if (balance > 1) {
        if (is_tree_balanced(node->left) >= 0)
            return right_rotate(node);
        else {
            node->left = left_rotate(node->left);
            return right_rotate(node);
        }
    }
    if (balance < -1) {
        if (is_tree_balanced(node->right) <= 0)
            return left_rotate(node);
        else {
            node->right = right_rotate(node->right);
            return left_rotate(node);
        }
    }
    return node;
}





void menu(Tree* tree) {
    int choice;
    do {
        printf("\n--------Menu--------\n");
        printf("1. Add node\n");
        printf("2. VSD\n");
        printf("3. SVD\n");
        printf("4. SDV\n");
        printf("5. DFS\n");
        printf("6. BFS\n");
        printf("7. Search employee\n");
        printf("8. Mirror tree\n");
        printf("9. Balance tree\n");
        printf("10. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case ADD_NODE: {
                int key;
                char name[100];
                int age;
                double height;
                char position;

                printf("Enter the key: ");
                scanf("%d", &key);
                printf("Enter the name of the new employee: ");
                scanf("%s", name);
                printf("Enter the age of the new employee: ");
                scanf("%d", &age);
                printf("Enter the height of the new employee: ");
                scanf("%lf", &height);
                printf("Enter the position of the new employee: ");
                scanf(" %c", &position);

                insert_node(tree, key);
                break;
            }
            case PRINT_TREE_VSD:
                printf("VSD:\n");
                _vsd_helper(tree->root);
                printf("\n");
                break;
            case PRINT_TREE_SVD:
                printf("SVD:\n");
                _svd_helper(tree->root);
                printf("\n");
                break;
            case PRINT_TREE_SDV:
                printf("SDV:\n");
                _sdv_iterator(tree->root);
                printf("\n");
                break;
            case PRINT_TREE_DFS:
                printf("DFS:\n");
                _dfs_helper(tree->root);
                printf("\n");
                break;
            case PRINT_TREE_BFS:
                printf("BFS:\n");
                bfs(tree->root);
                printf("\n");
                break;
            case SEARCH_NODE: {
                int key;
                printf("Enter the key you are searching for: ");
                scanf("%d", &key);
                struct TreeNode* found_node = search(tree->root, key);
                if (found_node != NULL)
                    printf("The employee with key %d was found\n", found_node->key);
                else
                    printf("The employee with key %d was not found\n", key);
                break;
            }
            case MIRROR_TREE:
                mirror_tree(tree->root);
                printf("Tree was mirrored:\n");
                _vsd_helper(tree->root);
                printf("\n");
                break;
            case BALANCE_TREE:
                balance_node((struct TreeNode *) tree);
                printf("Tree was balanced:\n");
                break;
            case EXIT:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option\n");
        }
    } while (choice != EXIT);
}