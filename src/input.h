/* Natalie Menato
   Numero USP: 10295051
   31/05/2017
   Submissao para Trabalho Parte 3  */

#ifndef INPUT_H
#define INPUT_H

#include "board.h"


int is_row_valid(int);
//Return 1 if the int passed corresponds to a valid row, else return 0


int is_column_valid(int);
//Return 1 if the int passed corresponds to a valid column, else return 0


int validate_input(t_move *, t_board board);
//Validate if input row and column numbers are both valid
//return TRUE if valid and valid board move
//return 0 if invalid format
//return -1 if invalid board move


void index_move(t_move *);
//changes move from ascii code to index of desired row and column


void flush_std_in(void);
//Flushes any extra chars input by user

int get_move(t_move *, t_board, int player);
//Get player's desired move, validate it, and store it in move
//return True if all is successful
//return False if user wants to quit

#endif
