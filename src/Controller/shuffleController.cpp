//MVC - Controller
//Grupo Shoegazer - Função para embaralhar o index das peças

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//Embaralha as peças
int * shuffle(){
    static int randomNumber[28]; //criação de um array estático para os index 

    srand(time(NULL)); //pega seed randomica baseada na hora do computador


   for (int k = 0; k < 28; k++) 
    {
        randomNumber[k] = k; //gera um array com os indexes de (0-27) para randomizar as peças
    }

    for (int k = 0; k < 28; k++)
    {
        int temp = randomNumber[k];
        int randomIndex = rand() % 27;
        randomNumber[k] = randomNumber[randomIndex];
        randomNumber[randomIndex] = temp;
    } //algoritmo para randomizar os indexes sem haver repetições, sendo so possível numeros de 0-27 e sem repetições  

    return randomNumber;
}
