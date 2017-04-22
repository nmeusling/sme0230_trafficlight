//
// Created by nmeusling on 4/21/17.
//

#ifndef MAIN_H
#define MAIN_H

#define TRUE 1
#define FALSE 0

#include "board.h"

void get_move(int *, t_board);

void flush_std_in(void);

int validate_input(int *);

void index_move(int *);


#endif
