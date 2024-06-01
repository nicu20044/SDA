#include <stdio.h>

#define MAX_SIZE 100

typedef struct Element{
    int pret;
    char nume[50];
}element;

void citire(element tablou[], int *n) {
    printf("Introdu numarul de elemente: ");
    scanf("%d", n);

    printf("Introdu elementele tabloului:\n");
    for (int i = 0; i < *n; ++i) {
        printf("Elementul %d:\n", i + 1);
        printf("Pretul: ");
        scanf("%d", &tablou[i].pret);
        printf("Marca: ");
        scanf("%s", tablou[i].nume);
    }
}

void afisare(element tablou[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("\nElementul %d: \nPretul - %d, Marca - %s\n", i + 1, tablou[i].pret, tablou[i].nume);
    }
}

int cautare(element tablou[], int n, int valoare_cautata) {
    for (int i = 0; i < n; ++i) {
        if (tablou[i].pret <= valoare_cautata) {
            return i;
        }
    }
    return -1;
}

int main() {
    element tablou[MAX_SIZE];
    int l;

    citire(tablou, &l);
    printf("\nElementele introduse sunt:\n");
    afisare(tablou, l);

    int valoare_cautata;
    printf("\nIntroduceti pretul cautat: ");
    scanf("%d", &valoare_cautata);

    int gasite = 0;
    for (int i = 0; i < l; i++) {
        if (tablou[i].pret <= valoare_cautata) {
            printf("\nMasina %s cu pretul(mai mic sau egal) %d a fost gasita la pozitia %d\n", tablou[i].nume, valoare_cautata, i);
            gasite = 1;
        }
    }

    if (!gasite) {
        printf("\nNicio masina cu pretul <= %d nu a fost gasita in tablou\n", valoare_cautata);
    }

    return 0;
}
