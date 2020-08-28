#include <stdio.h>


//função de limpeza de input afim de evitar erros de buffer do teclado
void flush_in(){

    int ch;

    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){

    }
}
