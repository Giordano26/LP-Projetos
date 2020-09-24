//Grupo Shoegazer - Função Principal com lógica do jogo e inicio do mesmo.

#include "./Controller/optionController.cpp"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./View/printInterfaces.cpp"
#include "./Controller/shuffleController.cpp"
#include "./Model/Model.h"
#include "./Controller/flushController.cpp"

//Criação da mesa inicial

int playerInicio;
int game(player playerA, player playerB);


int main()
{
    while (true)
    {
        int option;
        
        printMenu();
        option = grabOption();
        
        flush_in();

        // OPÇÃO --
        if(option == 3)
            exit(1);

        // OPÇÃO --> Selecionar numero de jogadores
        else if(option == 1) {
            
          printMode();
          option = grabOptionMode();
          
          if(option == 1){
              printf("Modo em desenvolvimento....\n");
              printf("Reiniciando...\n\n");
          }
          else if(option == 2){
              printf("Modo de 2 jogadores selecionado\n\n");
              player playerA, playerB;
              
              playerA.playerNum = 1;
              playerB.playerNum = 2;
              printf("Iniciando o Jogo...\n");
              game(playerA,playerB);
              
          }
            
          flush_in();
          if(option == 3)
            continue;
        }

        // OPÇÃO --> Regras
        else if (option == 2) {
            
            printRules();
            continue;
        }
    }

    return 0;
}


void mesinhaInicial(){ //função para printar a primeira mesa 
    board mesa;
    mesa.creation = false;
    if(!mesa.creation){
        printMesaInicial();
        printf("\n\n\n");
        mesa.creation = true;
    }
       
}


int game(player playerA, player playerB){

    mesinhaInicial(); //printa a primeira mesa
     
    //gera as peças para o jogo;
        int pieceA = 0;
        int pieceB = 0;
        int count = 0;

        piece dominoPieces[28];

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
        
        for(int k = 0 ; k < 28; k++){
            dominoPieces[k].available = true;
            dominoPieces[k].inGame = false;
            dominoPieces[k].player = 0;
        }


    // gerando as peças;

    //Embaralhando as peças 

     int shuffleSideA[28]; // Array para o index randomico
     int *A;

     A = shuffle();

    for ( int i = 0; i < 28; i++ ) {
        shuffleSideA[i] = *(A + i); // Atribui os indexes randomicos a uma variavel
   }
   //Embaralhando as peças

    // Dando 7 peças aos jogadores
    for (int y = 0; y < 14; y++ ){
        if(y < 7){
            playerA.playerPieces[y] = shuffleSideA[y];
            dominoPieces[y].available = false; //Peça deixa de ser disponível
            dominoPieces[y].player = 1; // Vai para o player A
        } else {
            playerB.playerPieces[y] = shuffleSideA[y]; 
            dominoPieces[y].available = false;  //Peça deixa de ser disponível
            dominoPieces[y].player = 2; // Vai para o player B
        }
    }

    int pecaMaiorA = NULL; // Analisa as peças de cada jogador para decidir quem começa o jogo
    int pecaMaiorB = NULL;
    bool sentinelaPrimordialA,sentinelaPrimordialB = false;


    for (int y = 0; y < 14; y++ ){
        if (y < 7){
        if(dominoPieces[playerA.playerPieces[y]].sideA == dominoPieces[playerA.playerPieces[y]].sideB){
            if (dominoPieces[pecaMaiorA].sideA + dominoPieces[pecaMaiorA].sideB < dominoPieces[playerA.playerPieces[y]].sideA + dominoPieces[playerA.playerPieces[y]].sideB )
            pecaMaiorA = playerA.playerPieces[y];
        }
            
        }else if(dominoPieces[playerB.playerPieces[y]].sideA == dominoPieces[playerB.playerPieces[y]].sideB){
            if (dominoPieces[pecaMaiorB].sideA + dominoPieces[pecaMaiorB].sideB < dominoPieces[playerB.playerPieces[y]].sideA + dominoPieces[playerB.playerPieces[y]].sideB )
            pecaMaiorB = playerB.playerPieces[y];
        }
    }
    if(pecaMaiorA != NULL) //se achou uma peça gêmea ativa a sentinela
        sentinelaPrimordialA = true;

    if(pecaMaiorB != NULL) //se achou uma peça gêmea ativa a sentinela
        sentinelaPrimordialB =  true;

    //Escopo do caso onde ambos sentinelas são nulas
    if(pecaMaiorA && pecaMaiorB == NULL){

        for (int y = 0; y <14; y++ ){
        {
            if(y < 7){
                if (pecaMaiorA < dominoPieces[playerA.playerPieces[y]].sideA + dominoPieces[playerA.playerPieces[y]].sideB){

                    pecaMaiorA = playerA.playerPieces[y];
            
                }

            }

            if(y >= 7){
                 if (pecaMaiorB < dominoPieces[playerB.playerPieces[y]].sideA + dominoPieces[playerB.playerPieces[y]].sideB){

                     pecaMaiorB = playerB.playerPieces[y];
                }
            }
        }
    }

    if(dominoPieces[pecaMaiorA].sideA + dominoPieces[pecaMaiorA].sideB > dominoPieces[pecaMaiorB].sideA + dominoPieces[pecaMaiorB].sideB )
        playerInicio = 1;
    else 
        playerInicio = 2;
    } //fim do escopo do nulo

    //Caso onde nenhum é nulo, duas peças são gêmeas 
    if(sentinelaPrimordialA && sentinelaPrimordialB){

    if(dominoPieces[pecaMaiorA].sideA > dominoPieces[pecaMaiorB].sideB)
        playerInicio = 1;
    else
        playerInicio = 2;

    }else //fim do caso onde nenhum é nulo

    //caso algum seja nulo
    if(!sentinelaPrimordialA || !sentinelaPrimordialB){
        if(dominoPieces[pecaMaiorA].sideA == dominoPieces[pecaMaiorA].sideB )
            playerInicio = 1;
        else if(dominoPieces[pecaMaiorB].sideB == dominoPieces[pecaMaiorB].sideB)
            playerInicio = 2;
    } //fim do caso em que algum seja nulo;
    



       // printf("Peça Maior do jogador A é: [%d|%d]\n",dominoPieces[pecaMaiorA].sideA,dominoPieces[pecaMaiorA].sideB);
       // printf("Peça Maior do jogador B é: [%d|%d]\n",dominoPieces[pecaMaiorB].sideA,dominoPieces[pecaMaiorB].sideB);
        printf("Jogador que inicia é o Player%d \n\n",playerInicio);
    

   return 0; 
}
