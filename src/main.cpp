#include "./menuFuncs/showPieces.cpp"
#include "./utils/grabOption.cpp"

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
}

//ha