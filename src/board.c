/* Natalie Menato
   Numero USP: 10295051
   22/04/2017
   Submissao para Trabalho Parte 1  */

#include <stdio.h>
#include "main.h"

/* Prints the board that was passed to the function to the screen. */
void print_board(t_board board) {
    int i, j;
    printf("    A   B   C   D\n");
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


/* Clears all positions of the board */
int clear_board(t_board *board) {
    int i, j;

    for (i = 0; i < ROW_SIZE; i++)
        for (j = 0; j < COLUMN_SIZE; j++)
            board->elements[i][j] = 0;

    return TRUE;
}

//check if it is possible to play at desired position
int valid_board_move(int *move, t_board board) {
    //is valid if the spot move[0], move[1] has a value < 2
    if (board.elements[move[0]][move[1]] < 3)
        return TRUE;
    return FALSE;
}

void update_board(int *move, t_board *board) {
    board->elements[move[0]][move[1]]++;

}

