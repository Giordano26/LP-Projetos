//MVC - Control
//Grupo shoegazer - função que armazena as peças 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "../utils/printInterfaces.cpp"
#include "../utils/arrayLoop.cpp"
#include "../utils/shuffle.cpp"
#include "../utils/flushBuffer.cpp"

void showPieces()
{
    int boleano = 0; //ini booleano
    char option;

    //inicialização do array de peças 
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
    arrayLoop(piecesArray); //função que printa o array

    printf("\n\n");

    printf("Shuffle? (Y/N)\n");
    scanf("%s", &option);
    flush_in(); //função de flush do input

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
        getchar();
        flush_in();
        
        printf("\n");

        if (toupper(option) == 'Y')
        {
            arrayLoop(piecesArray);
            printf("\n\n Restarting \n\n");

            boleano = 0;
        }
        else if (toupper(option) == 'N')
            printf("\n\n Restarting \n\n");
    }
}