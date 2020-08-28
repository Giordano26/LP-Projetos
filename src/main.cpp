#include "./menuFuncs/showPieces.cpp"
#include "./utils/grabOption.cpp"


//Função main apenas para inicilizar o menu e pegar a opção selecionada pelo usuario
int main()
{
    while (true)
    {
        printMenu();
        int option = grabOption();
        if (option == 6)
        {
            exit(1);
        }
        else if (option == 1)
        {
            showPieces();
        }
    }

    return 0;
}

//ha