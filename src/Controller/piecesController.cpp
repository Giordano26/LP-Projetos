//MVC - Control
//Grupo shoegazer - função que armazena as peças 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include "../View/printInterfaces.cpp"
#include "./shuffleController.cpp"
#include "./flushController.cpp"


    //Definição do tipo de peça
    typedef struct 
    {   
        int sideA;
        int sideB;
    } piece;




void showPieces()
{
   int shuffleIndexA[28]; //Array para o index randomico
   int *A;
   int pieceA = 0;
   int pieceB = 0;
   //contadores para printar as peças
   int count = 0;
   int countPrint = 0;
   int countPrintShuffle = 0 ;
   //contadores para printar as peças
   int option;
   bool sentinel = false; //sentinela para o menu

    piece dominoPieces[28];

    // Populate dominoPieces with  "0 | 0" "0 | 1" .... "6 | 6" 
    for (int createPiece = 0; createPiece < 7; createPiece++){
        for (int createPieceB = pieceA; createPieceB < 7; createPieceB++){
            dominoPieces[count].sideA = pieceA;
            dominoPieces[count].sideB = pieceB;

            pieceB = pieceB + 1;
            count = count + 1;
            }
        pieceA = pieceA + 1;
        pieceB = pieceA;
        }



    printf("Showing Pieces...\n");
    printf("\n\n");
    //print do array de peças 
    for (int createPiece = 0; createPiece < 4; createPiece++){
        for (int createPieceB = 0; createPieceB < 7; createPieceB++){
            printf("%d | %d\n",dominoPieces[countPrint].sideA,dominoPieces[countPrint].sideB);
            countPrint = countPrint + 1;
        }
    }
    if(countPrint == 28) //zera o contador das peças normais
        countPrint = 0;



    //Gera os indexes randomicos
    A = shuffle();
    for (int i = 0; i < 28; i++ ) {
    shuffleIndexA[i] = *(A + i); //Atribui os indexes randomicos a uma variavel
   }

    printf("Shuffle? (Y/N)\n");
    scanf("%s", &option);
    flush_in(); //função de flush do input
    printf("\n");

    if (toupper(option) == 'Y')
    {
   
    printf("Showing Shuffled Pieces...\n");
    printf("\n\n");
    //print do array de peças shufflado
    for (int createPiece = 0; createPiece < 4; createPiece++){
        for (int createPieceB = 0; createPieceB < 7; createPieceB++){
            printf("%d | %d\n",dominoPieces[shuffleIndexA[countPrintShuffle]].sideA,dominoPieces[shuffleIndexA[countPrintShuffle]].sideB);
            countPrintShuffle = countPrintShuffle + 1;
        }
    
    }
    if(countPrintShuffle == 28){ //zera o contador do shuffle
        countPrintShuffle = 0;
    }
    sentinel = true;
    }
    else if (toupper(option) == 'N')
    {
    }

    if(sentinel){ //sentinela para averiguar se houve ou não shuffle das peças
        printf("Back to normal? (Y/N)\n");
        getchar();
        flush_in();
        printf("\n");
    }

    if (toupper(option) == 'Y') //"volta" as peças ao normal
    {
    for (int createPiece = 0; createPiece < 4; createPiece++){
        for (int createPieceB = 0; createPieceB < 7; createPieceB++){
            printf("%d | %d\n",dominoPieces[countPrint].sideA,dominoPieces[countPrint].sideB);
            countPrint = countPrint + 1;
        }
    }
    if(countPrint == 28) //zera contador de print das peças
        countPrint = 0;

    printf("\n\n Restarting... \n\n");    
    }else if(toupper(option) == 'N')
        printf("\n\n Restarting \n\n");

   
    
}