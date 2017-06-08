//
// Created by nmeusling on 6/3/17.
//

#ifndef AI_H
#define AI_H

#include "board.h"

t_possible_moves *possible_moves(t_board board, t_possible_moves *poss_moves);
//returns all a struct with all of the possible moves, given the passed board

int can_win(t_board board, t_possible_moves poss_moves);

int computer_move(t_move *move, t_board board, t_possible_moves *poss_moves);

void random_move(t_move *, t_board);
// Saves a valid, random move to move

#endif //SME0230_TRAFFICLIGHT_AI_H
