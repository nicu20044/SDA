//
// Created by nicud on 5/20/2024.
//

#ifndef LAB5_FUNC_H
#define LAB5_FUNC_H

double get_function_execution_time(int (*search_function)(int *, int, int), int *arr, int size, int value);

void initialize_array(int *arr, int size);

void print_array(int *arr, int size);

void free_array(int *arr);

void selection_sort(int *arr, int size);

void quick_sort(int *arr, int left, int right);

int linear_search(int *arr, int size, int value);

int binary_search(int *arr, int size, int value);

void add_array_for_fibonacci(int a[], int b[], int result[], int length);

void print_fibonacci(int result[], int length);

void calculate_fibonacci(int n);

void menu_for_first_problem();

void problem_1();

void menu_for_second_problem();

void problem_2();


#endif