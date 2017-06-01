/* Natalie Menato
   Numero USP: 10295051
   27/05/2017
   Submissao para Trabalho Parte 3  */

#ifndef MANAGER_H
#define MANAGER_H

#include "board.h"
#include <stdlib.h>
#include <time.h>

void begin_game(t_board *);
// Clears the board and prints the opening menu.

void print_menu();
// Prints the game opening with basic instructions for play.

int pvp_play(t_board *);
// Controls PvP play until a player wins or quits

int pvc_play(t_board *);
// Controls PvC play until a player wins or quits

int get_game_type();
// Asks user for play mode (PvP or PvC)
// Returns 1 for PvC, 2 for PvP, 0 to quit program

int switch_player(int);
// Switches which player's turn it is

void random_move(t_move *, t_board);
// Saves a valid, random move to move

char column_letter(int);
// returns column letter based on column index

#endif //SME0230_TRAFFICLIGHT_MANAGER_H
