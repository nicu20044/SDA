//
// Created by nicud on 3/14/2024.
//
#include <string.h>
#include <stdlib.h>

#include "functions.h"

void print_car(struct Car *masina) {
    printf("Marca: %10s\t", masina->mark);
    printf("Model: %10s\t", masina->model);
    printf("Anul fabricatiei: %4d\t", masina->fab_year);
    printf("Pret: %.2f\n", masina->price);
}

void free_list(struct Car *head) {
    struct Car *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp->mark);
        free(tmp->model);
        free(tmp);
    }
}

void print_elements(struct Car *head) {
    printf("Lista masinilor:\n");
    struct Car *current = head;
    while (current != NULL) {
        printf("Marca: %10s, Model: %10s, Anul fabricatiei: %4d, Pretul: %.2f\n", current->mark, current->model,
               current->fab_year, current->price);
        current = current->next;
    }
}


void swap_cars(struct Car *car1, struct Car *car2) {
    struct Car temp = *car1;
    car1->mark = car2->mark;
    car1->model = car2->model;
    car1->fab_year = car2->fab_year;
    car1->price = car2->price;

    car2->mark = temp.mark;
    car2->model = temp.model;
    car2->fab_year = temp.fab_year;
    car2->price = temp.price;
}

void sort_by_field(struct Car **head_ref, char *field) {
    struct Car *ptr1;
    struct Car *ptr2 = NULL;
    int swapped;
    if (head_ref == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = *head_ref;

        while (ptr1->next != ptr2) {
            int compare = 0;
            if (strcmp(field, "mark") == 0) {
                compare = strcmp(ptr1->mark, ptr1->next->mark);
            } else if (strcmp(field, "model") == 0) {
                compare = strcmp(ptr1->model, ptr1->next->model);
            } else if (strcmp(field, "fab_year") == 0) {
                compare = ptr1->fab_year - ptr1->next->fab_year;
            } else if (strcmp(field, "price") == 0) {
                compare = (ptr1->price > ptr1->next->price) ? 1 : -1;
            }

            if (compare > 0) {
                swap_cars(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    } while (swapped);
}

void pop_back(struct Car **head) {
    FILE *file;
    file = fopen("masini.txt", "a");
    if (file == NULL) {
        printf("Nu am putut deschide fișierul.");
        return;
    }

    struct Car *masina = read_car(stdin);
    if (*head == NULL) {
        *head = masina;
    } else {
        struct Car *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = masina;
    }

    fprintf(file, "%s %s %d %.2f\n", masina->mark, masina->model, masina->fab_year, masina->price);

    fclose(file);
}

void pop_front(struct Car **head) {
    FILE *file;
    file = fopen("masini.txt", "r+");
    if (file == NULL) {
        printf("Nu am putut deschide fișierul.");
        return;
    }

    struct Car *masina = read_car(stdin);
    masina->next = *head;
    *head = masina;

    fseek(file, 0, SEEK_SET);
    fprintf(file, "%s %s %d %.2f\n", masina->mark, masina->model, masina->fab_year, masina->price);

    fclose(file);
}

void insert_at_pos(struct Car **head, int pozitie) {
    FILE *file;
    file = fopen("masini.txt", "r+");
    if (file == NULL) {
        printf("Nu am putut deschide fișierul.");
        return;
    }

    struct Car *masina = read_car(stdin);
    struct Car *temp = *head;
    int i = 0;
    while (temp != NULL && i < pozitie - 1) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL || i > pozitie - 1) {
        printf("Poziția specificată este invalidă.\n");
        return;
    }
    masina->next = temp->next;
    temp->next = masina;

    fseek(file, 0, SEEK_END);
    fprintf(file, "%s %s %d %.2f\n", masina->mark, masina->model, masina->fab_year, masina->price);

    fclose(file);
}

void delete_at_pos(struct Car **head, int pozitie) {
    FILE *file;
    file = fopen("masini.txt", "r+");
    if (file == NULL) {
        printf("Nu am putut deschide fișierul.");
        return;
    }

    if (*head == NULL) {
        printf("Lista este goală.\n");
        return;
    }
    struct Car *temp = *head;
    if (pozitie == 0) {
        *head = temp->next;
        free(temp->mark);
        free(temp->model);
        free(temp);
        printf("Elementul de pe poziția %d a fost șters.\n", pozitie);
        return;
    }
    int i = 0;
    while (temp != NULL && i < pozitie - 1) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Poziția specificată este invalidă.\n");
        return;
    }
    struct Car *next = temp->next->next;
    free(temp->next->mark);
    free(temp->next->model);
    free(temp->next);
    temp->next = next;

    fseek(file, 0, SEEK_SET);
    fprintf(file, "");

    struct Car *current = *head;
    while (current != NULL) {
        fprintf(file, "%s %s %d %.2f\n", current->mark, current->model, current->fab_year, current->price);
        current = current->next;
    }

    fclose(file);
}

void reverse_list(struct Car **head) {
    struct Car *prev = NULL;
    struct Car *current = *head;
    struct Car *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void clean_list(struct Car **head) {
    free_list(*head);
    *head = NULL;
}

int find_car_all_positions(struct Car *list, char *camp, char *valoare) {
    int found = 0;
    int pozitie = 1;
    struct Car *temp = list;

    while (temp != NULL) {
        if (strcmp(camp, "mark") == 0 && strcmp(temp->mark, valoare) == 0) {
            printf("Pozitie %d: Marca: %s, Model: %s, Anul fabricatiei: %d, Pretul: %.2f\n", pozitie, temp->mark,
                   temp->model, temp->fab_year, temp->price);
            found = 1;
        } else if (strcmp(camp, "model") == 0 && strcmp(temp->model, valoare) == 0) {
            printf("Pozitie %d: Marca: %s, Model: %s, Anul fabricatiei: %d, Pretul: %.2f\n", pozitie, temp->mark,
                   temp->model, temp->fab_year, temp->price);
            found = 1;
        } else if (strcmp(camp, "fab_year") == 0 && temp->fab_year == atoi(valoare)) {
            printf("Pozitie %d: Marca: %s, Model: %s, Anul fabricatiei: %d, Pretul: %.2f\n", pozitie, temp->mark,
                   temp->model, temp->fab_year, temp->price);
            found = 1;
        } else if (strcmp(camp, "price") == 0 && temp->price == atof(valoare)) {
            printf("Pozitie %d: Marca: %s, Model: %s, Anul fabricatiei: %d, Pretul: %.2f\n", pozitie, temp->mark,
                   temp->model, temp->fab_year, temp->price);
            found = 1;
        }
        temp = temp->next;
        pozitie++;
    }

    return found;
}


