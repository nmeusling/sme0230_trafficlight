/** @file input.h
 *  @brief Header file for input.c
 *
 *  This file contains the declarations for functions related to user input,
 *  including getting the next move and validating it.
 *
 *  @author Natalie Menato (10295051)
 */

#ifndef INPUT_H
#define INPUT_H

#include "board.h"

/** @brief Indexes row based on ASCII code
 *
 * This function indexes the row, which is currently the int related to the
 * input char, so that 0 corresponds to the first row, 1 to the second row, etc.
 *
 * @param row int corresponding to the input row char
 * @return index of the input row
 */
int index_row(int row);

/** @brief Indexes column based on ASCII code
 *
 * This function indexes the column, which is currently the int related to the
 * input char, so that 0 corresponds to the first column, 1 to the second
 * column, etc.
 *
 * @param col int corresponding to the input column char
 * @return index of the input column
 */
int index_column(int col);

/** @brief Validates if a move is valid given current board
 *
 *  This function verifies if the move's row and column are valid indexes of
 *  the board and also makes sure the desired move does not already continue
 *  the highest allowed piece.
 *
 *  @param move t_move that the user input and wants to make
 *  @param board t_board the current state of the board
 *  @return True if the move is valid, otherwise False.
 */
int valid_board_move(t_move, t_board);

/** @brief Flushes any extra characters input by user
 *
 * If the user inputs more than the expected number of characters, the extra
 * character are disregarded to prevent errors from occurring during program
 * execution.
 */
void flush_std_in(void);

/** @brief Checks if user wants to quit
 *
 * This function checks if the user entered 'q' or 'Q', signaling that they
 * want to quit the game.
 *
 * @param input int corresponding to the input char
 * @return True if user wants to quit, otherwise False
 */
int quit(int input);

/** @brief Prompts user to input move and validates it
 *
 * Prompts user to enter a move until a valid move has been entered. Stores the
 * valid move in the pointer that was passed to function.
 *
 * @param move t_move * stores the desired move
 * @param board t_board that stores the current state of the board
 * @param player int that represents whose turn it is
 * @return False if user wants to quit, otherwise True
 */
int get_move(t_move *move, t_board board, int player);

#endif
