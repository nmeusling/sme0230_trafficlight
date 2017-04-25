/* Natalie Menato
   Numero USP: 10295051
   22/04/2017
   Submissao para Trabalho Parte 1  */

#ifndef SME0230_TRAFFICLIGHT_INPUT_H
#define SME0230_TRAFFICLIGHT_INPUT_H

#include "board.h"
#include "main.h"
#include <stdio.h>

int is_row_valid(int);

int is_column_valid(int);

int validate_input(int *);

void index_move(int *);

void flush_std_in(void);

int get_move(int *, t_board, int player);

#endif
