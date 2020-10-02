//Grupo Shoegazer - Função Principal com lógica do jogo e inicio do mesmo.
//MVC - Controller - isto virou uma anarquia
// ATENÇÃO ATE O PRESENTE MOMENTO SE O JOGADOR 2 INICIAR O JOGO E NÃO COMPRAR PEÇA, ELE QUEBRA
//NÃO SABEMOS O PORQUE PF ALGUEM ME AJUDA


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "./Controller/gameController.c"



int main()
{
    while (true)
    {
        int option;
        
        printMenu();
        option = grabOption();
        clearScreen();
        
        flush_in();

        // OPÇÃO de saida
        if(option == 3)
            exit(1);

        // OPÇÃO --> Selecionar numero de jogadores
        else if(option == 1) {
            
          printMode();
          option = grabOptionMode();
          clearScreen();
          
          
          if(option == 1){
              showMessage("Modo em desenvolvimento...\n");
              showMessage("Reiniciando...\n\n");
          }
          else if(option == 2){
              showMessage("Modo de 2 jogadores selecionado\n\n");
              player playerA, playerB;
              
              playerA.playerNum = 1;
              playerB.playerNum = 2;
              showMessage("Modo de 2 jogadores selecionado\n\n");
              clearScreen();
              game(playerA,playerB);
              continue;
              
              
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




