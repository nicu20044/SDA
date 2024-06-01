//
// Created by nicud on 3/27/2024.
//
#include <stdbool.h>
#include "structs.h"

#define MAX_CHAR 50

struct Car *read_car(FILE *file) {

    char tmp_mark_buffer[MAX_CHAR];
    char tmp_model_buffer[MAX_CHAR];
    int tmp_fab_year;
    float tmp_price;

    bool scanning_status = fscanf(file, "%s %s %d %f", tmp_mark_buffer, tmp_model_buffer, &tmp_fab_year, &tmp_price);

    if (!scanning_status) {
        return NULL;
    }

    struct Car *masina = (struct Car *) malloc(sizeof(struct Car));

    if (masina == NULL) {
        return NULL;
    }

    masina->mark = (char *) malloc((strlen(tmp_mark_buffer) + 1) * sizeof(char));
    if (masina->mark == NULL) {
        free(masina);
        return NULL;
    }
    strcpy(masina->mark, tmp_mark_buffer);

    masina->model = (char *) malloc((strlen(tmp_model_buffer) + 1) * sizeof(char));
    if (masina->model == NULL) {
        free(masina->mark);
        free(masina);
        return NULL;
    }
    strcpy(masina->model, tmp_model_buffer);

    masina->fab_year = tmp_fab_year;
    masina->price = tmp_price;

    masina->next = NULL;
    return masina;
}
