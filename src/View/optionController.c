//Grupo Shoegazer - Função para pegar o input do usuário

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

//Cada menu tem que ter sua função própria de escolha

//função para o main menu
int grabOption()
{
    int option;

    do
    {
       showMessage("\nEscolha uma opção: \n");
        scanf("%d", &option);

        if(option < 1 || option > 3){
            showMessage("Opção inválida...\n");
        }else
            break;
    } while (true);

    printf("\n");

    return option;
}

//função para o menu de modo de jogo
int grabOptionMode()
{
    int option;

    do
    {
        showMessage("\nEscolha uma opção: \n");
        scanf("%d", &option);

        if(option < 1 || option > 3){
            showMessage("Opção inválida...\n");
        }else
            break;
    } while (true);

    printf("\n");

    return option;
}

//função para menu do jogador "in game"
int grabOptionInGame()
{
    int option;

    do
    {
        showMessage("\nEscolha uma opção: \n");
        scanf("%d", &option);

        if(option < 1 || option > 6){
            showMessage("Opção inválida...\n");
        }else
            break;
    } while (true);

    printf("\n");

    return option;
}


//função para opções dentro da mesa
char grabOptionBoard(){
    char option;
    do{
        showMessage("\n Jogar no começo ou no final?\n(C/F)\n");
        scanf("%s",&option);

        if(toupper(option) == 'C' || toupper(option) == 'F'){
            return option;
        }
        else{
            showMessage("Opção inválida...");
            continue;
        }

    }while(true);
}


    
//funlção para a inversão da peça
char grabOptionInvert(){
    char option;
    do{
        showMessage("\n Inverter a peça?\n(S/N)\n");
        scanf("%s",&option);
        
        if(toupper(option) == 'S' || toupper(option) == 'N'){
            return option;
        }
        else{
            showMessage("Opção inválida...");
            continue;
        }
    }while(true);
}


char saveGame(){
    char option;
    do{
        showMessage("Salvar jogo?\n(S/N)\n");
        scanf("%s",&option);

        if(toupper(option) == 'S' || toupper(option) == 'N'){
            return option;
        }
        else{
            showMessage("Opção inválida...");
            continue;
        }
    }while(true);
}