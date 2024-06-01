#include <stdlib.h>
#include "functions.h"

int main() {

    int group_to_find;
    int age_to_find;
    char name_to_find[50];

    FILE *file = fopen("C:\\Users\\nicud\\Desktop\\SDA\\LAB1\\untitled2\\studenti_TI.txt", "r");
    if (file == NULL) {
        perror("Eroare la deschidere");
        return 1;
    }

    int nr_of_students = count_rows(file);

    Student *list = (Student*)malloc(nr_of_students * sizeof(Student));
    if (list == NULL) {
        perror("Eroare la alocare");
        fclose(file);
        return 1;
    }

    for (int i = 0; i < nr_of_students; i++) {
        list[i].name = (char*)malloc(50 * sizeof(char));
        if (list[i].name == NULL) {
            perror("Eroare la alocare");
            fclose(file);
            free_list(list,nr_of_students);
            return 1;
        }
        if (fscanf(file, "%s %d %d", list[i].name, &list[i].group, &list[i].age) != 3) {
            perror("Error reading Student data\n");
            fclose(file);
            free_list(list,nr_of_students);
            return 1;
        }
    }

    for (int i = 0; i < nr_of_students; i++) {
        printf("Student %d: Nume: %s, Grupa: %d, Varsta: %d\n", i + 1, list[i].name, list[i].group, list[i].age);
    }

    int choice;
    while (1) {
        printf("----------------------------------------------------");
        printf("\n1.Pentru a printa lista studentilor");
        printf("\n2.Pentru a sorta lista dupa un criteriu");
        printf("\n3.Pentru a adauga un Student la inceputul listei");
        printf("\n4.Pentru a adauga un Student la capatul listei");
        printf("\n5.Pentru a adauga un Student la o anumita pozitie");
        printf("\n6.Pentru a elimina un Student din lista dupa pozitie");
        printf("\n7.Pentru a gasi un Student dupa grupa");
        printf("\n8.Pentru a gasi un Student dupa varsta");
        printf("\n9.Pentru a gasi un Student dupa nume");
        printf("\n0.Pentru a iesi din program\n");
        printf("Alegeti o optiune:\n");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                free_list(list,nr_of_students);
                fclose(file);
                return 0;
            case 1:
                print_elements(list, nr_of_students);
                break;
            case 2: {
                int sort_choice;
                printf("Alegeti criteriul de sortare (1. Nume, 2. Grupa, 3. Varsta): ");
                scanf("%d", &sort_choice);
                switch (sort_choice) {
                    case 1:
                        sort_by_name(list, nr_of_students);
                        break;
                    case 2:
                        sort_by_group(list, nr_of_students);
                        break;
                    case 3:
                        sort_by_age(list, nr_of_students);
                        break;
                    default:
                        printf("Optiune invalida!\n");
                        break;
                }
                break;
            }
            case 3:
                insert_item_start(&list, &nr_of_students);
                break;
            case 4:
                insert_item_end(&list, &nr_of_students);
                break;
            case 5:
                insert_item_by_index(&list, &nr_of_students);
                break;
            case 6:
                delete_item_by_index(&list, &nr_of_students);
                break;

            case 7:
                printf("Introduceti grupa pentru cautare: ");
                scanf("%d", &group_to_find);
                int index_by_group = find_student_by_group(list, nr_of_students, group_to_find);
                if (index_by_group != -1) {
                    printf("Studentul gasit:\n");
                    while (index_by_group < nr_of_students && list[index_by_group].group == group_to_find) {
                        printf("Nume: %s, Grupa: %d, Varsta: %d\n", list[index_by_group].name, list[index_by_group].group, list[index_by_group].age);
                        index_by_group++;
                    }
                } else {
                    printf("Nu s-au gasit studenti in grupa %d\n", group_to_find);
                }
                break;

            case 8:
                printf("Introduceti varsta pentru cautare: ");
                scanf("%d", &age_to_find);
                int index_by_age = find_student_by_age(list, nr_of_students, age_to_find);
                if (index_by_age != -1) {
                    printf("Studentii gasiti cu varsta %d:\n", age_to_find);
                    while (index_by_age < nr_of_students && list[index_by_age].age == age_to_find) {
                        printf("Nume: %s, Grupa: %d, Varsta: %d\n", list[index_by_age].name, list[index_by_age].group, list[index_by_age].age);
                        index_by_age++;
                    }
                } else {
                    printf("Nu s-au gasit studenti cu varsta %d\n", age_to_find);
                }
                break;
            case 9:
                printf("Introduceti numele studentului cautat: ");
                scanf("%s", name_to_find);

                int index = find_student_by_name(list, nr_of_students, name_to_find);

                if (index != -1) {
                    printf("Studentul a fost gasit:\n");
                    printf("Nume: %s, Grupa: %d, Varsta: %d\n", list[index].name, list[index].group, list[index].age);
                } else {
                    printf("Studentul '%s' nu a fost gasit\n", name_to_find);
                }
                break;
            default:
                printf("Optiune invalida!\n");
                break;
        }
    }
}
