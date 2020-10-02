#include "../View/optionController.c"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../View/printInterfaces.c"
#include "./shuffleController.c"
#include "../Model/Model.h"
#include "./flushController.c"
#include <ctype.h>



  char str[1000];
  char str2[1000];

int playerInicio,playerSecundario;
char megaOption;


int game(player playerA, player playerB){

    
     //variaveis de comparação:
        int timeShiftC_ladoA = 0; 
        int timeShiftC_ladoB = 0;

        int timeShiftF_ladoA = 0;
        int timeShiftF_ladoB = 0; 

        int validador = 0;
        int validador2 = 0;
        bool pavement = false;

        bool bilola = false;

    //gera as peças para o jogo;
        int pieceA = 0;
        int pieceB = 0;
        int count = 0;

    //variaveis para a mesa;
        char mesaIndex[168];
        bool mesaBool[168];
        int mesaCounter;
        int mesaCounter2;

    //Estado dos jogadores
    bool playerIni = true;
    bool playerSec = false;
        

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

    // Dando 7 peças aos jogadores --> playerPieces 
    for (int y = 0; y < 7; y++ ){
            playerA.playerPieces[y] = shuffleSideA[y];
            dominoPieces[y].available = false; //Peça deixa de ser disponível
            dominoPieces[y].player = 1; // Vai para o player A
    }
    for(int y = 0; y < 7; y++){
            playerB.playerPieces[y] = shuffleSideA[y+7]; 
            dominoPieces[y+7].available = false;  //Peça deixa de ser disponível
            dominoPieces[y+7].player = 2; // Vai para o player B
    }

    int playerA_Piece_Count = 7; // Primeira posição com index vazio para peça
    int playerB_Piece_Count = 7; // Primeira posição com index vazio para peça


    int pecaMaiorA = '\0'; // Analisa as peças de cada jogador para decidir quem começa o jogo
    int pecaMaiorB = '\0';
    bool sentinelaPrimordialA,sentinelaPrimordialB = false;


    for (int y = 0; y < 7; y++ ){

        if(dominoPieces[playerA.playerPieces[y]].sideA == dominoPieces[playerA.playerPieces[y]].sideB){
            if (dominoPieces[pecaMaiorA].sideA + dominoPieces[pecaMaiorA].sideB < dominoPieces[playerA.playerPieces[y]].sideA + dominoPieces[playerA.playerPieces[y]].sideB )
                pecaMaiorA = playerA.playerPieces[y];
        }
    }

    for(int y = 0; y < 7; y++){
        if(dominoPieces[playerB.playerPieces[y]].sideA == dominoPieces[playerB.playerPieces[y]].sideB){
            if (dominoPieces[pecaMaiorB].sideA + dominoPieces[pecaMaiorB].sideB < dominoPieces[playerB.playerPieces[y]].sideA + dominoPieces[playerB.playerPieces[y]].sideB )
                pecaMaiorB = playerB.playerPieces[y];
    }
    }


    
    if(pecaMaiorA !=  '\0') //se achou uma peça gêmea ativa a sentinela
        sentinelaPrimordialA = true;

    if(pecaMaiorB !=  '\0') //se achou uma peça gêmea ativa a sentinela
        sentinelaPrimordialB =  true;

    //Escopo do caso onde ambos sentinelas são nulas
    if(pecaMaiorA && pecaMaiorB ==  '\0'){

        for (int y = 0; y <7; y++ ){
        
                if (pecaMaiorA < dominoPieces[playerA.playerPieces[y]].sideA + dominoPieces[playerA.playerPieces[y]].sideB){
                    pecaMaiorA = playerA.playerPieces[y];
            }
        }
        for(int y = 0; y < 7; y++){
            if (pecaMaiorB < dominoPieces[playerB.playerPieces[y]].sideA + dominoPieces[playerB.playerPieces[y]].sideB){
                pecaMaiorB = playerB.playerPieces[y];
            }
        }

    if(dominoPieces[pecaMaiorA].sideA + dominoPieces[pecaMaiorA].sideB > dominoPieces[pecaMaiorB].sideA + dominoPieces[pecaMaiorB].sideB ){
        playerInicio = 1;
        playerSecundario = 2;
    }
    else {
        playerInicio = 2;
        playerSecundario = 1;
    }
    } //fim do escopo do nulo

    //Caso onde nenhum é nulo, duas peças são gêmeas 
    if(sentinelaPrimordialA && sentinelaPrimordialB){

    if(dominoPieces[pecaMaiorA].sideA > dominoPieces[pecaMaiorB].sideB){
        playerInicio = 1;
        playerSecundario = 2;
    }
    else{
        playerInicio = 2;
        playerSecundario = 1;
    }

    }else //fim do caso onde nenhum é nulo

    //caso algum seja nulo
    if(!sentinelaPrimordialA || !sentinelaPrimordialB){
        if(dominoPieces[pecaMaiorA].sideA == dominoPieces[pecaMaiorA].sideB ){
            playerInicio = 1;
            playerSecundario = 2;
        }
        else if(dominoPieces[pecaMaiorB].sideA == dominoPieces[pecaMaiorB].sideB){
            playerInicio = 2;
            playerSecundario = 1;
        }
    } //fim do caso em que algum seja nulo;


    //gerar a mesa

    for(int lin = 0; lin <= 168; lin++){
        mesaIndex[lin] = ' ';
        mesaBool[lin] = true;
    }
    bool solucaoMacaca = false;


        
        showMessage(          
                   " ░██████╗██╗░░██╗░█████╗░███████╗░██████╗░░█████╗░███████╗███████╗██████╗░\n"
                   " ██╔════╝██║░░██║██╔══██╗██╔════╝██╔════╝░██╔══██╗╚════██║██╔════╝██╔══██╗\n"
                   " ╚█████╗░███████║██║░░██║█████╗░░██║░░██╗░███████║░░███╔═╝█████╗░░██████╔╝\n"
                   " ░╚═══██╗██╔══██║██║░░██║██╔══╝░░██║░░╚██╗██╔══██║██╔══╝░░██╔══╝░░██╔══██╗\n"
                   " ██████╔╝██║░░██║╚█████╔╝███████╗╚██████╔╝██║░░██║███████╗███████╗██║░░██║\n"
                   " ╚═════╝░╚═╝░░╚═╝░╚════╝░╚══════╝░╚═════╝░╚═╝░░╚═╝╚══════╝╚══════╝╚═╝░░╚═╝\n"
                                                                           );

                    
            showMessage(" -------------------------------- BETA V2.0 ---------------------------------\n\n");

            
            // Mostra quem é o primeiro e o segundo a jogar
            firstToPlay(playerInicio,playerSecundario);



        
        while(true){
            int option;
            
            int newPiece;

            
            while(playerIni){

            printInGameMenu(playerInicio);
            option = grabOptionInGame();
            
            switch(option){  
                case 1:
                showMessage("MESA:\n");
                mesaCounter2 = 0;
                    if(solucaoMacaca)
                        printf("[");
                for(int lin = 0; lin <= 168  ; lin++){
                    printf("%c",mesaIndex[lin]);
                    if(mesaCounter2 == 84)
                        printf("\n");
                    mesaCounter2++;

                    };
                    printf("\n");
                continue;

                //Caso mostrar peças
                case 2:
                if(1 == playerInicio){ //checa se é jogador A 
                    for(int k = 0 ; k < playerA_Piece_Count; k++){
                        showPlayerPieces(dominoPieces[playerA.playerPieces[k]].sideA,dominoPieces[playerA.playerPieces[k]].sideB);
                   }
                   
                    printf("\n");
                }else{
                    
                    for(int k = 0 ; k < playerB_Piece_Count; k++){
                        showPlayerPieces(dominoPieces[playerB.playerPieces[k]].sideA,dominoPieces[playerB.playerPieces[k]].sideB);
                   }
                    printf("\n");
                }
                continue;

                //Caso comprar peças
                case 3:
                for(int k = 14; k < 28; k++){ //Função para o jogador comprar uma peça
                    if(dominoPieces[k].available  == true){
                        newPiece = k;
                        dominoPieces[k].available = false;
                        printf("Próxima posição válida = %d\n",k); 
                        break;
                    }else 
                        continue;
            }
                if (1 == playerInicio){ // Checa se é Jogador A
            
                playerA.playerPieces[playerA_Piece_Count] = shuffleSideA[newPiece]; //Pega o index de peça disponivel, acessa no array de peças embaralhadas e atribui ao jogador na primeira posição disponivel.

                dominoPieces[newPiece].available = false; // Peça deixa de ser disponível

                dominoPieces[newPiece].player = 1; // Vai para o player A

                purchasedPiece(dominoPieces[playerA.playerPieces[playerA_Piece_Count]].sideA,dominoPieces[playerA.playerPieces[playerA_Piece_Count]].sideB);


                playerA_Piece_Count = playerA_Piece_Count + 1; // Move 1 na posição do proximo index valido

                } else if(2 == playerInicio) {
                    
                playerB.playerPieces[playerB_Piece_Count] = shuffleSideA[newPiece]; // Pega o index de peça disponivel, acessa no array de peças embaralhadas e atribui ao jogador na primeira posição disponivel.

                dominoPieces[newPiece].available = false; // Peça deixa de ser disponível

                dominoPieces[newPiece].player = 2; // Vai para o player B

                 purchasedPiece(dominoPieces[playerB.playerPieces[playerB_Piece_Count]].sideA,dominoPieces[playerB.playerPieces[playerB_Piece_Count]].sideB);

                playerB_Piece_Count = playerB_Piece_Count + 1; // move 1 na posição do proximo index valido
                }
               
                continue;

                case 4:
                if(playerInicio == 1){
                do {
                printf("Escolha uma peça de 0 a %d\n",playerA_Piece_Count-1);
                scanf("%d",&option);
                flush_in();
                if(option < 0 || option > playerA_Piece_Count){
                    //scanf("%d",&option);
                    showMessage("Peça inválida...\n");
                    continue;
                }else
                    break;

                }while(true); //invalidar a peça, mudar on table para true e available false
                //printf("Peça jogada: [%d|%d] foi jogada\n",dominoPieces[playerA.playerPieces[option]].sideA,dominoPieces[playerA.playerPieces[option]].sideB);



                megaOption = grabOptionBoard(); //opção começo ou fim?
                mesaCounter = 0; //contador para quebrar a atribuição em partes
                if(toupper(megaOption) == 'C'){

                    if (validador > 0) {
                        if (timeShiftC_ladoB == dominoPieces[playerA.playerPieces[option]].sideB && timeShiftC_ladoB != dominoPieces[playerA.playerPieces[option]].sideA )
                            {
                                bilola = true; 
                                pavement = true;
                                
                                timeShiftC_ladoA = dominoPieces[playerA.playerPieces[option]].sideB;
                                timeShiftC_ladoB = dominoPieces[playerA.playerPieces[option]].sideA;
                                
                            }else{
                                    timeShiftC_ladoA = dominoPieces[playerA.playerPieces[option]].sideA;
                                    timeShiftC_ladoB = dominoPieces[playerA.playerPieces[option]].sideB;
                            }
                         if (timeShiftC_ladoB != dominoPieces[playerA.playerPieces[option]].sideA || timeShiftC_ladoB != dominoPieces[playerA.playerPieces[option]].sideB && bilola == false ){
                            printf("VC BURRO NAO JOGAR PEÇAS CORRETAS QUEBRAR JOGO DESTE MODO\n");
                            bilola = false;
                            continue;
                                                                                                                 
                        }
                    }else{
                        timeShiftC_ladoA = dominoPieces[playerA.playerPieces[option]].sideA;
                        timeShiftC_ladoB = dominoPieces[playerA.playerPieces[option]].sideB;
                    }
                    validador++;

                    printf(" MEU NEGRO JOGOU ESTA PEÇA E ELA EM BREVE SERA VALIDADE ->>> [%d|%d]\n",timeShiftC_ladoA,timeShiftC_ladoB );

        
                    for(int k = 0; k <= 168; k++){ //começa percorrer o array pelo começo
                        if(mesaBool[k] == true){
                            if(mesaCounter == 0){ //vai colocando em partes a peça no array da mesa
                                mesaIndex[k] = '[';
                                mesaBool[k] = false;
                                mesaCounter++;
                            }
                            else if(mesaCounter == 1){
                                if(pavement){
                                sprintf(str, "%d", dominoPieces[playerA.playerPieces[option]].sideB);
                                mesaIndex[k] = *str;
                                mesaBool[k] = false;
                                mesaCounter++;
                                }else{
                                sprintf(str, "%d", dominoPieces[playerA.playerPieces[option]].sideA);
                                mesaIndex[k] = *str;
                                mesaBool[k] = false;
                                mesaCounter++;

                                }
                            }
                            else if(mesaCounter == 2){
                                mesaIndex[k] = '|';
                                mesaBool[k] = false;
                                mesaCounter++;
                            }else if(mesaCounter == 3){
                                if(pavement){
                                sprintf(str, "%d", dominoPieces[playerA.playerPieces[option]].sideA);
                                mesaIndex[k] = *str;
                                mesaBool[k] = false;
                                mesaCounter++;
                                pavement = false;
                                }else{
                                sprintf(str, "%d", dominoPieces[playerA.playerPieces[option]].sideB);
                                mesaIndex[k] = *str;
                               // mesaIndex[k] = dominoPieces[playerA.playerPieces[option]].sideB;
                                mesaBool[k] = false;
                                mesaCounter++;
                                }
                            }else if(mesaCounter == 4){
                                mesaIndex[k] = ']';
                                mesaBool[k] = false;
                                mesaCounter++;
                            }else if(mesaCounter == 5){
                                mesaIndex[k] = ' ';
                                mesaBool[k] = false;
                                mesaCounter++;
                            }
                        }
                    }
                }else if(toupper(megaOption) == 'F'){

                if (validador2 > 0) {
                    if (timeShiftF_ladoB == dominoPieces[playerA.playerPieces[option]].sideB && timeShiftF_ladoB != dominoPieces[playerA.playerPieces[option]].sideA )
                            {
                                pavement = true;
                                bilola = true;
                                
                                timeShiftF_ladoA = dominoPieces[playerA.playerPieces[option]].sideB;
                                timeShiftF_ladoB = dominoPieces[playerA.playerPieces[option]].sideA;
                                
                            }else{
                                    timeShiftF_ladoA = dominoPieces[playerA.playerPieces[option]].sideA;
                                    timeShiftF_ladoB = dominoPieces[playerA.playerPieces[option]].sideB;
                            }
                         if (timeShiftF_ladoA != dominoPieces[playerA.playerPieces[option]].sideB || timeShiftF_ladoA != dominoPieces[playerA.playerPieces[option]].sideA && bilola == false ){
                            printf("VC BURRO NAO JOGAR PEÇAS CORRETAS QUEBRAR JOGO DESTE MODO\n");
                            bilola = false;
                            continue;
                                                                                                        
                        }
                    }else{
                        timeShiftF_ladoA = dominoPieces[playerA.playerPieces[option]].sideA;
                        timeShiftF_ladoB = dominoPieces[playerA.playerPieces[option]].sideB;
                    }
                    validador2++;

                    printf(" MEU NEGRO JOGOU ESTA PEÇA E ELA EM BREVE SERA VALIDADE ->>> [%d|%d]\n",timeShiftF_ladoA,timeShiftF_ladoB );


                    for(int k = 168; k >= 0 ; k--){
                        if(mesaBool[k] == true){
                            if(mesaCounter == 0){
                                mesaIndex[k] = ']';
                                mesaBool[k] = false;
                                mesaCounter++;
                            }
                            else if(mesaCounter == 1){
                                if(pavement){
                                sprintf(str, "%d", dominoPieces[playerA.playerPieces[option]].sideA);
                                mesaIndex[k] = *str;
                                //mesaIndex[k] = dominoPieces[playerA.playerPieces[option]].sideB;
                                mesaBool[k] = false;
                                mesaCounter++;
                                }else{
                                sprintf(str, "%d", dominoPieces[playerA.playerPieces[option]].sideB);
                                mesaIndex[k] = *str;
                                //mesaIndex[k] = dominoPieces[playerA.playerPieces[option]].sideB;
                                mesaBool[k] = false;
                                mesaCounter++;
                                }
                            }
                            else if(mesaCounter == 2){
                                mesaIndex[k] = '|';
                                mesaBool[k] = false;
                                mesaCounter++;
                            }else if(mesaCounter == 3){
                                if(pavement){
                                sprintf(str, "%d", dominoPieces[playerA.playerPieces[option]].sideB);
                                mesaIndex[k] = *str;
                                //mesaIndex[k] = dominoPieces[playerA.playerPieces[option]].sideB;
                                mesaBool[k] = false;
                                mesaCounter++;
                                pavement = false;
                                }else{
                                sprintf(str, "%d", dominoPieces[playerA.playerPieces[option]].sideA);
                                mesaIndex[k] = *str;
                                //mesaIndex[k] = dominoPieces[playerA.playerPieces[option]].sideB;
                                mesaBool[k] = false;
                                mesaCounter++;
                                }
                            }else if(mesaCounter == 4){
                                mesaIndex[k] = '[';
                                mesaBool[k] = false;
                                mesaCounter++;
                            }else if(mesaCounter == 5){
                                mesaIndex[k] = ' ';
                                mesaBool[k] = false;
                                mesaCounter++;
                            }

                        }
                    }
                    solucaoMacaca = true;
                };

                for(int k = option; k < playerA_Piece_Count; k++){ // Algoritmo que joga todo o array pra esquerda
                    dominoPieces[playerA.playerPieces[k]].sideA = dominoPieces[playerA.playerPieces[k+1]].sideA;
                    dominoPieces[playerA.playerPieces[k]].sideB = dominoPieces[playerA.playerPieces[k+1]].sideB;
                }
                dominoPieces[playerA.playerPieces[playerA_Piece_Count-1]].sideA = '\0';
                dominoPieces[playerA.playerPieces[playerA_Piece_Count-1]].sideB = '\0';
                playerA_Piece_Count--;
                dominoPieces[playerA.playerPieces[option]].inGame = true; // Status da peça em jogo
                }
                 if(playerInicio == 2){ 
                do{
                printf("Escolha uma peça de 0 a %d\n",playerB_Piece_Count-1); // Modularizar para o view
                scanf("%d",&option);
                flush_in();
                if(option < 0 || option > playerB_Piece_Count){
                    //scanf("%d",&option);
                    showMessage("Peça inválida...\n");
                    continue;
                }else
                    break;

                }while(true); //invalidar a peça, mudar on table para true e available false
                //printf("Peça jogada: [%d|%d] foi jogada\n",dominoPieces[playerA.playerPieces[option]].sideA,dominoPieces[playerA.playerPieces[option]].sideB);
                megaOption = grabOptionBoard(); //opção começo ou fim?
                mesaCounter = 0; //contador para quebrar a atribuição em partes
                if(toupper(megaOption) == 'C'){
                   
                    if (validador > 0) {
                        if (timeShiftC_ladoB == dominoPieces[playerB.playerPieces[option]].sideB && timeShiftC_ladoB != dominoPieces[playerB.playerPieces[option]].sideA )
                            {
                                bilola = true; 
                                pavement = true;
                                
                                timeShiftC_ladoA = dominoPieces[playerB.playerPieces[option]].sideB;
                                timeShiftC_ladoB = dominoPieces[playerB.playerPieces[option]].sideA;
                                
                            }else{
                                    timeShiftC_ladoA = dominoPieces[playerB.playerPieces[option]].sideA;
                                    timeShiftC_ladoB = dominoPieces[playerB.playerPieces[option]].sideB;
                            }
                         if (timeShiftC_ladoB != dominoPieces[playerB.playerPieces[option]].sideA || timeShiftC_ladoB != dominoPieces[playerB.playerPieces[option]].sideB && bilola == false ){
                            printf("VC BURRO NAO JOGAR PEÇAS CORRETAS QUEBRAR JOGO DESTE MODO\n");
                            bilola = false;
                            continue;
                                                                                                                 
                        }
                    }else{
                        timeShiftC_ladoA = dominoPieces[playerB.playerPieces[option]].sideA;
                        timeShiftC_ladoB = dominoPieces[playerB.playerPieces[option]].sideB;
                    }
                    validador++;

                    printf("%d %d", timeShiftC_ladoA,timeShiftC_ladoB );
                    printf(" MEU NEGRO JOGOU ESTA PEÇA E ELA EM BREVE SERA VALIDADE ->>> [%d|%d]\n",timeShiftC_ladoA,timeShiftC_ladoB );

                    //dampé ta aqui pra baixo
                    for(int k = 0; k <= 168; k++){ //começa percorrer o array pelo começo
                        if(mesaBool[k] == true){
                            if(mesaCounter == 0){ //vai colocando em partes a peça no array da mesa
                                mesaIndex[k] = '[';
                                mesaBool[k] = false;
                                mesaCounter++;
                            }
                            else if(mesaCounter == 1){
                                if(pavement){
                                sprintf(str, "%d", dominoPieces[playerB.playerPieces[option]].sideB);
                                mesaIndex[k] = *str;
                                mesaBool[k] = false;
                                mesaCounter++;
                                }else{
                                sprintf(str, "%d", dominoPieces[playerB.playerPieces[option]].sideA);
                                mesaIndex[k] = *str;
                                mesaBool[k] = false;
                                mesaCounter++;

                                }
                            }
                            else if(mesaCounter == 2){
                                mesaIndex[k] = '|';
                                mesaBool[k] = false;
                                mesaCounter++;
                            }else if(mesaCounter == 3){
                                if(pavement){
                                sprintf(str, "%d", dominoPieces[playerB.playerPieces[option]].sideA);
                                mesaIndex[k] = *str;
                                mesaBool[k] = false;
                                mesaCounter++;
                                pavement = false;
                                }else{
                                sprintf(str, "%d", dominoPieces[playerB.playerPieces[option]].sideB);
                                mesaIndex[k] = *str;
                                mesaBool[k] = false;
                                mesaCounter++;
                                }
                            }else if(mesaCounter == 4){
                                mesaIndex[k] = ']';
                                mesaBool[k] = false;
                                mesaCounter++;
                            }else if(mesaCounter == 5){
                                mesaIndex[k] = ' ';
                                mesaBool[k] = false;
                                mesaCounter++;
                            }

                        }
                    }
                }else if(toupper(megaOption) == 'F'){
                if (validador2 > 0) {
                    if (timeShiftF_ladoB == dominoPieces[playerB.playerPieces[option]].sideB && timeShiftF_ladoB != dominoPieces[playerB.playerPieces[option]].sideA )
                            {
                                pavement = true;
                                bilola = true;
                                
                                timeShiftF_ladoA = dominoPieces[playerB.playerPieces[option]].sideB;
                                timeShiftF_ladoB = dominoPieces[playerB.playerPieces[option]].sideA;
                                
                            }else{
                                    timeShiftF_ladoA = dominoPieces[playerB.playerPieces[option]].sideA;
                                    timeShiftF_ladoB = dominoPieces[playerB.playerPieces[option]].sideB;
                            }
                         if (timeShiftF_ladoA != dominoPieces[playerB.playerPieces[option]].sideB || timeShiftF_ladoA != dominoPieces[playerB.playerPieces[option]].sideA && bilola == false ){
                            printf("VC BURRO NAO JOGAR PEÇAS CORRETAS QUEBRAR JOGO DESTE MODO\n");
                            bilola = false;
                            continue;
                                                                                                        
                        }
                    }else{
                        timeShiftF_ladoA = dominoPieces[playerB.playerPieces[option]].sideA;
                        timeShiftF_ladoB = dominoPieces[playerB.playerPieces[option]].sideB;
                    }
                    validador2++;

                    printf(" MEU NEGRO JOGOU ESTA PEÇA E ELA EM BREVE SERA VALIDADE ->>> [%d|%d]\n",timeShiftF_ladoA,timeShiftF_ladoB );


                    for(int k = 168; k >= 0 ; k--){
                        if(mesaBool[k] == true){
                            if(mesaCounter == 0){
                                mesaIndex[k] = ']';
                                mesaBool[k] = false;
                                mesaCounter++;
                            }
                            else if(mesaCounter == 1){
                                if(pavement){
                                sprintf(str, "%d", dominoPieces[playerB.playerPieces[option]].sideA);
                                mesaIndex[k] = *str;
                                //mesaIndex[k] = dominoPieces[playerB.playerPieces[option]].sideB;
                                mesaBool[k] = false;
                                mesaCounter++;

                                }else{
                                sprintf(str, "%d", dominoPieces[playerB.playerPieces[option]].sideB);
                                mesaIndex[k] = *str;
                                //mesaIndex[k] = dominoPieces[playerB.playerPieces[option]].sideB;
                                mesaBool[k] = false;
                                mesaCounter++;
                                }
                            }
                            else if(mesaCounter == 2){
                                mesaIndex[k] = '|';
                                mesaBool[k] = false;
                                mesaCounter++;
                            }else if(mesaCounter == 3){
                                if(pavement){
                                sprintf(str, "%d", dominoPieces[playerB.playerPieces[option]].sideB);
                                mesaIndex[k] = *str;
                                mesaBool[k] = false;
                                mesaCounter++;
                                pavement = false;
                                }else{
                                sprintf(str, "%d", dominoPieces[playerB.playerPieces[option]].sideA);
                                mesaIndex[k] = *str;
                                mesaBool[k] = false;
                                mesaCounter++;

                                }
                            }else if(mesaCounter == 4){
                                mesaIndex[k] = '[';
                                mesaBool[k] = false;
                                mesaCounter++;
                            }else if(mesaCounter == 5){
                                mesaIndex[k] = ' ';
                                mesaBool[k] = false;
                                mesaCounter++;
                            }

                        }
                    }
                    solucaoMacaca = true;
                };

                for(int k = option; k < playerA_Piece_Count; k++){ //algoritmo que joga todo o array pra esquerda
                    dominoPieces[playerB.playerPieces[k]].sideA = dominoPieces[playerB.playerPieces[k+1]].sideA;
                    dominoPieces[playerB.playerPieces[k]].sideB = dominoPieces[playerB.playerPieces[k+1]].sideB;
                }
                dominoPieces[playerB.playerPieces[playerB_Piece_Count-1]].sideA = '\0';
                dominoPieces[playerB.playerPieces[playerB_Piece_Count-1]].sideB = '\0';
                playerB_Piece_Count--;
                dominoPieces[playerB.playerPieces[option]].inGame = true; //status da peça em jogo
                }
                break; 

                //Imprime as regras
                case 5:
                printRules();
                continue;

                case 6:
                exit(1);
                // Sai do jogo 
                break;
            }
                clearScreen();
                playerSec = true;
                playerIni = false;
            }



            

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------






            while(playerSec){

            printInGameMenu(playerSecundario);
            option = grabOptionInGame();
            flush_in();
            
            switch(option){  
                case 1:
                showMessage("MESA:\n");
                mesaCounter2 = 0;
                    if(solucaoMacaca)
                        printf("[");
                for(int lin = 0; lin <= 168  ; lin++){
                    printf("%c",mesaIndex[lin]);
                    if(mesaCounter2 == 84)
                        printf("\n");
                    mesaCounter2++;

                    };
                    printf("\n");
                    continue;

                //Caso mostrar peças
                case 2:
                if(1 == playerSecundario){ //checa se é jogador A 
                    for(int k = 0 ; k < playerA_Piece_Count; k++){
                        showPlayerPieces(dominoPieces[playerA.playerPieces[k]].sideA,dominoPieces[playerA.playerPieces[k]].sideB);
                   }
                   
                    printf("\n");
                }else{
                    
                    for(int k = 0 ; k < playerB_Piece_Count; k++){
                        showPlayerPieces(dominoPieces[playerB.playerPieces[k]].sideA,dominoPieces[playerB.playerPieces[k]].sideB);
                   }
                    printf("\n");
                }
                    continue; //solução primata porém é oq temos para hj

                //Caso comprar peças
                case 3:
                for(int k = 14; k < 28; k++){ //Função para o jogador comprar uma peça
                    if(dominoPieces[k].available  == true){
                        newPiece = k;
                        dominoPieces[k].available = false;
                        printf("Próxima posição válida = %d\n",k);
                        break;
                    }else 
                        continue;
            }
                if (1 == playerSecundario){ //checa se é Jogador A
            
                playerA.playerPieces[playerA_Piece_Count] = shuffleSideA[newPiece]; //Pega o index de peça disponivel, acessa no array de peças embaralhadas e atribui ao jogador na primeira posição disponivel.

                dominoPieces[newPiece].available = false; //Peça deixa de ser disponível

                dominoPieces[newPiece].player = 1; // Vai para o player A

                purchasedPiece(dominoPieces[playerA.playerPieces[playerA_Piece_Count]].sideA,dominoPieces[playerA.playerPieces[playerA_Piece_Count]].sideB);

                playerA_Piece_Count = playerA_Piece_Count + 1; // move 1 na posição do proximo index valido

                } else if(2 == playerSecundario) {
                    
                playerB.playerPieces[playerB_Piece_Count] = shuffleSideA[newPiece]; //Pega o index de peça disponivel, acessa no array de peças embaralhadas e atribui ao jogador na primeira posição disponivel.

                dominoPieces[newPiece].available = false; //Peça deixa de ser disponível

                dominoPieces[newPiece].player = 2; // Vai para o player B

                purchasedPiece(dominoPieces[playerB.playerPieces[playerB_Piece_Count]].sideA,dominoPieces[playerB.playerPieces[playerB_Piece_Count]].sideB);

                playerB_Piece_Count = playerB_Piece_Count + 1; // move 1 na posição do proximo index valido
                }
               
                    continue; //solução primata porém é oq temos pra hj

                case 4:
                if(playerSecundario == 1){
                do{
                printf("Escolha uma peça de 0 a %d\n",playerA_Piece_Count-1);
                scanf("%d",&option);
                flush_in();
                if(option < 0 || option > playerA_Piece_Count){
                    //scanf("%d",&option);
                    showMessage("Peça inválida...\n");
                    continue;
                }else
                    break;

                }while(true); //invalidar a peça, mudar on table para true e available false
                //printf("Peça jogada: [%d|%d] foi jogada\n",dominoPieces[playerA.playerPieces[option]].sideA,dominoPieces[playerA.playerPieces[option]].sideB);
                megaOption = grabOptionBoard(); //opção começo ou fim?
                mesaCounter = 0; //contador para quebrar a atribuição em partes


                if(toupper(megaOption) == 'C'){

                    if (validador > 0) {
                        if (timeShiftC_ladoB == dominoPieces[playerA.playerPieces[option]].sideB && timeShiftC_ladoB != dominoPieces[playerA.playerPieces[option]].sideA )
                            {
                                bilola = true; 
                                pavement = true;
                                
                                timeShiftC_ladoA = dominoPieces[playerA.playerPieces[option]].sideB;
                                timeShiftC_ladoB = dominoPieces[playerA.playerPieces[option]].sideA;
                                
                            }else{
                                    timeShiftC_ladoA = dominoPieces[playerA.playerPieces[option]].sideA;
                                    timeShiftC_ladoB = dominoPieces[playerA.playerPieces[option]].sideB;
                            }
                         if (timeShiftC_ladoB != dominoPieces[playerA.playerPieces[option]].sideA || timeShiftC_ladoB != dominoPieces[playerA.playerPieces[option]].sideB && bilola == false ){
                            printf("VC BURRO NAO JOGAR PEÇAS CORRETAS QUEBRAR JOGO DESTE MODO\n");
                            bilola = false;
                            continue;
                                                                                                                 
                        }
                    }else{
                        timeShiftC_ladoA = dominoPieces[playerA.playerPieces[option]].sideA;
                        timeShiftC_ladoB = dominoPieces[playerA.playerPieces[option]].sideB;
                    }
                    validador++;

                    printf("%d %d", timeShiftC_ladoA,timeShiftC_ladoB );
                    printf(" MEU NEGRO JOGOU ESTA PEÇA E ELA EM BREVE SERA VALIDADE ->>> [%d|%d]\n",timeShiftC_ladoA,timeShiftC_ladoB );

                    for(int k = 0; k <= 168; k++){ //começa percorrer o array pelo começo
                        if(mesaBool[k] == true){
                            if(mesaCounter == 0){ //vai colocando em partes a peça no array da mesa
                                mesaIndex[k] = '[';
                                mesaBool[k] = false;
                                mesaCounter++;
                            }
                            else if(mesaCounter == 1){
                                if(pavement){
                                sprintf(str, "%d", dominoPieces[playerA.playerPieces[option]].sideB);
                                mesaIndex[k] = *str;
                                mesaBool[k] = false;
                                mesaCounter++;
                                }else{
                                sprintf(str, "%d", dominoPieces[playerA.playerPieces[option]].sideA);
                                mesaIndex[k] = *str;
                                mesaBool[k] = false;
                                mesaCounter++;

                                }
                            }
                            else if(mesaCounter == 2){
                                mesaIndex[k] = '|';
                                mesaBool[k] = false;
                                mesaCounter++;
                            }else if(mesaCounter == 3){
                                if(pavement){
                                sprintf(str, "%d", dominoPieces[playerA.playerPieces[option]].sideA);
                                mesaIndex[k] = *str;
                                mesaBool[k] = false;
                                mesaCounter++;
                                pavement = false;
                                }else{
                                sprintf(str, "%d", dominoPieces[playerA.playerPieces[option]].sideB);
                                mesaIndex[k] = *str;;
                                mesaBool[k] = false;
                                mesaCounter++;
                                }
                            }else if(mesaCounter == 4){
                                mesaIndex[k] = ']';
                                mesaBool[k] = false;
                                mesaCounter++;
                            }else if(mesaCounter == 5){
                                mesaIndex[k] = ' ';
                                mesaBool[k] = false;
                                mesaCounter++;
                            }

                        }
                    }
                }else if(toupper(megaOption) == 'F'){

                if (validador2 > 0) {
                    if (timeShiftF_ladoB == dominoPieces[playerA.playerPieces[option]].sideB && timeShiftF_ladoB != dominoPieces[playerA.playerPieces[option]].sideA )
                            {
                                pavement = true;
                                bilola = true;
                                
                                timeShiftF_ladoA = dominoPieces[playerA.playerPieces[option]].sideB;
                                timeShiftF_ladoB = dominoPieces[playerA.playerPieces[option]].sideA;
                                
                            }else{
                                    timeShiftF_ladoA = dominoPieces[playerA.playerPieces[option]].sideA;
                                    timeShiftF_ladoB = dominoPieces[playerA.playerPieces[option]].sideB;
                            }
                         if (timeShiftF_ladoA != dominoPieces[playerA.playerPieces[option]].sideB || timeShiftF_ladoA != dominoPieces[playerA.playerPieces[option]].sideA && bilola == false ){
                            printf("VC BURRO NAO JOGAR PEÇAS CORRETAS QUEBRAR JOGO DESTE MODO\n");
                            bilola = false;
                            continue;
                                                                                                        
                        }
                    }else{
                        timeShiftF_ladoA = dominoPieces[playerA.playerPieces[option]].sideA;
                        timeShiftF_ladoB = dominoPieces[playerA.playerPieces[option]].sideB;
                    }
                    validador2++;

                    printf(" MEU NEGRO JOGOU ESTA PEÇA E ELA EM BREVE SERA VALIDADE ->>> [%d|%d]\n",timeShiftF_ladoA,timeShiftF_ladoB );

                    for(int k = 168; k >= 0 ; k--){
                        if(mesaBool[k] == true){
                            if(mesaCounter == 0){
                                mesaIndex[k] = ']';
                                mesaBool[k] = false;
                                mesaCounter++;
                            }
                            else if(mesaCounter == 1){
                                if(pavement){
                                sprintf(str, "%d", dominoPieces[playerA.playerPieces[option]].sideA);
                                mesaIndex[k] = *str;
                                mesaBool[k] = false;
                                mesaCounter++;
                                }else{
                                sprintf(str, "%d", dominoPieces[playerA.playerPieces[option]].sideB);
                                mesaIndex[k] = *str;
                                mesaBool[k] = false;
                                mesaCounter++;

                                }
                            }
                            else if(mesaCounter == 2){
                                mesaIndex[k] = '|';
                                mesaBool[k] = false;
                                mesaCounter++;
                            }else if(mesaCounter == 3){
                                if(pavement){
                                sprintf(str, "%d", dominoPieces[playerA.playerPieces[option]].sideB);
                                mesaIndex[k] = *str;
                                mesaBool[k] = false;
                                mesaCounter++;
                                pavement = false;
                                }else{
                                sprintf(str, "%d", dominoPieces[playerA.playerPieces[option]].sideA);
                                mesaIndex[k] = *str;
                                mesaBool[k] = false;
                                mesaCounter++;

                                }
                            }else if(mesaCounter == 4){
                                mesaIndex[k] = '[';
                                mesaBool[k] = false;
                                mesaCounter++;
                            }else if(mesaCounter == 5){
                                mesaIndex[k] = ' ';
                                mesaBool[k] = false;
                                mesaCounter++;
                            }

                        }
                    }
                    solucaoMacaca = true;
                };

                for(int k = option; k < playerA_Piece_Count; k++){ //algoritmo que joga todo o array pra esquerda
                    dominoPieces[playerA.playerPieces[k]].sideA = dominoPieces[playerA.playerPieces[k+1]].sideA;
                    dominoPieces[playerA.playerPieces[k]].sideB = dominoPieces[playerA.playerPieces[k+1]].sideB;
                }
                dominoPieces[playerA.playerPieces[playerA_Piece_Count-1]].sideA = '\0';
                dominoPieces[playerA.playerPieces[playerA_Piece_Count-1]].sideB = '\0';
                playerA_Piece_Count--;
                dominoPieces[playerA.playerPieces[option]].inGame = true; //status da peça em jogo
                }
                 if(playerSecundario == 2){
                do{
                printf("Escolha uma peça de 0 a %d\n",playerB_Piece_Count-1);
                scanf("%d",&option);
                flush_in();
                if(option < 0 || option > playerB_Piece_Count){
                    //scanf("%d",&option);
                    showMessage("Peça inválida...\n");
                    continue;
                }else
                    break;

                }while(true); //invalidar a peça, mudar on table para true e available false
                //printf("Peça jogada: [%d|%d] foi jogada\n",dominoPieces[playerA.playerPieces[option]].sideA,dominoPieces[playerA.playerPieces[option]].sideB);
                megaOption = grabOptionBoard(); //opção começo ou fim?
                mesaCounter = 0; //contador para quebrar a atribuição em partes
                if(toupper(megaOption) == 'C'){
                
                    if (validador > 0) {
                        if (timeShiftC_ladoB == dominoPieces[playerB.playerPieces[option]].sideB && timeShiftC_ladoB != dominoPieces[playerB.playerPieces[option]].sideA )
                            {
                                bilola = true; 
                                pavement = true;
                                
                                timeShiftC_ladoA = dominoPieces[playerB.playerPieces[option]].sideB;
                                timeShiftC_ladoB = dominoPieces[playerB.playerPieces[option]].sideA;
                                
                            }else{
                                    timeShiftC_ladoA = dominoPieces[playerB.playerPieces[option]].sideA;
                                    timeShiftC_ladoB = dominoPieces[playerB.playerPieces[option]].sideB;
                            }
                         if (timeShiftC_ladoB != dominoPieces[playerB.playerPieces[option]].sideA || timeShiftC_ladoB != dominoPieces[playerB.playerPieces[option]].sideB && bilola == false ){
                            printf("VC BURRO NAO JOGAR PEÇAS CORRETAS QUEBRAR JOGO DESTE MODO\n");
                            bilola = false;
                            continue;
                                                                                                                 
                        }
                    }else{
                        timeShiftC_ladoA = dominoPieces[playerB.playerPieces[option]].sideA;
                        timeShiftC_ladoB = dominoPieces[playerB.playerPieces[option]].sideB;
                    }
                    validador++;

                    printf("%d %d", timeShiftC_ladoA,timeShiftC_ladoB );
                    printf(" MEU NEGRO JOGOU ESTA PEÇA E ELA EM BREVE SERA VALIDADE ->>> [%d|%d]\n",timeShiftC_ladoA,timeShiftC_ladoB );

                    for(int k = 0; k <= 168; k++){ //começa percorrer o array pelo começo
                        if(mesaBool[k] == true){
                            if(mesaCounter == 0){ //vai colocando em partes a peça no array da mesa
                                mesaIndex[k] = '[';
                                mesaBool[k] = false;
                                mesaCounter++;
                            }
                            else if(mesaCounter == 1){
                               if(pavement){
                                sprintf(str, "%d", dominoPieces[playerB.playerPieces[option]].sideB);
                                mesaIndex[k] = *str;
                                mesaBool[k] = false;
                                mesaCounter++;
                                }else{
                                sprintf(str, "%d", dominoPieces[playerB.playerPieces[option]].sideA);
                                mesaIndex[k] = *str;
                                mesaBool[k] = false;
                                mesaCounter++;

                                }
                            }
                            else if(mesaCounter == 2){
                                mesaIndex[k] = '|';
                                mesaBool[k] = false;
                                mesaCounter++;
                            }else if(mesaCounter == 3){
                                   if(pavement){
                                sprintf(str, "%d", dominoPieces[playerB.playerPieces[option]].sideA);
                                mesaIndex[k] = *str;
                                mesaBool[k] = false;
                                mesaCounter++;
                                pavement = false;
                                }else{
                                sprintf(str, "%d", dominoPieces[playerB.playerPieces[option]].sideB);
                                mesaIndex[k] = *str;
                                mesaBool[k] = false;
                                mesaCounter++;
                                }
                            }else if(mesaCounter == 4){
                                mesaIndex[k] = ']';
                                mesaBool[k] = false;
                                mesaCounter++;
                            }else if(mesaCounter == 5){
                                mesaIndex[k] = ' ';
                                mesaBool[k] = false;
                                mesaCounter++;
                            }

                        }
                    }
                }else if(toupper(megaOption) == 'F'){

                if (validador2 > 0) {
                    if (timeShiftF_ladoB == dominoPieces[playerB.playerPieces[option]].sideB && timeShiftF_ladoB != dominoPieces[playerB.playerPieces[option]].sideA )
                            {
                                pavement = true;
                                bilola = true;
                                
                                timeShiftF_ladoA = dominoPieces[playerB.playerPieces[option]].sideB;
                                timeShiftF_ladoB = dominoPieces[playerB.playerPieces[option]].sideA;
                                
                            }else{
                                    timeShiftF_ladoA = dominoPieces[playerB.playerPieces[option]].sideA;
                                    timeShiftF_ladoB = dominoPieces[playerB.playerPieces[option]].sideB;
                            }
                         if (timeShiftF_ladoA != dominoPieces[playerB.playerPieces[option]].sideB || timeShiftF_ladoA != dominoPieces[playerB.playerPieces[option]].sideA && bilola == false ){
                            printf("VC BURRO NAO JOGAR PEÇAS CORRETAS QUEBRAR JOGO DESTE MODO\n");
                            bilola = false;
                            continue;
                                                                                                        
                        }
                    }else{
                        timeShiftF_ladoA = dominoPieces[playerB.playerPieces[option]].sideA;
                        timeShiftF_ladoB = dominoPieces[playerB.playerPieces[option]].sideB;
                    }
                    validador2++;

                    printf(" MEU NEGRO JOGOU ESTA PEÇA E ELA EM BREVE SERA VALIDADE ->>> [%d|%d]\n",timeShiftF_ladoA,timeShiftF_ladoB );


                    for(int k = 168; k >= 0 ; k--){
                        if(mesaBool[k] == true){
                            if(mesaCounter == 0){
                                mesaIndex[k] = ']';
                                mesaBool[k] = false;
                                mesaCounter++;
                            }
                            else if(mesaCounter == 1){
                               if(pavement){
                                sprintf(str, "%d", dominoPieces[playerB.playerPieces[option]].sideA);
                                mesaIndex[k] = *str;
                                mesaBool[k] = false;
                                mesaCounter++;
                                }else{
                                sprintf(str, "%d", dominoPieces[playerB.playerPieces[option]].sideB);
                                mesaIndex[k] = *str;
                                mesaBool[k] = false;
                                mesaCounter++;

                                }
                            }
                            else if(mesaCounter == 2){
                                mesaIndex[k] = '|';
                                mesaBool[k] = false;
                                mesaCounter++;
                            }else if(mesaCounter == 3){
                                if(pavement){
                                sprintf(str, "%d", dominoPieces[playerB.playerPieces[option]].sideB);
                                mesaIndex[k] = *str;
                                mesaBool[k] = false;
                                mesaCounter++;
                                pavement = false;
                                }else{
                                sprintf(str, "%d", dominoPieces[playerB.playerPieces[option]].sideA);
                                mesaIndex[k] = *str;
                                mesaBool[k] = false;
                                mesaCounter++;

                                }
                            }else if(mesaCounter == 4){
                                mesaIndex[k] = '[';
                                mesaBool[k] = false;
                                mesaCounter++;
                            }else if(mesaCounter == 5){
                                mesaIndex[k] = ' ';
                                mesaBool[k] = false;
                                mesaCounter++;
                            }

                        }
                    }
                    solucaoMacaca = true;
                };

                for(int k = option; k < playerA_Piece_Count; k++){ //algoritmo que joga todo o array pra esquerda
                    dominoPieces[playerB.playerPieces[k]].sideA = dominoPieces[playerB.playerPieces[k+1]].sideA;
                    dominoPieces[playerB.playerPieces[k]].sideB = dominoPieces[playerB.playerPieces[k+1]].sideB;
                }
                dominoPieces[playerB.playerPieces[playerB_Piece_Count-1]].sideA = '\0';
                dominoPieces[playerB.playerPieces[playerB_Piece_Count-1]].sideB = '\0';
                playerB_Piece_Count--;
                dominoPieces[playerB.playerPieces[option]].inGame = true; //status da peça em jogo
                }
                break; 

                //Imprime as regras
                case 5:
                printRules();
                    continue;

                case 6:
                exit(1);
                // Sai do jogo 
                break;
            }


                clearScreen();
                playerIni = true; //troca as jogadas
                playerSec = false; //troca as jogadas
            }
        }; //fase de testes ok...............
            //jogador 2 playerInicio jogar peça (ao menos index 0) jogar no inicio quebra o jogo


            return 0; 
        }


