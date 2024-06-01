//
// Created by nicud on 3/7/2024.
//
#include <string.h>
#include <stdlib.h>

#include "functions.h"

int count_rows(FILE *fp) {
    int lines = 0;
    char buf[200];

    while(fgets(buf,sizeof(buf),fp) != NULL)
    {
        lines++;
    }
    rewind(fp);

    return lines;
}

void print_elements(Student *list, int size) {
    printf("Lista studentilor:\n");
    for (int i = 0; i < size; i++) {
        printf("Nume: %s, Grupa: %d, Varsta: %d\n", list[i].name, list[i].group, list[i].age);
    }
}

void free_list(Student *list, int size) {
    for (int i = 0; i < size; i++) {
        free(list[i].name);
    }
    free(list);
}

int find_student_by_name(Student *list, int size, const char *name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(list[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int find_student_by_group(Student *list, int size, int group) {
    for (int i = 0; i < size; i++) {
        if (list[i].group == group) {
            return i;
        }
    }
    return -1;
}

int find_student_by_age(Student *list, int size, int age) {
    for (int i = 0; i < size; i++) {
        if (list[i].age == age) {
            return i;
        }
    }
    return -1;
}

void swap_students(Student *student1, Student *student2) {
    Student *temp = student1;
    *student1 = *student2;
    *student2 = *temp;
}


void sort_by_name(Student *list, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(list[j].name, list[j + 1].name) > 0) {
                swap_students(&list[j], &list[j + 1]);
            }
        }
    }
    printf("Dupa sortare:\n");
    for (int i = 0; i < size; i++) {
        printf("Numele: %s, Grupa: %d, Varsta: %d\n", list[i].name, list[i].group, list[i].age);
    }
}

void sort_by_age(Student *list, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (list[j].age > list[j + 1].age) {
                swap_students(&list[j], &list[j + 1]);
            }
        }
    }
    printf("Dupa sortare:\n");
    for (int i = 0; i < size; i++) {
        printf("Numele: %s, Grupa: %d, Varsta: %d\n", list[i].name, list[i].group, list[i].age);
    }
}

void sort_by_group(Student *list, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (list[j].group > list[j + 1].group) {
                swap_students(&list[j], &list[j + 1]);
            }
        }
    }
    printf("Dupa sortare:\n");
    for (int i = 0; i < size; i++) {
        printf("Numele: %s, Grupa: %d, Varsta: %d\n", list[i].name, list[i].group, list[i].age);
    }
}

void insert_item_start(Student **list, int *size) {
    *size += 1;
    *list = (Student*)realloc(*list, *size * sizeof(Student));
    for (int i = *size - 1; i > 0; i--) {
        (*list)[i] = (*list)[i - 1];
    }
    printf("Introduceti detalii pentru noul Student la inceput:\n");
    (*list)[0].name = (char*)malloc(50 * sizeof(char));
    printf("Nume: ");
    scanf("%s", (*list)[0].name);
    printf("Grupa: ");
    scanf("%d", &(*list)[0].group);
    printf("Varsta: ");
    scanf("%d", &(*list)[0].age);
}

void insert_item_end(Student **list, int *size) {
    *size += 1;
    *list = (Student*)realloc(*list, *size * sizeof(Student));
    if (*list == NULL) {
        perror("Eroare la realocare");
        exit(1);
    }

    (*list)[*size - 1].name = (char*)malloc(50 * sizeof(char));
    if ((*list)[*size - 1].name == NULL) {
        perror("Eroare la alocare");
        exit(1);
    }

    printf("Nume: ");
    scanf("%s", (*list)[*size - 1].name);
    printf("Grupa: ");
    scanf("%d", &(*list)[*size - 1].group);
    printf("Varsta: ");
    scanf("%d", &(*list)[*size - 1].age);
}

void insert_item_by_index(Student **list, int *size) {
    *size += 1;
    *list = (Student*)realloc(*list, *size * sizeof(Student));
    if (*list == NULL) {
        perror("Eroare la realocare");
        exit(1);
    }

    int index;
    printf("Introduceti pozitia: ");
    scanf("%d", &index);

    for (int i = *size - 1; i > index-1; i--) {
        (*list)[i] = (*list)[i - 1];
    }

    (*list)[index].name = (char*)malloc(50 * sizeof(char));
    if ((*list)[index].name == NULL) {
        perror("Eroare la alocare");
        exit(1);
    }

    printf("Introduceti detalii pentru noul Student la pozitia %d:\n", index);
    printf("Nume: ");
    scanf("%s", (*list)[index].name);
    printf("Grupa: ");
    scanf("%d", &(*list)[index].group);
    printf("Varsta: ");
    scanf("%d", &(*list)[index].age);
}

void delete_item_by_index(Student **list, int *size) {
    int index;
    printf("Introduceti pozitia elementului de sters: ");
    scanf("%d", &index);

    if (index < 0 || index >= *size) {
        printf("Index invalid. Operatiunea de stergere nu a fost efectuata.\n");
        return;
    }

    free((*list)[index].name);

    for (int i = index; i < *size - 1; i++) {
        (*list)[i] = (*list)[i+1];
    }

    --(*size);

    *list = (Student*)realloc(*list, *size * sizeof(Student));
    if (*list == NULL && *size > 0) {
        perror("Eroare la realocare");
        exit(1);
    }

    printf("Elementul de la pozitia %d a fost sters.\n", index);
}
