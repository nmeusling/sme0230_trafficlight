//
// Created by nmeusling on 6/3/17.
//

#include "ai.h"

t_possible_moves *possible_moves(t_board board, t_possible_moves *poss_moves) {
    int i, j;
    t_move move;
    poss_moves->num_moves = 0;

    for (i = 0; i < ROW_SIZE; i++) {
        for (j = 0; j < COLUMN_SIZE; j++) {
            move.row = i;
            move.column = j;
            if (valid_board_move(move, board) == TRUE) {
                poss_moves->possible_moves[poss_moves->num_moves] = move;
                poss_moves->num_moves++;
            }
        }
    }
    return poss_moves;
}

int can_win(t_board board, t_possible_moves poss_moves) {
    int i;
    for (i = 0; i < poss_moves.num_moves; i++) {
        update_board(poss_moves.possible_moves[i], &board);
        if (won_game(board, poss_moves.possible_moves[i]) == TRUE) {
            return i;
        }
        undo_move(poss_moves.possible_moves[i], &board);
    }
    return -1;
}

int computer_move(t_move *move, t_board board, t_possible_moves *poss_moves) {
    poss_moves = possible_moves(board, poss_moves);
    int win_move = can_win(board, *poss_moves);
    //if it is not possible to win, make a random move and return -1
    if (win_move == -1) {
        random_move(move, board);
        return -1;
    } else {
        move->row = poss_moves->possible_moves[win_move].row;
        move->column = poss_moves->possible_moves[win_move].column;
    }
    //if it is possible to win, make winning move and return 0
    return 0;
}

void random_move(t_move *move, t_board board) {
// Saves a valid, random move to move
    move->row = rand() % 3;
    move->column = rand() % 4;
    while (valid_board_move(*move, board) == FALSE) {
        move->row = rand() % 3;
        move->column = rand() % 4;
    }
    return;
}