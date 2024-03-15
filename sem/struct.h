//
// Created by nicud on 3/13/2024.
//

#ifndef SEM_STRUCT_H
#define SEM_STRUCT_H

#define MAX_COLS 9
#define MAX_STRING_LENGTH 100
typedef struct {
    char date[11];
    int product_id;
    char product_name[MAX_STRING_LENGTH];
    char category[MAX_STRING_LENGTH];
    char subcategory[MAX_STRING_LENGTH];
    float unit_price;
    int quantity_sold;
    char country[MAX_STRING_LENGTH];
    char city[MAX_STRING_LENGTH];
} Sale;


#endif //SEM_STRUCT_H
