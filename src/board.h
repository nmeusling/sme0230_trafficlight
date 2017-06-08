/* Natalie Menato
   Numero USP: 10295051
   31/05/2017
   Submissao para Trabalho Parte 3  */

#ifndef BOARD_H
#define BOARD_H


#include "main.h"


void print_board(t_board);
// Prints the board that was passed to the function to the screen.

int clear_board(t_board *);
// Clears the board so each position has value 0

int valid_board_move(t_move, t_board);
//check if it is possible to play at desired position
// is valid if the value of the board at row column is < 3

void update_board(t_move, t_board *);
//updates the board based on the last move

int won_game(t_board, t_move);
//return TRUE if last move caused player to win game, FALSE otherwise

int check_column(t_board, int);
//check if a user has won in a column, return TRUE if yes, otherwise FALSE

int check_row(t_board, int);
//check if a user has won in a row, return TRUE if yes, otherwise FALSE

int check_diagonal(t_board, t_move);
//check if user won in either diagonal, return TRUE if yes, otherwise FALSE

int dec_diag(t_board, t_move);
//verify if the decreasing diaganal has three in a row

int inc_diag(t_board, t_move);
//if the increasing diagonal has three in a row return TRUE if yes, else return FALSE

void undo_move(t_move move, t_board *board);
#endif
