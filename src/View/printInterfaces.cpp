//MVC - View
//Grupo Shoegazer - Função para imprimir menus

#include <stdio.h>

//Menu principal
void printMenu()
{
    printf(
        " _____________________________________ \n"
        "|                 MENU                |\n"
        "|                                     |\n"
        "|          Select an option:          |\n"
        "|                                     |\n"
        "|                                     |\n"
        "|  1) Show Pieces                     |\n"
        "|                                     |\n"
        "|  2) Select Mode                     |\n"
        "|                                     |\n"
        "|  3) Game Menu (Sample)              |\n"
        "|                                     |\n"
        "|  4) ?????????                       |\n"
        "|                                     |\n"
        "|  5) Rules                           |\n"
        "|                                     |\n"
        "|  6) Exit                            |\n"
        "|                                     |\n"
        "|_____________________________________|\n");
}

//Menu de modo
void printMode (){
    printf(
    " ___________________________\n"
    "|                           |\n"
    "|     Select Game Mode      |\n"  
    "|                           |\n"
    "|    1) Solo - P1 VS IA     |\n"
    "|                           |\n"
    "|    2) Multi - P1 VS P2    |\n"
    "|                           |\n"
    "|    3) Back to Menu        |\n"
    "|___________________________|\n");
}

//Menu de jogador
void printInGameMenu(){
    printf(
    " _______________________________\n"
    "|                               |\n"
    "|         Player  #1            |\n"
    "|                               |\n"
    "|   1) See Table                |\n"
    "|                               |\n"
    "|   2) Show Pieces              |\n"
    "|                               |\n"
    "|   3) Buy Pieces               |\n"
    "|                               |\n"
    "|   4) Play                     |\n"
    "|                               |\n"
    "|   5) Quit Game                |\n"
    "|_______________________________|\n"
    );
}

void printRules(){
    printf(
        " _____________________________________ \n"
        "|                Rules                |\n"
        "|                                     |\n"
        "|  * The player with the highest      |\n"
        "|    piece (6-6) starts the game.     |\n"
        "|                                     |\n"
        "|  * Each player must try to match    |\n"
        "|    one of the pieces at the end of  |\n"
        "|    the table, when the player fits  |\n"
        "|    one piece it passes their turn   |\n"
        "|    In case they can't do it, they   |\n"
        "|    must buy a piece, if there is no |\n"
        "|    piece it will pass the turn.     |\n"
        "|                                     |\n"
        "|  * The game ends when one of the    |\n"
        "|    players run out of pieces, when  |\n"
        "|    the game 'closes', that means    |\n"
        "|    there is no other possibility    |\n"
        "|     to put new pieces.              |\n"
        "|                                     |\n"
        "|  * Each piece is composed by 2      |\n"
        "|    numbers, one in which extremity  |\n"
        "|    the value of which piece is the  |\n"
        "|    sum of the two numbers. E.g the  |\n"
        "|    (0-0) worths 0 points, the (5-2) |\n"
        "|    worths 7 points and (6-6) worths |\n"
        "|    12 points.                       |\n"   
        "|_____________________________________|\n");
}