/* Natalie Menato
   Numero USP: 10295051
   07/05/2017
   Submissao para Trabalho Parte 3  */

#ifndef SME0230_TRAFFICLIGHT_INPUT_H
#define SME0230_TRAFFICLIGHT_INPUT_H

#include "board.h"
#include "main.h"
#include <stdio.h>

//Return 1 if the int passed corresponds to a char of a valid row number,
//otherwise return 0
int is_row_valid(int);

//Return 1 if the int passed corresponds to a char of a valid column letter,
//otherwise return 0
int is_column_valid(int);

//Validate if input row and column numbers are both valid
int validate_input(int []);

//change move from ascii code to index of desired row and column
void index_move(int []);

//Flushes any extra chars input by user
void flush_std_in(void);

//Get player's desired move, validates it, and stores it in move
//Get player's desired move
//returns 0 if all is successful
//returns -1 if user wants to quit
int get_move(int [], t_board, int player);

#endif
