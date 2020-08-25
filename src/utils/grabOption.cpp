#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int grabOption()
{
    int option;
    do
    {
        printf("\nChoose an option: \n");
        scanf("%d", &option);
        if (option == 1 || option == 6)
            break;
        else
            continue;
    } while (true);
    printf("\n");
    return option;
}
