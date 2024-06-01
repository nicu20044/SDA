#include <stdio.h>
#include "func.h"


int main() {

    double height;
    char name[50], position;
    struct TreeNode* foundNode;

    struct Tree tree;
    tree.root = NULL;

    insert_node(&tree, 50, "Andrei", 30, 1.70, 'S');
    insert_node(&tree, 30, "Alina", 25, 1.65, 'I');
    insert_node(&tree, 70, "Mihai", 35, 1.80, 'M');
    insert_node(&tree, 20, "Evelina", 22, 1.60, 'S');
    insert_node(&tree, 40, "Stefan", 28, 1.70, 'I');
    insert_node(&tree, 60, "Cristi", 32, 1.72, 'S');
    insert_node(&tree, 80, "Dragos", 40, 1.85, 'F');

    menu(&tree);

    free_tree(tree.root);

    return 0;
}

