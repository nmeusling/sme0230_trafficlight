/** @file board.c
 *  @brief Header file for board.c
 *
 *  This file contains the declaration for the functions related to the board,
 *  including printing, clearing, making a move, and validating if a player has
 *  won.
 *
 *  @author Natalie Menato (10295051)
 */

#ifndef BOARD_H
#define BOARD_H


#include "main.h"

/** @brief Prints the current board
 *
 * This function prints the current board with all moves that have already
 * been made
 *
 * @param board t_board that represents the current state of the board
 */
void print_board(t_board board);

/** @brief Clears the board
 *
 * Clears the board so that each position has a value of 0, representing an
 * empty position.
 *
 * @param board t_board* that contains the address of the current board
 */
void clear_board(t_board *board);

/** @brief Updates the board with the last move
 *
 * Increases the value of the board at the location of the last move that was
 * made.
 *
 * @param move t_move that contains the move to be made
 * @param board t_board* that contains the address of the current board
 */
void make_move(t_move move, t_board *board);

/** @brief Updates the board by undoing a move
 *
 * Dereases the value of the board at the location of the move that was passed.
 *
 * @param move t_move that contains the move to be undone
 * @param board t_board* that contains the address of the current board
 */
void undo_move(t_move move, t_board *board);

/** @brief Verifies if the last move resulted in a win
 *
 * Checks if the last move resulted in a win for the last player. Checks if
 * there are three consecutive pieces that are the same in a row, column or
 * diagonal.
 *
 * @param move t_move that contains the move that was just made
 * @param board t_board that contains the current state of the board
 * @return True if player won game, otherwise False
 */
int won_game(t_board, t_move);

/** @brief Verifies if the last move resulted in a win in a column
 *
 * Checks if the last move resulted in a win in a column. Checks if
 * there are three consecutive pieces that are the same in the column of move.
 *
 * @param board t_board that contains the current state of the board
 * @param col int that contains the index of the column of the move
 * @return True if column has three in a row, otherwise False
 */
int check_column(t_board board, int col);

/** @brief Verifies if the last move resulted in a win in a row
 *
 * Checks if the last move resulted in a win in a row. Checks if
 * there are three consecutive pieces that are the same in the row of move.
 *
 * @param board t_board contains the current state of the board
 * @param row int that contains the index of the row of the move
 * @return True if row has three in a row, otherwise False
 */
int check_row(t_board board, int row);
//check if a user has won in a row, return TRUE if yes, otherwise FALSE

/** @brief Verifies if the last move resulted in a win in a diagonal
 *
 * Checks if the last move resulted in a win in a diagonal. Checks if
 * there are three consecutive pieces that are the same in the diagonal.
 *
 * @param board t_board contains the current state of the board
 * @param move t_move that contains the last move that was made
 * @return True if diagonal has three in a row, otherwise False
 */
int check_diagonal(t_board board, t_move move);

/** @brief Verifies if the last move resulted in a win in decreasing diagonal
 *
 * Checks if the last move resulted in a win in a decreasing diagonal. Checks if
 * there are three consecutive pieces that are the same in the diagonal.
 *
 * @param board t_board contains the current state of the board
 * @param move t_move that contains the last move that was made
 * @return True if diagonal has three in a row, otherwise False
 */
int dec_diag(t_board, t_move);

/** @brief Verifies if the last move resulted in a win in increasing diagonal
 *
 * Checks if the last move resulted in a win in an increasing diagonal. Checks if
 * there are three consecutive pieces that are the same in the diagonal.
 *
 * @param board t_board contains the current state of the board
 * @param move t_move that contains the last move that was made
 * @return True if diagonal has three in a row, otherwise False
 */
int inc_diag(t_board, t_move);


#endif
