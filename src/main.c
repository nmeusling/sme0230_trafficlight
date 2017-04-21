//
// Created by nmeusling on 4/21/17.
//

#include <stdio.h>

#define ROWS 3
#define COLUMNS 4

/* function declaration */

//int[][] initialize_board (  );
typedef struct {
    int board_pieces[ROWS][COLUMNS];
} brd;

void print_board(brd board);

brd clear_board(brd board);



int main() {
    //declare brd struct current_board to store current state of game board
    int board_array[ROWS][COLUMNS];
    brd current_board = {board_array};

    //initialize the current_board so that all spaces are clear
    current_board = clear_board(current_board);

    //print the current_board
    print_board(current_board);

    return 0;
}

/* Prints the board that was passed to the function to the screen. */
void print_board(brd board) {
    int i, j;
    printf(" ---------------\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {

            if (board.board_pieces[i][j] == 0) {
                printf("| %c ", ' ');
            } else if (board.board_pieces[i][j] == 1) {
                printf("| %c ", '-');
            } else if (board.board_pieces[i][j] == 2) {
                printf("| %c ", '+');
            } else {
                printf("| %c ", '#');
            }

            if (j == COLUMNS - 1) {
                printf("|");
            }

        }
        printf("\n ---------------\n");
    }


}

/* Clears all positions of the board */
brd clear_board(brd board) {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            board.board_pieces[i][j] = 0;
        }
    }
    return board;
}
