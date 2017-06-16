/** @file input.c
 *  @brief Contains functions related to user input
 *
 *  This file contains the functions related to user input, including getting
 *  the next move and validating it.
 *
 *  @author Natalie Menato (10295051)
 */

#include "input.h"

/*
 * Indexes row based on ASCII code.
 */
int index_row(int row) {
    // Using ASCII code, '1' = 49, '2' = 50, '3' = 51
    // '1' will become 0, '2' will become 1, '3' will become 2
    row = row - 49;
    return row;
}

/*
 * Indexes column based on ASCII code.
 */
int index_column(int col) {
    // Using ASCII code 'a' - 'd' = 97-100, 'A' - 'D' = 65-68
    // 'A' or 'a' will become 0. 'D' or 'd' will become 3.
    if (col >= 97)
        col = col - 97;
    else
        col = col - 65;
    return col;
}

/*
 * Verifies if it is possible to play at the desired position.
 */
int valid_board_move(t_move move, t_board board) {
    //desired row belongs to board
    if (move.row < 0 || move.row >= ROW_SIZE)
        return FALSE;
    //desired column belongs to board
    if (move.column < 0 || move.column >= COLUMN_SIZE)
        return FALSE;
    //the highest piece has not yet been placed at the desired position
    if (board.elements[move.row][move.column] < 3)
        return TRUE;
    return FALSE;
}

/*
 * Flushes any extra characters input by the user to prevent input errors from
 * causing runtime errors.
 */
void flush_std_in(void) {
//Flushes any extra chars input by user
    int ch;
    while (((ch = getchar()) != '\n') && (ch != EOF));
}

/*
 * Verifies if user input q or Q and wishes to quit the game.
 */
int quit(int input) {
    if (input == (int) 'q' || input == (int) 'Q')
        return TRUE;
    return FALSE;
}

/*
 * Prompts the user to enter desired moved. Validates the move and stores it
 * in move.
 */
int get_move(t_move *move, t_board board, int player) {
    //Stores int corresponding to input row and column chars
    int row, column;
    int is_valid;
    //For PvC mode
    if (player == 0) {
        printf("\n\nPlayer - Please enter your move: ");
    }
        //For PvP mode
    else {
        printf("\n\nPlayer %d - Please enter your move: ", player);
    }

    //get user input, check if user wants to quit
    row = getchar();
    if (quit(row) == TRUE)
        return FALSE;
    column = getchar();
    if (quit(column) == TRUE)
        return FALSE;
    //Discard any chars input after the first two
    flush_std_in();
    //index move and store to move
    move->row = index_row(row);
    move->column = index_column(column);

    //validate move
    is_valid = valid_board_move(*move, board);
    //if not valid, repeat until valid input is entered
    while (is_valid == FALSE) {

        printf("Not a valid move! Try again: ");

        //read the first two input chars and see if user wants to quit
        row = getchar();
        if (quit(row) == TRUE)
            return FALSE;
        column = getchar();
        if (quit(column) == TRUE)
            return FALSE;
        //Discard any chars input after the first two
        flush_std_in();
        //index move and store to move
        move->row = index_row(row);
        move->column = index_column(column);
        //validate move
        is_valid = valid_board_move(*move, board);
    }
    return TRUE;
}

