//
// Created by nmeusling on 6/3/17.
//

#ifndef AI_H
#define AI_H

#include "board.h"

t_possible_moves possible_moves(t_board board);
//returns all a struct with all of the possible moves, given the passed board

//int can_win(t_board board, t_possible_moves poss_moves);

t_move computer_move(t_board board);

void random_move(t_move *, t_board);
// Saves a valid, random move to move

int score_move(t_board board, t_move move);

//t_possible_moves * prevent_win(t_board, t_possible_moves);

#endif //SME0230_TRAFFICLIGHT_AI_H
