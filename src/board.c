/* Natalie Menato
   Numero USP: 10295051
   07/05/2017
   Submissao para Trabalho Parte 2  */

#include <stdio.h>
#include "main.h"

// Prints the board that was passed to the function to the screen.
void print_board(t_board board) {
    int i, j;
    printf("\n\nCurrent board\n    A   B   C   D\n");
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


// Clears all positions of the board
int clear_board(t_board *board) {
    int i, j;

    for (i = 0; i < ROW_SIZE; i++)
        for (j = 0; j < COLUMN_SIZE; j++)
            board->elements[i][j] = 0;

    return TRUE;
}

//check if it is possible to play at desired position
int valid_board_move(int move[2], t_board board) {
    //is valid if the spot move[0], move[1] has a value < 3
    if (board.elements[move[0]][move[1]] < 3)
        return TRUE;
    return FALSE;
}

//updates the board with the latest move
void update_board(int move[2], t_board *board) {
    board->elements[move[0]][move[1]]++;

}

//return TRUE if more possible moves, FALSE if there are no more possible moves
int remaining_moves(t_board board) {
    int i, j;
    for (i = 0; i < ROW_SIZE; i++) {
        for (j = 0; j < COLUMN_SIZE; j++) {
            if (board.elements[i][j] < 3)
                return TRUE;
        }
    }
    return FALSE;
}

//return TRUE if last move caused player to win game, FALSE otherwise
int won_game(t_board board, int move[2]) {
    if (check_column(board, move[1]) == TRUE) {
        return TRUE;
    } else if (check_row(board, move[0]) == TRUE) {
        return TRUE;
    } else if (check_diagonal(board, move) == TRUE) {
        return TRUE;
    } else {
        return FALSE;
    }

}

//check if a user has won in a column, return TRUE if yes, otherwise FALSE
int check_column(t_board board, int col) {
    int i;
    int piece = board.elements[0][col];
    for (i = 1; i < ROW_SIZE; i++) {
        if (board.elements[i][col] != piece) {
            return FALSE;
        }
    }
    return TRUE;
}

//check if a user has won in a row, return TRUE if yes, otherwise FALSE
int check_row(t_board board, int row) {

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


int dec_diag(t_board board, int move[2]) {
    int i, ind_row, ind_column, value;
    ind_row = 0;
    if (move[1] - move[0] >= 0) {
        ind_column = move[1] - move[0];
        value = board.elements[ind_row][ind_column];
        for (i = 1; i < 3; i++) {
            if (board.elements[ind_row + i][ind_column + i] != value)
                return FALSE;
        }
        return TRUE;
    }
    return FALSE;
}

int inc_diag(t_board board, int move[2]) {
    int i, ind_row, ind_column, value;
    ind_row = 0;
    if (move[1] - move[0] >= 2 && move[1] - move[0] <= 3) {
        ind_column = move[1] - move[0];
        value = board.elements[ind_row][ind_column];
        for (i = 1; i < 3; i++) {
            if (board.elements[ind_row + i][ind_column - i] != value)
                return FALSE;
        }
        return TRUE;
    }
    return FALSE;
}


//check if user won in diagonal, return TRUE if yes, otherwise FALSE
int check_diagonal(t_board board, int move[2]) {
    if (dec_diag(board, move) == TRUE)
        return TRUE;
    else if (inc_diag(board, move) == TRUE)
        return TRUE;
    return FALSE;


}