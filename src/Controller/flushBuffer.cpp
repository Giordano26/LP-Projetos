// MVC - Controller
// Grupo Shoegazer - função de limpeza de input afim de evitar erros de buffer do teclado

#include <stdio.h>

void flush_in(){

    int ch;

    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){

    }
}
