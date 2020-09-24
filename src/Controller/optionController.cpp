//MVC - Controller
//Grupo Shoegazer - Função para pegar o input do usuário

#include <stdio.h>
#include <stdbool.h>

//Cada menu tem que ter sua função própria de escolha

//função para o main menu
int grabOption()
{
    int option;

    do
    {
        printf("\nEscolha uma opção: \n");
        scanf("%d", &option);
        if (option == 1 || option == 2 || option == 3 || option == 5 || option == 6) //evita opções fora do escopo
            break;
        else
        {
            printf("Opção inválida...\n");
            continue;
        }

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
        printf("\nEscolha uma opção: \n");
        scanf("%d", &option);

        if (option == 1 || option == 2 || option == 3) //evita opções fora do escopo
            break;
        else
        {
            printf("Opção inválida...\n");
            continue;
        }

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
        printf("\nEscolha uma opção: \n");
        scanf("%d", &option);

        if (option == 5) //evita opções fora do escopo
            break;
        else
        {
            printf("Opção inválida...\n");
            continue;
        }
    } while (true);

    printf("\n");

    return option;
}