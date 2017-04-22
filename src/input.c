/* Natalie Menato
   Numero USP: 10295051
   22/04/2017
   Submissao para Trabalho Parte 1  */

#include "input.h"

//Verify if the first entered char is a valid row number
int is_row_valid(int row) {
    if (row >= 0 && row < ROW_SIZE) {
        return TRUE;
    }
    return FALSE;
}

//Verify if the second entered char is a valid column letter
int is_column_valid(int col) {
    if (col >= 0 && col < COLUMN_SIZE)
        return TRUE;
    return FALSE;
}

//Validate if input row and column numbers are both valid
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

//Flushes any extra chars input by user
void flush_std_in(void) {
    int ch;
    while (((ch = getchar()) != '\n') && (ch != EOF));
}

//Get player's desired move, validates it, and stores it in move
//Returns -1 if move is invalid, 0 if move is valid
int get_move(int *move, t_board board) {
    //store int related to char based on ASCII
    int row, column;
    int is_valid_input;

    printf("Please enter your move."
                   " Enter it as row and then column with no space."
                   " For example (3B): ");

    //read the first two input chars
    row = getchar();
    column = getchar();

    //Discard any chars input after the first two
    flush_std_in();

    //store input values in move
    move[0] = row;
    move[1] = column;

    //validate if valid format and valid position
    is_valid_input = validate_input(move);
    if (is_valid_input == TRUE) {
        if (valid_board_move(move, board) == TRUE) {
            return 0;
        } else {
            printf("Not a valid position! \n");
            return -1;
        }
    }
    //loop to get input from user with valid format
    while (is_valid_input == FALSE) {
        printf("Not a valid input format. Try again: ");

        //read the first two input chars
        row = getchar();
        column = getchar();

        //Discard any chars input after the first two
        flush_std_in();

        move[0] = row;
        move[1] = column;

        //validate format and if valid move
        is_valid_input = validate_input(move);
        if (is_valid_input == TRUE) {
            if (valid_board_move(move, board) == TRUE) {
                return 0;
            } else {
                printf("Not a valid position! \n");
                return -1;
            }
        }
    }
    return 0;
}
