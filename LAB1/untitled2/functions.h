//
// Created by nicud on 3/7/2024.
//

#ifndef UNTITLED2_FUNCTIONS_H
#define UNTITLED2_FUNCTIONS_H

#include <stdio.h>
#include "structs.h"


int count_rows(FILE *fp);

void print_elements(Student *list, int size);

void free_list(Student *list, int size);

int find_student_by_name(Student *list, int size, const char *name);

int find_student_by_group(Student *list, int size, int group);

int find_student_by_age(Student *list, int size, int age);

void sort_by_name(Student *list, int size);

void sort_by_age(Student *list, int size);

void sort_by_group(Student *list, int size);

void insert_item_start(Student **list, int *size);

void insert_item_end(Student **list, int *size);

void insert_item_by_index(Student **list, int *size);

void delete_item_by_index(Student **list, int *size);



#endif //UNTITLED2_FUNCTIONS_H
