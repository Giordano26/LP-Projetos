//Excluir essa função dps

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>


//Função para imprimir cada elemento do array
void arrayLoop(char arr[28][3])
{
    for (int k = 0; k < 28; k++)
    {
        printf(arr[k]);
        printf(" ");
        if (k % 7 == 0 && k != 0)
            printf("\n");
    }
}
