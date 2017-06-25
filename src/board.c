/** @file board.c
 *  @brief Contains functions related to the game board
 *
 *  This file contains the functions related to the board, including printing,
 *  clearing, making a move, and validating if a player has won.
 *
 *  @author Natalie Menato (10295051)
 */

#include "board.h"

/*
 * Prints the board that was passed to the function to the screen.
 */
void print_board(t_board board) {
    int i, j;
    //print column labels
    printf("\n    A   B   C   D\n");
    printf("   ---------------\n");
    for (i = 0; i < ROW_SIZE; i++) {
        for (j = 0; j < COLUMN_SIZE; j++) {
            //print row labels
            if (j == 0) {
                printf("%d |", i + 1);
            }
            //print the board pieces
            if (board.elements[i][j] == 0) {
                printf(" %c |", ' ');
            } else if (board.elements[i][j] == 1) {
                printf(" %c |", '-');
            } else if (board.elements[i][j] == 2) {
                printf(" %c |", '+');
            } else {
                printf(" %c |", '#');
            }
        }
        printf("\n   ---------------\n");
    }
}

/*
 * Clears the board so that each position has value 0.
 */
void clear_board(t_board *board) {
    int i, j;

    for (i = 0; i < ROW_SIZE; i++)
        for (j = 0; j < COLUMN_SIZE; j++)
            board->elements[i][j] = 0;
    return;
}

/*
 * Updates the board to reflect the last move, incrementing the value at given
 * position of board.
 */
void make_move(t_move move, t_board *board) {
    board->elements[move.row][move.column]++;
}

/*
 * Undoes a move, decrementing the value at given position of board.
 */
void undo_move(t_move move, t_board *board) {
    board->elements[move.row][move.column]--;
}

/*
 * Checks if the last move resulted in the player winning the game.
 */
int won_game(t_board board, t_move move) {
    if (check_column(board, move.column) == TRUE) {
        return TRUE;
    } else if (check_row(board, move.row) == TRUE) {
        return TRUE;
    } else if (check_diagonal(board, move) == TRUE) {
        return TRUE;
    }
    return FALSE;

}

/*
 * Checks if the entered column has three of the same pieces.
 */
int check_column(t_board board, int col) {
    int i;
    int piece = board.elements[0][col];
    //if the position is empty, it is not possible to win
    if (piece == 0)
        return 0;
    //see if all values are the same
    for (i = 1; i < ROW_SIZE; i++) {
        if (board.elements[i][col] != piece) {
            return FALSE;
        }
    }
    return TRUE;
}

/*
 * Checks if the entered row has three of the same pieces in a row.
 */
int check_row(t_board board, int row) {
    //if either of the two middle elements are blank, it is not possible to win
    if (board.elements[row][1] == 0 || board.elements[row][2] == 0)
        return FALSE;

    //in order to win by a row, the two middle columns must be equal
    if (board.elements[row][1] != board.elements[row][2]) {
        return FALSE;
    }
    //two middle elements are equal, and not blank, test if either first or last element is also equal
    if (board.elements[row][0] == board.elements[row][2]
        || board.elements[row][3] == board.elements[row][2]) {
        return TRUE;
    }
    return FALSE;
}

/*
 * Checks if the entered move resulted in a win in a diagonal.
 */
int check_diagonal(t_board board, t_move move) {
    if (dec_diag(board, move) == TRUE)
        return TRUE;
    else if (inc_diag(board, move) == TRUE)
        return TRUE;
    return FALSE;
}

/*
 * Checks if the last move resulted in a win in a decreasing diagonal.
 */
int dec_diag(t_board board, t_move move) {
    int i, ind_row, ind_column, value;
    ind_row = 0;
    //if the difference between the column and the row is not 0 or 1, the diagonal does not have three places
    if (move.column - move.row >= 0 && move.column - move.row <= 1) {
        //change to the column associated with the first row of the diagonal
        ind_column = move.column - move.row;
        value = board.elements[ind_row][ind_column];
        //if it is empty, it is not possible to win
        if (value == 0)
            return FALSE;
        //check all row and column pairs of the diagonal
        for (i = 1; i < ROW_SIZE; i++) {
            if (board.elements[ind_row + i][ind_column + i] != value)
                return FALSE;
        }
        return TRUE;
    }
    return FALSE;
}

/*
 * Checks if the last move resulted in a win in an increasing diagonal.
 */
int inc_diag(t_board board, t_move move) {
    int i, ind_row, ind_column, value;
    //change to the column associated with the first row of the diagonal
    ind_column = move.column + move.row;
    ind_row = 0;
    //if the column is not 2 or 3, the move did not belong to one of the increasing diagonals
    if (ind_column == 2 || ind_column == 3) {
        value = board.elements[ind_row][ind_column];
        //if it is empty, it is not possible to win
        if (value == 0)
            return FALSE;
        //check all row and column pairs of the diagonal to see if they are the same
        for (i = 1; i < 3; i++) {
            if (board.elements[ind_row + i][ind_column - i] != value)
                return FALSE;
        }
        return TRUE;
    }
    return FALSE;
}

