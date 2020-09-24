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
        "|          Selecione uma opção:       |\n"
        "|                                     |\n"
        "|  1) Selecionar Modo                 |\n"
        "|                                     |\n"
        "|  2) Regras                          |\n"
        "|                                     |\n"
        "|  3) Sair                            |\n"
        "|                                     |\n"
        "|_____________________________________|\n");
}

//Menu de modo
void printMode (){
    printf(
    " ___________________________\n"
    "|                           |\n"
    "|     Modo de jogo          |\n"  
    "|                           |\n"
    "|    1) Solo - P1 VS IA     |\n"
    "|                           |\n"
    "|    2) Multi - P1 VS P2    |\n"
    "|                           |\n"
    "|    3) Voltar ao Menu      |\n"
    "|___________________________|\n");
}

//Menu de jogador
void printInGameMenu(int numero){
    printf(
    " _______________________________\n"
    "|                               |\n"
    "|         Jogador  #%d          |\n"
    "|                               |\n"
    "|   1) Ver Mesa                 |\n"
    "|                               |\n"
    "|   2) Mostrar Peças            |\n"
    "|                               |\n"
    "|   3) Comprar Peças            |\n"
    "|                               |\n"
    "|   4) Jogar                    |\n"
    "|                               |\n"
    "|   5) Sair do Jogo             |\n"
    "|_______________________________|\n"
    ,numero);
}

//Regras do jogo
void printRules(){
    printf(
        " _____________________________________ \n"
        "|                Regras               |\n"
        "|                                     |\n"
        "|  * Cada jogador pega sete peças e   |\n"
        "|    pode comprar sempre que precisar |\n"
        "|    de uma peça para poder jogar e   |\n"
        "|    e sempre que for necessário.     |\n"
        "|                                     |\n"
        "|  * Da se inicio ao jogo o jogador   |\n"
        "|    que tira a peça [6|6] ou o jo-   |\n"
        "|    gador que possui a maior pedra   |\n"
        "|    de números repetidos.            |\n"
        "|                                     |\n"
        "|  * O jogo acontece no sentido anti- |\n"
        "|    -horário e os jogadores devem    |\n"
        "|    colocar peças que tenham os mes- |\n"
        "|    mos numeros das peças que se en- |\n"
        "|    contram na ponta do jogo.        |\n"
        "|                                     |\n"
        "|  * Cada jogador no seu turno deve   |\n"
        "|    colocar uma das suas peças numa  |\n"
        "|    das extremidades abertas de for- |\n"
        "|    ma que os pontos de um dos lados |\n"
        "|    coincida com os pontos da extre- |\n"
        "|    midade onde está sendo colocada. |\n"
        "|                                     |\n"
        "|  * Quando jogador jogar sua peça    |\n"
        "|    sobre a mesa, seu turno se acaba |\n"
        "|    e passa-se ao seguinte jogador.  |\n"
        "|                                     |\n"
        "|  * Se o jogador não puder jogar ele |\n"
        "|    deverá comprar do monte tantas   |\n"
        "|    peças quanto forem necessárias,  |\n"  
        "|    se não houver peças no monte,pas-|\n"
        "|    sará o turno ao seguinte jogador |\n"
        "|                                     |\n"
        "|  * A partida continua com seus joga-|\n"
        "|    dores colando suas peças sobre a |\n"
        "|    mesa até que se apresente alguma |\n"
        "|    das seguintes situações:         |\n"
        "|    1- Quando jogador colocar sua    |\n"
        "|       última pedra sobre a mesa.    |\n"
        "|    2- Quando nenhum dos jogadores   |\n"
        "|       conseguir continuar a partida |\n"
        "|       os pontos das pedras que fica-|\n"
        "|       ram serão somados, vence quem |\n"
        "|       ficar com menos pontos.       |\n"
        "|    3- Se a soma dos pontos forem    |\n"
        "|       iguais vence o jogador que    |\n"
        "|       começou a partida.            |\n"
        "|                                     |\n"
        "|_____________________________________|\n");
}

//Mesa inicial
void printMesaInicial(){
        printf(
        " __________________________________________________________________\n"
        "|                                                                  |\n"
        "|                                                                  |\n"  
        "|                                                                  |\n"
        "|                                                                  |\n"
        "|                                                                  |\n"
        "|                                                                  |\n"
        "|                                                                  |\n"
        "|                                                                  |\n"
        "|                                                                  |\n"
        "|                                                                  |\n"
        "|                                                                  |\n"
        "|                                                                  |\n"
        "|                                                                  |\n"
        "|                                                                  |\n"
        "|                                                                  |\n"
        "|                                                                  |\n"
        "|                                                                  |\n"
        "|__________________________________________________________________|\n");

}

