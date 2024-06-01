#include <stdio.h>

#include "functions.h"

#define MAX_CHAR 50

// TODO: Alloc only necessary memory for strings
// TODO: Documentation according to doxygen standard
// TODO: use enum in switch statement

int main() {
    FILE* file;
    file = fopen("C:\\Users\\nicud\\Desktop\\SDA\\sda_lab2\\cars.txt", "r");
    if (file == NULL) {
        perror("Eroare la deschidere");
        return 1;
    }

    struct Car* lista_masini = NULL;
    struct Car* masina;

    printf("\nLista initiala de masini:\n");
    while ((masina = read_car(file)) != NULL) {
        if (lista_masini == NULL) {
            lista_masini = masina;
        } else {
            struct Car* temp = lista_masini;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = masina;
        }
        print_car(masina);
    }
    fclose(file);

    int optiune;
    int pozitie;
    char camp_cautat[MAX_CHAR];
    char valoare_cautata[MAX_CHAR];

    do {
        printf("\n------------Meniu:------------\n");
        printf("1. Afisare lista\n");
        printf("2. Cautare element dupa camp\n");
        printf("3. Sortare lista dupa un criteriu\n");
        printf("4. Inserare element la finalul listei\n");
        printf("5. Inserare element la inceputul listei\n");
        printf("6. Inserare element la o anumita pozitie\n");
        printf("7. Stergere element de pe o anumita pozitie\n");
        printf("8. Inversare ordine elemente\n");
        printf("9. Curatare lista\n");
        printf("0. Iesire\n");
        printf("Introduceti optiunea dvs: ");
        scanf("%d", &optiune);

        switch (optiune) {
            case PRINT_LIST:
                printf("\nAfisare lista de masini:\n");
                print_elements(lista_masini);
                break;
            case SEARCH_BY_FIELD:
                printf("\nIntroduceti campul dupa care doriti sa cautati: ");
                scanf("%s", camp_cautat);
                printf("Introduceti valoarea pe care doriti sa o cautati: ");
                scanf("%s", valoare_cautata);
                printf("Rezultatele cautarii:\n");
                pozitie = find_car_all_positions(lista_masini, camp_cautat, valoare_cautata);
                if (pozitie == 0) {
                    printf("Elementul nu a fost gasit\n");
                }
                break;

            case SORT_BY_CRITERIA:
            {
                char field[MAX_CHAR];
                printf("Introduceti campul dupa care doriti sa sortati (mark, model, fab_year, price): ");
                scanf("%s", field);

                sort_by_field(&lista_masini, field);

                printf("Lista a fost sortata dupa campul %s.\n", field);

                printf("Dupa sortare:\n");
                print_elements(lista_masini);
            }
                break;


            case INSERT_LAST:
                printf("Introduceti caracteristicele masinii");
                pop_back(&lista_masini);
                printf("Elementul a fost inserat la finalul listei.\n");
                break;
            case INSERT_FIRST:
                printf("Introduceti caracteristicele masinii");
                pop_front(&lista_masini);
                printf("Elementul a fost inserat la inceputul listei.\n");
                break;
            case INSERT_AT_POS:
                printf("Introduceti pozitia la care doriti sa inserati elementul: ");
                scanf("%d", &pozitie);
                insert_at_pos(&lista_masini, pozitie);
                break;
            case DELETE_AT_POS:
                printf("Introduceti pozitia de pe care doriti sa stergeti elementul: ");
                scanf("%d", &pozitie);
                delete_at_pos(&lista_masini, pozitie);
                break;
            case INVERT_LIST:
                reverse_list(&lista_masini);
                printf("Ordinea elementelor a fost inversata.\n");
                break;
            case CLEAN_LIST:
                clean_list(&lista_masini);
                printf("Lista a fost curatita\n");
                break;
            case EXIT:
                printf("Exiting...\n");
                break;
            default:
                printf("Optiune invalida. Va rugam introduceti o optiune valida.\n");
        }
    } while (optiune != 0);

    return 0;
}
