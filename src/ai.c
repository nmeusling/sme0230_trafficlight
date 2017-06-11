//
// Created by nmeusling on 6/3/17.
//

#include "ai.h"


t_possible_moves possible_moves(t_board board) {
    int i, j;
    t_move move;
    t_possible_moves poss_moves;
    poss_moves.num_moves = 0;

    for (i = 0; i < ROW_SIZE; i++) {
        for (j = 0; j < COLUMN_SIZE; j++) {
            move.row = i;
            move.column = j;
            if (valid_board_move(move, board) == TRUE) {
                poss_moves.possible_moves[poss_moves.num_moves] = move;
                poss_moves.num_moves++;
            }
        }
    }
    return poss_moves;
}

//int can_win(t_board board, t_possible_moves poss_moves) {
//    int i;
//    for (i = 0; i < poss_moves.num_moves; i++) {
//        update_board(poss_moves.possible_moves[i], &board);
//        if (won_game(board, poss_moves.possible_moves[i]) == TRUE) {
//            return i;
//        }
//        undo_move(poss_moves.possible_moves[i], &board);
//    }
//    return -1;
//}
//score how good a move is based on current board, 1 for win, -1 if lets other player win, otherwise 0
int score_move(t_board board, t_move move) {
    int i;
    t_possible_moves player_moves;
    //score each of the possible moves
    update_board(move, &board);
    if (won_game(board, move)) {
        return 1;
    }
    //get possible moves still available after move is made
    player_moves = possible_moves(board);
    for (i = 0; i < player_moves.num_moves; i++) {
        t_move player_move = player_moves.possible_moves[i];
        update_board(player_move, &board);
        if (won_game(board, player_move)) {
            return -1;
        }
        undo_move(player_move, &board);
    }
    undo_move(move, &board);
    return 0;
}

//t_possible_moves * prevent_win(t_board board, t_possible_moves poss_comp_moves){
//    t_possible_moves *good_moves = (t_possible_moves *)malloc(sizeof(t_possible_moves));
//    good_moves->num_moves = 0;
//    int i, j, player_win = FALSE;
//    t_possible_moves *player_moves = (t_possible_moves *)malloc(sizeof(t_possible_moves));
//    player_moves->num_moves = 0;
//    for(i = 0; i < poss_comp_moves.num_moves; i++){
//        //update board to reflect comp move
//        update_board(poss_comp_moves.possible_moves[i], &board);
//        //check each possible player move
//        player_moves = possible_moves(board, player_moves);
//        //check if player can win, if so, computer move is not a good move
//        for(j=0; j < player_moves->num_moves; j++){
//            if(can_win(board, *player_moves) > -1) {
//                player_win = TRUE;
//                break;
//            }
//            update_board(player_moves->possible_moves[j], &board);
//            if(won_game(board, player_moves->possible_moves[j]) == TRUE){
//                undo_move(player_moves->possible_moves[j], &board);
//                player_win = TRUE;
//                break;
//        }
//        //if it is not possible for player to win after computer move, add computer move to good moves
//        if(player_win == FALSE){
//            good_moves->possible_moves[good_moves->num_moves] = poss_comp_moves.possible_moves[i];
//            good_moves->num_moves++;
//        }
//        //undo move to check next possible comp move
//        undo_move(poss_comp_moves.possible_moves[i], &board);
//    }
//    return good_moves;
//}

t_move computer_move(t_board board) {
//    poss_moves = possible_moves(board, poss_moves);
//    t_possible_moves *best_moves;
//    int win_move = can_win(board, *poss_moves);
//    //if computer can win this turn, make move and return 0
//    if (win_move >= 0) {
//        move->row = poss_moves->possible_moves[win_move].row;
//        move->column = poss_moves->possible_moves[win_move].column;
//        return 0;
//    }
//    best_moves = prevent_win(board, *poss_moves);
//    //no moves where player will not win
//    if(best_moves->num_moves == 0){
//        random_move(move, board);
//        return -1;
//    }
//    move->row = best_moves->possible_moves[0].row;
//    move->column = best_moves->possible_moves[0].column;
//    return 0;

    int i;
    t_move comp_move;
    t_possible_moves poss_moves;
    poss_moves = possible_moves(board);
    int ind_best_score = 0;
    int best_score = score_move(board,
                                poss_moves.possible_moves[ind_best_score]);
    //evaluate each possible computer move
    for (i = 1; i < poss_moves.num_moves; i++) {
        int score = score_move(board, poss_moves.possible_moves[i]);
        if (score > best_score) {
            ind_best_score = i;
            best_score = score;
        }
    }
    comp_move = poss_moves.possible_moves[ind_best_score];
    return comp_move;
}

void random_move(t_move *move, t_board board) {
// Saves a valid, random move to move
    move->row = rand() % ROW_SIZE;
    move->column = rand() % COLUMN_SIZE;
    while (valid_board_move(*move, board) == FALSE) {
        move->row = rand() % ROW_SIZE;
        move->column = rand() % COLUMN_SIZE;
    }
    return;
}