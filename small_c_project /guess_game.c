#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    printf("Welcome to guess number game.\n");

    // printf("%s%i","U entered : ",num);

    // print random number
    srand(time(NULL));

    // Generate a random number between 1 and 10 (not 0-9)
    int random_number = (rand() % 10) + 1;

    // printf("Random number: %d\n", random_number);

    int a = 0;
    while (a != 1)
    {

        int num;

        printf("%s", "Enter the number : ");

        if (scanf("%d", &num) != 1) // 1 detect is it num or string
        {
            printf("Enter number only\n");

            break; // exit loop on invalid input
        }

        if (num == random_number)
        {
            printf("%s", "U guess the correct number\n");
            a++;
        }
        else if (num > random_number)
        {
            printf("%s%d%s", "Enter small number then ", num, "\n");
        }
        else if (num < random_number)
        {
            printf("%s%d%s", "Enter big number then ", num, "\n");
        }
    }
}
