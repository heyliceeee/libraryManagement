#include <stdio.h>
#include "books.h"

int main()
{
    int option;
    Books books = {.count = 0};

    do
    {
        setbuf(stdout, 0);
        printf("\nBooks------------------------------------------------------------");
        printf("\n1 - Insert");
        printf("\n2 - Show Books");
        printf("\n3 - Show Authors");
        printf("\n4 - Show Publish Companies");
        printf("\n0 - Close");
        printf("\n---------------------------------------------------------------------");

        printf("\nBooks: %d/%d", books.count, MAX_BOOKS);

        printf("\nOption: ");
        scanf("%d", &option);


        switch (option)
        {
            case 0:
                break;

            case 1:
                insertBooks(&books);
                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                break;

            default:
                printf("\nInvalid option");
        }

    } while (option != 0);


    return 0;
}
