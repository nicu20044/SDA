//
// Created by nicud on 3/27/2024.
//

#ifndef SDA_LAB2_STRUCTS_H
#define SDA_LAB2_STRUCTS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Car {
    char* mark;
    char* model;
    int fab_year;
    float price;
    struct Car* next;
};

enum menu{
    PRINT_LIST = 1,
    SEARCH_BY_FIELD,
    SORT_BY_CRITERIA,
    INSERT_LAST,
    INSERT_FIRST,
    INSERT_AT_POS,
    DELETE_AT_POS,
    INVERT_LIST,
    CLEAN_LIST ,
    EXIT = 0

};

/**
 * Reads a car from a file.
 *
 * @param file the file to read from
 * @return the car read from the file, or NULL if an error occurred
 */
 struct Car* read_car(FILE* file);
#endif //SDA_LAB2_STRUCTS_H
