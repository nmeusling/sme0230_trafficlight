/** @file input.h
 *  @brief Header file for input.c
 *
 *  This file contains the declarations for functions related to user input,
 *  including getting the next move and validating it.
 *
 *  @author Natalie Menato (10295051)
 */

#ifndef MANAGER_H
#define MANAGER_H

#include "main.h"
#include "ai.h"


/** @brief Begins a new game
 *
 * Clears the game board and prints the opening menu.
 *
 * @param board t_board* contains the address of the game board
 */
void begin_game(t_board *board);


/** @brief Prints the opening menu for the game
 *
 * Prints the opening menu with the instructions of how to play.
 */
void print_menu();


/** @brief Asks user to input desired play mode.
 *
 * User can choose between PvC mode, PvP mode or quit the program.
 *
 * @return 1 for PvC mode, 2 for PvP mode, or 0 to quit the program
 */
int get_game_type();


/** @brief Controls PvP play until a player wins or quits
 *
 * Controls the game between two human players, calling functions to get the
 * next move, update the board, and check if the player won.
 *
 * @param board t_board* contains address of the current board
 * @return -1 if player quits, 0 when player wins
 */
int pvp_play(t_board *board);

/** @brief Controls PvC play until a player wins or quits
 *
 * Controls the game between a human player and the computer, calling functions
 * to get the next move, update the board, and check if the player won.
 *
 * @param board t_board* contains address of the current board
 * @return -1 if player quits, 0 if the player or computer wins
 */
int pvc_play(t_board *board);


/** @brief Asks user to input who should play first
 *
 * User decides if first move should go to the player, the computer, or if it
 * should be random. If the player chooses random, the first player is already
 * selectedrandomly.
 *
 * @param
 * @return 2 if human player goes first, or 1 if computer player goes first.
 */
int first_player();


/** @brief Switches which player's turn it is
 *
 * Switches from player 1 to player 2 or from player 2 to player 1.
 *
 * @param current_player int that refers to which player's turn it is
 * @return 2 if current_player is 1, otherwise return 1
 */
int switch_player(int current_player);


/** @brief Returns column letter based on column index
 *
 * Returns the corresponding letter for the input column index. Used for
 * printing the computer's last move.
 *
 * @param column int that stores the index of the column
 * @return char corresponding to the index column
 */
char column_letter(int column);






#endif //SME0230_TRAFFICLIGHT_MANAGER_H
