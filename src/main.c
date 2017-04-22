//
// Created by nmeusling on 4/21/17.
//

#include <stdio.h>
#include "main.h"

int main() {
    //declare t_board struct current_board to store current state of game board
    t_board main_board;

    //initialize the current_board so that all spaces are clear
    clear_board(&main_board);

    //print the current_board
    print_board(main_board);
    int move[2] = {0, 0};
    get_move(move, main_board);
    return 0;
}

//Verify if the first entered char is a valid option
int is_row_valid(int row) {
    if (row >= 0 && row <= ROW_SIZE) {
        return TRUE;
    }
    return FALSE;
}

//Verify if the second entered char is a valid option
int is_column_valid(int col) {
    if (col >= 0 && col <= COLUMN_SIZE)
        return TRUE;
    return FALSE;
}

/* validates if desired position is valid returns 1 if true, 0 if false*/
int validate_input(int *move) {
    index_move(move);
    if ((is_row_valid(move[0]) == TRUE) && (is_column_valid(move[1]) == TRUE))
        return TRUE;
    return FALSE;
}

//change move from ascii code to index of desired row and column
void index_move(int *move) {
    // Using ASCII code, '1' - 49, '2' - 50, '3' - 51
    // '1' will become 0, '2' will become 1, '3' will become 2
    move[0] -= 49;
    // Using ASCII code 'a' - 'd' = 97-100, 'A' - 'D' = 65-68
    // 'A' or 'a' will become 0. 'D' or 'd' will become 3.
    if (move[1] >= 97)
        move[1] -= 97;
    else
        move[1] -= 65;
}

//Get player's desired move
void get_move(int *move, t_board board) {
    //store int related to char based on ASCII
    int row, column;
    int is_valid = FALSE;
    int is_valid_input;
    int is_valid_move;

    printf("Please enter your move."
                   " Enter it as row and then column with no space."
                   " For example (3B): ");
    row = getchar();
    column = getchar();
    flush_std_in();

    move[0] = row;
    move[1] = column;

    is_valid_input = validate_input(move);
    if (is_valid_input == TRUE)
        if (valid_board_move(move, board) == TRUE)
            is_valid = TRUE;

    while (is_valid == FALSE) {
        if (is_valid_input == FALSE) {
            printf("\nNot a valid input format. Try again: ");
        } else {
            is_valid_move = valid_board_move(move, board);
            if (is_valid_move == FALSE)
                printf("\nThat is not a legal move! Try again: \n");
        }
        //read the first two input chars
        row = getchar();
        column = getchar();
        //Discard any chars input after the first two
        flush_std_in();

        move[0] = row;
        move[1] = column;
        is_valid_input = validate_input(move);
        if (is_valid_input == TRUE)
            if (valid_board_move(move, board) == TRUE)
                is_valid = TRUE;


    }
}

void flush_std_in(void) {
    int ch;
    while (((ch = getchar()) != '\n') && (ch != EOF));
}
