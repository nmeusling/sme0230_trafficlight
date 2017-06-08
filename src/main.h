/* Natalie Menato
   Numero USP: 10295051
   27/05/2017
   Submissao para Trabalho Parte 3  */

#ifndef MAIN_H
#define MAIN_H

#define TRUE 1
#define FALSE 0


#define ROW_SIZE 3
#define COLUMN_SIZE 4

//struct to store the game board
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

typedef struct {
    int elements[ROW_SIZE][COLUMN_SIZE];
} t_board;

//struct to store moves
typedef struct {
    int row, column;
} t_move;

typedef struct {
    t_move possible_moves[12];
    int num_moves;

} t_possible_moves;

#endif
