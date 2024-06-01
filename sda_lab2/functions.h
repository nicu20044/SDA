//
// Created by nicud on 3/14/2024.
//
#ifndef SDA_LAB2_FUNCTIONS_H
#define SDA_LAB2_FUNCTIONS_H

#include <stdio.h>
#include "structs.h"


/**
 * function used to print cars from file
 * @param masina
 * @return void
 */
void print_car(struct Car* masina);

/**
 *function used to free list of cars
 * @param head
 * @return void
 */
void free_list(struct Car* head) ;

/**
 * function used to print elements at user request
 * @param head
 * @return void
 */
void print_elements(struct Car* head);

/**
 * function used to swap cars
 * @param car1
 * @param car2
 * @return void
 */
void swap_cars(struct Car *car1, struct Car *car2) ;

/**
 *function used to sort by a certain field
 * @param head_ref
 * @param field
 * @return void
 */
void sort_by_field(struct Car** head_ref, char* field);

/**
 *function used to delete last element of list
 * @param head
 * @return void
 */
void pop_back(struct Car** head) ;

/**
 *function used to delete first element of list
 * @param head
 * @return void
 */
void pop_front(struct Car** head);

/**
 *function used to insert a element at a certain position
 * @param head
 * @param pozitie
 */
void insert_at_pos(struct Car** head, int pozitie);

/**
 *function used to insert a element at a certain position
 * @param head
 * @param pozitie
 * @return void
 */
void delete_at_pos(struct Car** head, int pozitie) ;

/**
 *function used to reverse the list
 * @param head
 * @return void
 */
void reverse_list(struct Car** head);

/**
 *function used to clean list
 * @param head
 * @return void
 */
void clean_list(struct Car** head);

/**
 *function used to find a car by a field value
 * @param list
 * @param camp
 * @param valoare
 * @return found
 */
int find_car_all_positions(struct Car* list, char* camp, char* valoare) ;
#endif //SDA_LAB2_FUNCTIONS_H
