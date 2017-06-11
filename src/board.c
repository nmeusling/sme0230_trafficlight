/* Natalie Menato
   Numero USP: 10295051
   31/05/2017
   Submissao para Trabalho Parte 3  */

#include "board.h"

void print_board(t_board board) {
// Prints the board that was passed to the function to the screen.
    int i, j;
    printf("\n    A   B   C   D\n");
    printf("   ---------------\n");
    for (i = 0; i < ROW_SIZE; i++) {
        for (j = 0; j < COLUMN_SIZE; j++) {

            if (j == 0) {
                printf("%d |", i + 1);
            }
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

int clear_board(t_board *board) {
// Clears the board so each position has value 0
    int i, j;

    for (i = 0; i < ROW_SIZE; i++)
        for (j = 0; j < COLUMN_SIZE; j++)
            board->elements[i][j] = 0;

    return TRUE;
}

int valid_board_move(t_move move, t_board board) {
//check if it is possible to play at desired position
// is valid if the value of the board at row column is < 3
    if (board.elements[move.row][move.column] < 3)
        return TRUE;
    return FALSE;
}


void update_board(t_move move, t_board *board) {
//updates the board based on the last move
    board->elements[move.row][move.column]++;

}

void undo_move(t_move move, t_board *board) {
    board->elements[move.row][move.column]--;
}


int won_game(t_board board, t_move move) {
//return TRUE if last move caused player to win game, FALSE otherwise
    if (check_column(board, move.column) == TRUE) {
        return TRUE;
    } else if (check_row(board, move.row) == TRUE) {
        return TRUE;
    } else if (check_diagonal(board, move) == TRUE) {
        return TRUE;
    } else {
        return FALSE;
    }

}

int check_column(t_board board, int col) {
//check if a user has won in a column, return TRUE if yes, otherwise FALSE
    int i;
    int piece = board.elements[0][col];
    if (piece == 0)
        return 0;
    for (i = 1; i < ROW_SIZE; i++) {
        if (board.elements[i][col] != piece) {
            return FALSE;
        }
    }
    return TRUE;
}


int check_row(t_board board, int row) {
//check if a user has won in a row, return TRUE if yes, otherwise FALSE
    //in order to win by a row, the two middle columns must be equal
    if (board.elements[row][1] != board.elements[row][2]) {
        return FALSE;
    }
    //if either of the two middle elements are blank, it is not possible to win
    if (board.elements[row][1] == 0 || board.elements[row][2] == 0)
        return FALSE;
    //two middle elements are equal, and not blank, test if either first or last element is also equal
    if (board.elements[row][0] == board.elements[row][2]
        || board.elements[row][3] == board.elements[row][2]) {
        return TRUE;
    }
    return FALSE;
}


int dec_diag(t_board board, t_move move) {
//if the decreasing diagonal has three in a row return TRUE if yes, else return FALSE
    int i, ind_row, ind_column, value;
    ind_row = 0;
    //if the difference between the column and the row is not 0 or 1, the diagonal does not have three places
    if (move.column - move.row >= 0 && move.column - move.row <= 1) {
        //change to the column associated with the first row of the diagonal
        ind_column = move.column - move.row;
        value = board.elements[ind_row][ind_column];
        if (value == 0)
            return FALSE;
        //check all row and column pairs of the diagonal
        for (i = 1; i < 3; i++) {
            if (board.elements[ind_row + i][ind_column + i] != value)
                return FALSE;
        }
        return TRUE;
    }
    return FALSE;
}

int inc_diag(t_board board, t_move move) {
//if the increasing diagonal has three in a row return TRUE if yes, else return FALSE
    int i, ind_row, ind_column, value;
    //if the difference between the row and column number is not 2 or 3, the diagonal does not have three places
    ind_column = move.column + move.row;
    ind_row = 0;
    if (ind_column == 2 || ind_column == 3) {
        //change to the column associated with the first row of the diagonal
        value = board.elements[ind_row][ind_column];
        if (value == 0)
            return FALSE;
        //check all row and column pairs of the diagonal
        for (i = 1; i < 3; i++) {
            if (board.elements[ind_row + i][ind_column - i] != value)
                return FALSE;
        }
        return TRUE;
    }
    return FALSE;
}

int check_diagonal(t_board board, t_move move) {
//check if user won in either diagonal, return TRUE if yes, otherwise FALSE
    if (dec_diag(board, move) == TRUE)
        return TRUE;
    else if (inc_diag(board, move) == TRUE)
        return TRUE;
    return FALSE;


}