#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "../utils/printMenu.cpp"
#include "../utils/arrayLoop.cpp"
#include "../utils/shuffle.cpp"

void showPieces()
{
    int boleano = 0;
    char option;
    char piecesArray[28][3] = {
        "00",
        "01",
        "02",
        "03",
        "04",
        "05",
        "06",
        "11",
        "12",
        "13",
        "14",
        "15",
        "16",
        "22",
        "23",
        "24",
        "25",
        "26",
        "33",
        "34",
        "35",
        "36",
        "44",
        "45",
        "46",
        "55",
        "56",
        "66",
    };

    printf("Showing Pieces...\n");
    arrayLoop(piecesArray);

    printf("\n\n");

    printf("Shuffle? (Y/N)\n");
    scanf("%s", &option);
    flush_in();

    printf("\n");

    if (toupper(option) == 'Y')
    {
        shuffle();
        boleano = 1;
    }
    else if (toupper(option) == 'N')
    {
    }

    if (boleano == 1)
    {
        printf("Back to normal? (Y/N)\n");
        scanf("%s", &option);
        flush_in();
        
        printf("\n");

        if (toupper(option) == 'Y')
        {
            arrayLoop(piecesArray);
            printf("\n Restarting \n");

            boleano = 0;
        }
        else if (toupper(option) == 'N')
            printf("\n Restarting \n");
    }
}