//
// Created by nicud on 5/20/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "func.h"


double get_function_execution_time(int (*search_function)(int *, int, int), int *arr, int size, int value) {
    clock_t start = clock();
    int result = search_function(arr, size, value);
    clock_t end = clock();
    double execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Search result: %d\n", result);
    return execution_time;
}

void initialize_array(int *arr, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100000;
    }
}

void print_array(int *arr, int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void free_array(int *arr) {
    free(arr);
}

void selection_sort(int *arr, int size) {
    clock_t start = clock();

    for (int i = 0; i < size - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }

    clock_t end = clock();
    double execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Selection Sort lasted for: %.6f seconds\n", execution_time);
}

void quick_sort(int *arr, int left, int right) {
    if (left < right) {
        int pivot = arr[(left + right) / 2];
        int i = left, j = right;
        while (i <= j) {
            while (arr[i] < pivot) i++;
            while (arr[j] > pivot) j--;
            if (i <= j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        }
        quick_sort(arr, left, j);
        quick_sort(arr, i, right);
    }
}

int linear_search(int *arr, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

int binary_search(int *arr, int size, int value) {
    clock_t start = clock();

    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            clock_t end = clock();
            double execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("Binary Search lasted for: %.6f seconds\n", execution_time);
            return mid;
        }
        if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    clock_t end = clock();
    double execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Binary Search lasted for: %.6f seconds\n", execution_time);
    return -1;
}

void add_array_for_fibonacci(int a[], int b[], int result[], int length) {
    int carry = 0;
    for (int i = length - 1; i >= 0; i--) {
        int sum = a[i] + b[i] + carry;
        result[i] = sum % 10;
        carry = sum / 10;
    }
}

void print_fibonacci(int result[], int length) {
    int i = 0;
    while (i < length && result[i] == 0) {
        i++;
    }

    if (i == length) {
        printf("0");
    } else {
        for (; i < length; i++) {
            printf("%d", result[i]);
        }
    }
    printf("\n");
}

void calculate_fibonacci(int n) {
    clock_t start = clock();
    int maxLength = 200000;
    int *fib1 = calloc(maxLength, sizeof(int));
    int *fib2 = calloc(maxLength, sizeof(int));
    int *result = calloc(maxLength, sizeof(int));
    if (!fib1 || !fib2 || !result) {
        printf("Memory allocation failed\n");
        free(fib1);
        free(fib2);
        free(result);
        return;
    }
    fib1[maxLength - 1] = 1;

    for (int i = 2; i <= n; i++) {
        add_array_for_fibonacci(fib1, fib2, result, maxLength);
        int *temp = fib2;
        fib2 = fib1;
        fib1 = result;
        result = temp;
    }

    print_fibonacci(fib1, maxLength);
    free(fib1);
    free(fib2);
    free(result);
    clock_t end = clock();
    double execution_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Fibonacci calculation lasted for: %.6f seconds\n", execution_time);
}

void menu_for_first_problem() {
    printf("\n---------------Menu---------------\n");
    printf("1. Initialize array with random numbers\n");
    printf("2. Display array\n");
    printf("3. Free array\n");
    printf("4. Selection Sort\n");
    printf("5. Quick Sort\n");
    printf("6. Exit\n");
}

void problem_1() {
    int *array = NULL;
    int size = 0;
    int option;

    do {
        menu_for_first_problem();
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the size of the array: ");
                scanf("%d", &size);
                array = (int *)malloc(size * sizeof(int));
                if (!array) {
                    printf("Memory allocation failed\n");
                    break;
                }
                initialize_array(array, size);
                break;
            case 2:
                if (array == NULL) {
                    printf("The array is not initialized\n");
                } else {
                    print_array(array, size);
                }
                break;
            case 3:
                if (array != NULL) {
                    free_array(array);
                    array = NULL;
                    printf("The array memory has been freed\n");
                } else {
                    printf("The array is not initialized\n");
                }
                break;
            case 4:
                if (array == NULL) {
                    printf("The array is not initialized\n");
                } else {
                    selection_sort(array, size);
                }
                break;
            case 5:
                if (array == NULL) {
                    printf("The array is not initialized\n");
                } else {
                    clock_t start = clock();
                    quick_sort(array, 0, size - 1);
                    clock_t end = clock();
                    double timp_executie = ((double)(end - start)) / CLOCKS_PER_SEC;
                    printf("Quick Sort lasted for: %.6f seconds\n", timp_executie);
                }
                break;
            case 6:
                printf("Exit\n");
                if (array != NULL) {
                    free_array(array);
                }
                break;
            case 7:
                return;
            default:
                printf("Invalid option\n");
        }
    } while (option != 6);
}

void menu_for_second_problem() {
    printf("1. Initialize array with random numbers\n");
    printf("2. Print array\n");
    printf("3. Free array\n");
    printf("4. Linear Search\n");
    printf("5. Binary Search\n");
    printf("6. Exit\n");
}


void problem_2() {
    int *array = NULL;
    int size = 0;
    int option;

    do {
        menu_for_second_problem();
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the size of the array: ");
                scanf("%d", &size);
                array = (int *)malloc(size * sizeof(int));
                if (!array) {
                    printf("Memory allocation failed\n");
                    break;
                }
                initialize_array(array, size);
                break;
            case 2:
                if (array == NULL) {
                    printf("The array is not initialized.\n");
                } else {
                    print_array(array, size);
                }
                break;
            case 3:
                if (array != NULL) {
                    free_array(array);
                    array = NULL;
                    printf("The array memory has been freed.\n");
                } else {
                    printf("The array is not initialized.\n");
                }
                break;
            case 4:
                if (array == NULL) {
                    printf("The array is not initialized.\n");
                } else {
                    int value;
                    printf("Enter the value you want to search for: ");
                    scanf("%d", &value);
                    double result = get_function_execution_time(linear_search, array, size, value);
                    printf("Execution time: %lf\n", result);
                }
                break;
            case 5:
                if (array == NULL) {
                    printf("The array is not initialized.\n");
                } else {
                    int value;
                    printf("Enter the value you want to search for: ");
                    scanf("%d", &value);
                    int result = binary_search(array, size, value);
                    if (result != -1) {
                        printf("Value %d found at index %d.\n", value, result);
                    } else {
                        printf("Value %d not found in the array.\n", value);
                    }
                }
                break;
            case 6:
                printf("Exiting program.\n");
                if (array != NULL) {
                    free_array(array);
                }
                break;
            case 7:
                return;
            default:
                printf("Invalid option!\n");
        }
    } while (option != 6);
}