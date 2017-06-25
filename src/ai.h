/** @file input.h
 *  @brief Header file for input.c
 *
 *  This file contains the declarations for functions related to user input,
 *  including getting the next move and validating it.
 *
 *  @author Natalie Menato (10295051)
 */

#ifndef AI_H
#define AI_H

#include "input.h"

/** @brief Finds all possible moves given the passed board
 *
 * Finds all of the possible legal moves for the board that was passed to the
 * function
 *
 * @param board t_board contains the state of the board to be analyzed
 * @return t_possible_moves struct containing all legal moves
 */
t_possible_moves possible_moves(t_board board);


/** @brief Scores a move to see how good it is for the computer
 *
 * Checks if the last move resulted in a win in a decreasing diagonal. Checks if
 * there are three consecutive pieces that are the same in the diagonal.
 *
 * @param board t_board contains the current state of the board
 * @param move t_move that contains the move to be evaluated
 * @return float corresponding to how good a move is for the computer, -1 if other
 * player can win, 1 if computer wins, -.75 if moving there leaves the computer
 * with 0 good moves on their next turn, otherwise a value between -0.5 and 0.5,
 * where the higher the number is, the fewer options for good moves the next
 * player has.
 */
float score_move(t_board board, t_move move);

/** @brief Finds the number of possible good moves for current player
 *
 * Counts how many moves the current player can make that do not allow the next
 * player to win
 *
 * @param board t_board contains the current state of the board
 * @return int corresponding to the number of good moves available
 */
int possible_good_moves(t_board board);

/** @brief Chooses the computer move based on the legal move with highest score
 *
 * Checks all possible moves and scores them. Picks a possible move with the
 * highest score.
 *
 * @param board t_board contains the current state of the board
 * @return t_move the move that the computer will make
 */
t_move computer_move(t_board board);


/** @brief Chooses a random move that is valid for the board
 *
 * Chooses a random valid move. Saves it to move.
 *
 * @param board t_board contains the current state of the board
 * @param move t_move contains the address of the computer's move
 */
void random_move(t_move *move, t_board board);


#endif //SME0230_TRAFFICLIGHT_AI_H
