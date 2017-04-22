//
// Created by nmeusling on 4/21/17.
//

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

#endif
