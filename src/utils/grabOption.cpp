#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

//Função simples para  verificação de opção do usuário no menu apenas
int grabOption()
{
    int option;
    do
    {
        printf("\nChoose an option: \n");
        scanf("%d", &option);
        flush_in();
        if (option == 1 || option == 6)
            break;
        else
            continue;
    } while (true);
    printf("\n");
    return option;
}
