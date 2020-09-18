//MVC - Controller
//Grupo Shoegazer - Função para embaralhar o index das peças

#include <stdio.h>
#include <time.h>


int * shuffle(){
    static int randomNumber[28];

    srand(time(NULL));


   for (int k = 0; k < 28; k++)
    {
        randomNumber[k] = k;
    }

    for (int k = 0; k < 28; k++)
    {
        int temp = randomNumber[k];
        int randomIndex = rand() % 27;
        randomNumber[k] = randomNumber[randomIndex];
        randomNumber[randomIndex] = temp;
    }

    return randomNumber;
}
