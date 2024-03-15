//
// Created by nicud on 3/13/2024.
//

#ifndef SEM_FUNCTIONS_H
#define SEM_FUNCTIONS_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "struct.h"

int count_rows(FILE *file) ;

void read_sales_data(const char *filepath) ;

float calculate_total_revenue(int month, int year) ;

void print_top_5_products() ;

void print_sales_per_category(const char *category);

void print_cities_with_highest_sales(const char *country) ;

void print_monthly_sales_trends(int year);

void free_sales_data();

#endif //SEM_FUNCTIONS_H
