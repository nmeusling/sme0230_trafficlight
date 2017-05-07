/* Natalie Menato
   Numero USP: 10295051
   07/05/2017
   Submissao para Trabalho Parte 2  */

#ifndef BOARD_H
#define BOARD_H


#define ROW_SIZE 3
#define COLUMN_SIZE 4

#include "main.h"

//struct to store the game board
typedef struct {
    int elements[ROW_SIZE][COLUMN_SIZE];
} t_board;

// Prints the board that was passed to the function to the screen.
void print_board(t_board);

// Clears all positions of the board
int clear_board(t_board *);

//check if it is possible to play at desired position
int valid_board_move(int *, t_board);

//updates the board with the latest move
void update_board(int *, t_board *);

//return TRUE if more possible moves, FALSE if there are no more possible moves
int remaining_moves(t_board);

#endif
