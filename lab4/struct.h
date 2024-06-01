//
// Created by nicud on 5/8/2024.
//

#ifndef LAB4_STRUCT_H
#define LAB4_STRUCT_H

typedef struct Person{
    char* name;
    int age;
    double height;
    char position;
} Person;

struct TreeNode {
    int key;
    struct Person person;
    struct TreeNode* left;
    struct TreeNode* right;
};

typedef struct Tree {
    struct TreeNode* root;
} Tree;



#endif //LAB4_STRUCT_H
