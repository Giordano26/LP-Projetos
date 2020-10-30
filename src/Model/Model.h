//MVC - Model
//Grupo Shoegazer - Definição do tipo de peça



    typedef struct 
    {   
        int sideA; //lado A da peça
        int sideB; //lado B da peça
        bool inGame; // verifica se a peça está em jogo
        bool available; // verifica se a peça esta disponível para ser comprada
        int player; //determina com que jogador está a peça 

    }piece;

    typedef struct{
        int playerNum; //numero do jogador
        int playerPieces[30]; //array de peças do jogador
    } player;


//salvar:
//struct peça
//struct player
// 2 index mesa, crivo e array em si da mesa