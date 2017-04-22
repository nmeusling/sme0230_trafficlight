/* Natalie Menato
   Numero USP: 10295051
   22/04/2017
   Submissao para Trabalho Parte 1  */

#include "main.h"

int main() {
    //allow player to keep placing pieces while true
    int keep_playing = TRUE;
    int input;

    //stores player's desired move
    int move[2] = {-1, -1};

    //declare t_board struct current_board to store current state of game board
    t_board main_board;

    //initialize the current_board so that all spaces are clear
    clear_board(&main_board);

    //print the menu and the current_board
    print_menu();
    print_board(main_board);

    //after each play, ask user if they want to place another piece
    while (keep_playing == TRUE) {
        //get_move returns -1 if the input move is invalid, end execution
        get_move(move, main_board);

        //input is valid, board is updated to include move
        update_board(move, &main_board);
        print_board(main_board);
        printf("Do you want to place another piece? Y/N: ");

        //get first input character, flush all others
        input = getchar();
        flush_std_in();

        //if 'y' or 'Y', user will place another piece, otherwise, end execution
        if (input != 89 && input != 121) {
            keep_playing = FALSE;
        }

    }
    return 0;
}

//function to print the game opening with basic instructions for play.
void print_menu() {
    printf(
            "\n--------------------------------------" \
             "\nWelcome to the Traffic Light Game." \
             "\n--------------------------------------\n\n" \
             "The goal of the game is to place a piece so that there are three " \
             "\nof the same type in a row, column, or diagonal. \n" \
             "\nEach turn, you can place '-' in an empty space, transform a"\
             "\n'-' into a '+', or transform a '+' into a '#'."\
             "\nIf a space contains a '#', no further moves are possible.\n\n");
}
