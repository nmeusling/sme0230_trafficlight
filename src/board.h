/* Natalie Menato
   Numero USP: 10295051
   22/04/2017
   Submissao para Trabalho Parte 1  */

#ifndef BOARD_H
#define BOARD_H


#define ROW_SIZE 3
#define COLUMN_SIZE 4

#include "main.h"

typedef struct {
    int elements[ROW_SIZE][COLUMN_SIZE];
} t_board;

void print_board(t_board);

int clear_board(t_board *);

int valid_board_move(int *, t_board);

void update_board(int *, t_board *);

int remaining_moves(t_board);

#endif
