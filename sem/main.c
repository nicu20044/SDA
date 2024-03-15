#include <stdio.h>
#include "functions.h"


int main() {
    read_sales_data("C:\\Users\\nicud\\Desktop\\sem\\sale.txt");

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Total revenue for a specific month and year\n");
        printf("2. Top 5 products by revenue\n");
        printf("3. Sales per category\n");
        printf("4. Cities with highest sales for a specific country\n");
        printf("5. Monthly sales trends for a specific year\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);


        switch (choice) {
            case 1: {
                int month, year;
                printf("Enter month and year (MM YYYY): ");
                scanf("%d %d", &month, &year);
                float revenue = calculate_total_revenue(month, year);
                printf("Total revenue for %d/%d: %.2f\n", month, year, revenue);
                break;
            }
            case 2:
                print_top_5_products();
                break;
            case 3: {
                char category[MAX_STRING_LENGTH];
                printf("Enter category: ");
                scanf("%s", category);
                print_sales_per_category(category);
                break;
            }
            case 4: {
                char country[MAX_STRING_LENGTH];
                printf("Enter country: ");
                scanf("%s", country);
                print_cities_with_highest_sales(country);
                break;
            }
            case 5: {
                int year;
                printf("Enter year: ");
                scanf("%d", &year);
                print_monthly_sales_trends(year);
                break;
            }
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    free_sales_data();
    return 0;
}
