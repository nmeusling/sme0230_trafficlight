/* Natalie Menato
   Numero USP: 10295051
   27/05/2017
   Submissao para Trabalho Parte 3  */

#include "main.h"

int main() {

    //declare t_board struct current_board to store current state of game board
    t_board main_board;
    srand((unsigned int) time(NULL));

    begin_game(&main_board);
    //select correct game type: PvC or PvP
    int game_type = get_game_type();
    if (game_type == 0)
        return 0;
    if (game_type == 1)
        pvc_play(&main_board);
    if (game_type == 2)
        pvp_play(&main_board);
    return 0;
}


