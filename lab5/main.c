#include <stdio.h>

#include "func.h"

int main()
{
    int n,number;

    do {
        printf("1.Problem 1\n");
        printf("2.Problem 2\n");
        printf("3.Problem 3\n");
        printf("4.Exit\n");
        printf("Choose the problem\n");
        scanf("%d", &n);

        switch (n) {
            case 1:
                problem_1();
                break;
            case 2:
                problem_2();
                break;
            case 3:
                printf("Enter the position of the fibonacci element\n ");
                scanf("%d", &number);
                calculate_fibonacci(number);
                break;
            case 4:
                printf("Exit\n");
                return 0;
            default:
                printf("Invalid option\n");
        }
    } while (n != 4);


    return 0;

}



