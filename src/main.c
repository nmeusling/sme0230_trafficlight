/** @file main.c
 *  @brief main c file containing implementation of traffic light game
 *
 *  SME0230 - Introducao a Programacao de Computadores - USP/Fall 2017
 *
 *                     Prof. Marina Andretta
 *
 *  @author Natalie Menato (10295051)
 */

#include "main.h"
#include "manager.h"

int main() {

    //stores the current state of the game board
    t_board main_board;
    srand((unsigned int) time(NULL));

    //test score function
    clear_board(&main_board);

    //clears board and prints opening menu
    begin_game(&main_board);

    //get desired game type: 1 for PvC, 2 for PvP, 3 to quit
    int game_type = get_game_type();
    //quit game
    if (game_type == 0)
        return 0;
    //begin PvC game
    if (game_type == 1)
        pvc_play(&main_board);
    //begin PvP game
    if (game_type == 2)
        pvp_play(&main_board);
    return 0;
}

