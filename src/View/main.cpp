//MVC - View 
//Grupo Shoegazer - função para pegar opções e mostrar interfaces principais

#include "../Controller/showPieces.cpp"
#include "../Controller/grabOption.cpp"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main()
{
    while (true)
    {
        int option;
        printMenu();
        option = grabOption();
        flush_in();
        if(option == 6)
            exit(1);
        else if(option == 1){
            showPieces();
        }
        else if(option == 2){
          printMode();
          option = grabOptionMode();
          flush_in();
          if(option == 3)
            continue;
        }
        else if (option == 3){
            printInGameMenu();
            option = grabOptionInGame();
            flush_in();
            if(option == 3)
                continue;
        }
        else if (option == 5){
            printRules();
            continue;
        }
    }

    return 0;
}
