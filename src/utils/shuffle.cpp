#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

void shuffle()
{
    //Inicialização do array com as peças
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

    //Criação de um array com os index do array de peças(0 - 27) para ser embaralhado
    int randomShuffle[28];
    srand(time(NULL));
    for (int k = 0; k < 28; k++)
    {
        randomShuffle[k] = k;
    }

    //Algoritmo que embaralha os index entre (0-27) sem repetições
    for (int k = 0; k < 28; k++)
    {
        int temp = randomShuffle[k];
        int randomIndex = rand() % 27;
        randomShuffle[k] = randomShuffle[randomIndex];
        randomShuffle[randomIndex] = temp;
    }

    //Impressão do Array embaralhado
    printf("Showing Shuffled Pieces...\n");
    for (int k = 0; k < 28; k++)
    {
        printf(piecesArray[randomShuffle[k]]);
        printf(" ");
        if (k % 7 == 0 && k != 0)
            printf("\n");
    }
    printf("\n\n");
}
