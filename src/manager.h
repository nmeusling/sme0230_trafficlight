/* Natalie Menato
   Numero USP: 10295051
   27/05/2017
   Submissao para Trabalho Parte 3  */

#ifndef MANAGER_H
#define MANAGER_H

#include "board.h"
#include <stdlib.h>
#include <time.h>

int begin_game(t_board *);

//function to print the game opening with basic instructions for play.
//returns FALSE if the user does not want to start a game, TRUE otherwise
void print_menu();

int pvp_play(t_board *);

int pvc_play(t_board *);

int get_game_type();

#endif //SME0230_TRAFFICLIGHT_MANAGER_H
