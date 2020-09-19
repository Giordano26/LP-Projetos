//MVC - Control
//Grupo shoegazer - função que armazena as peças 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "../View/printInterfaces.cpp"
#include "./arrayLoop.cpp"
#include "./shuffle.cpp"
#include "./flushBuffer.cpp"

void showPieces()
{

    typedef struct 
    {   
        int sideA;
        int sideB;
    } piece;

    int pieceA = 0;
    int pieceB = 0;

    int count = 0;

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

    int countPrint = 0;

    printf("Showing Pieces...\n");
    //inicialização do array de peças 
    for (int createPiece = 0; createPiece < 4; createPiece++){
        for (int createPieceB = 0; createPieceB < 7; createPieceB++){
            printf("%d | %d\n",dominoPieces[countPrint].sideA,dominoPieces[countPrint].sideB);
            countPrint = countPrint + 1;
        }
    }
}