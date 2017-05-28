/* Natalie Menato
   Numero USP: 10295051
   27/05/2017
   Submissao para Trabalho Parte 3  */

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
//return TRUE if valid and valid board move
//return 0 if invalid format
//return -1 if invalid board move
int validate_input(t_move *move, t_board board) {
    index_move(move);
    if ((is_row_valid(move->row) == TRUE) &&
        (is_column_valid(move->column) == TRUE)) {
        if (valid_board_move(*move, board) == TRUE) {
            return TRUE;
        }
        return -1;
    }
    return 0;
}

//change move from ascii code to index of desired row and column
void index_move(t_move *move) {
    // Using ASCII code, '1' - 49, '2' - 50, '3' - 51
    // '1' will become 0, '2' will become 1, '3' will become 2
    move->row = move->row - 49;
    // Using ASCII code 'a' - 'd' = 97-100, 'A' - 'D' = 65-68
    // 'A' or 'a' will become 0. 'D' or 'd' will become 3.
    if (move->column >= 97)
        move->column = move->column - 97;
    else
        move->column = move->column - 65;
}

//Flushes any extra chars input by user
void flush_std_in(void) {
    int ch;
    while (((ch = getchar()) != '\n') && (ch != EOF));
}

//Get player's desired move, validates it, and stores it in move
//Get player's desired move
//returns 0 if all is successful
//returns -1 if user wants to quit
int get_move(t_move *move, t_board board, int player) {
    //store int related to char based on ASCII
    int row, column;
    int is_valid;

    printf("Player %d - Please enter your move: ", player);
    row = getchar();
    if (row == (int) 'q' || row == (int) 'Q') {
        return -1;
    }
    column = getchar();
    flush_std_in();

    move->row = row;
    move->column = column;
    //Validate if input row and column numbers are both valid
    //return TRUE if valid and valid board move
    //return 0 if invalid format
    //return -1 if invalid board move
    is_valid = validate_input(move, board);
    while (is_valid != TRUE) {
        if (is_valid == 0) {
            printf("Not a valid input format. Try again: ");
        } else {
            printf("That is not a legal move! Try again: ");
        }
        //read the first two input chars
        row = getchar();
        if (row == (int) 'q' || row == (int) 'Q') {
            return -1;
        }
        column = getchar();
        //Discard any chars input after the first two
        flush_std_in();

        move->row = row;
        move->column = column;
        is_valid = validate_input(move, board);
    }
    return 0;


}

