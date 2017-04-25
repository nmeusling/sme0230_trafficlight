/* Natalie Menato
   Numero USP: 10295051
   22/04/2017
   Submissao para Trabalho Parte 1  */

#include "main.h"

int main() {
    //allow player to keep placing pieces while true
    int current_player = 1;

    //stores player's desired move
    int move[2] = {-1, -1};

    //declare t_board struct current_board to store current state of game board
    t_board main_board;

    //initialize the current_board so that all spaces are clear
    clear_board(&main_board);

    //print the menu and the current_board
    if (print_menu() == FALSE)
        return 0;


    print_board(main_board);

    //after each play, ask user if they want to place another piece
    while (remaining_moves(main_board) == TRUE) {
        //get_move returns -1 if the user wants to stop playing
        if (get_move(move, main_board, current_player) < 0) {
            return 0;
        }

        //input is valid, board is updated to include move
        update_board(move, &main_board);
        print_board(main_board);
        /*printf("Do you want to place another piece? Y/N: ");

        //get first input character, flush all others
        input = getchar();
        flush_std_in();*/
        if (current_player == 1)
            current_player = 2;
        else
            current_player = 1;
        //if 'y' or 'Y', user will place another piece, otherwise, end execution
        /*if (input == 89 || input == 121) {
            keep_playing = FALSE;
        }*/

    }
    printf("\n\nGame Over: No more possible moves!\n\n");
    return 0;
}

//function to print the game opening with basic instructions for play.
//returns FALSE if the user does not want to start a game, TRUE otherwise
int print_menu() {
    int start_game;
    printf(
            "\n--------------------------------------" \
             "\nWelcome to the Traffic Light Game." \
             "\n--------------------------------------\n\n" \
             "The goal of the game is to place a piece so that there are three " \
             "\nof the same type in a row, column, or diagonal. \n" \
             "\nEach turn, you can place '-' in an empty space, transform a"\
             "\n'-' into a '+', or transform a '+' into a '#'."\
             "\nIf a space contains a '#', no further moves are possible."\
             "\n\nEnter 'Q' to quit at any point.\n\n"\
             "Would you like to start a game? Y/N: ");

    start_game = getchar();
    flush_std_in();
    if (start_game != 89 && start_game != 121) {
        return FALSE;
    }
    return TRUE;
}
