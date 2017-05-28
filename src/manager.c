/* Natalie Menato
   Numero USP: 10295051
   27/05/2017
   Submissao para Trabalho Parte 3  */

#include <stdio.h>
#include "manager.h"
#include "input.h"

//function to print the game opening with basic instructions for play.
//returns FALSE if the user does not want to start a game, TRUE otherwise
void print_menu() {

    printf(
            "\n--------------------------------------" \
             "\nWelcome to the Traffic Light Game." \
             "\n--------------------------------------\n\n" \
             "The goal of the game is to place a piece so that there are three " \
             "\nof the same type in a row, column, or diagonal. \n" \
             "\nEach turn, you can place '-' in an empty space, transform a"\
             "\n'-' into a '+', or transform a '+' into a '#'."\
             "\nIf a space contains a '#', no further moves are possible."\
             " \n\nEnter your moves based on desired row and then column."\
             "\nFor example: '3B'. "\
             "\n\nEnter 'Q' to quit at any point.\n\n"\
             "Would you like to start a game? Y/N: ");

    return;
}

int begin_game(t_board *board) {
    int start_game;

    clear_board(board);

    print_menu();

    start_game = getchar();
    flush_std_in();
    //check input using ASCII, if input is not 'Y' or 'y'
    if (start_game != (int) 'Y' && start_game != (int) 'y') {
        return FALSE;
    }
    return TRUE;
}

int get_game_type() {
    int game_type;
    printf("\nEnter '1' for player vs player mode or '2' for player vs computer mode: ");
    game_type = getchar();
    flush_std_in();
    while (game_type != (int) '1' && game_type != (int) '2') {
        printf("Invalid selection. Try again: ");
        game_type = getchar();
        flush_std_in();
    }
    if (game_type == '1')
        return 1;
    return 2;
}

int pvp_play(t_board *board) {
    //keep track of which player's turn it is
    int current_player = 1;

    //stores player's desired move
    t_move move = {-1, -1};

    print_board(*board);

    while (remaining_moves(*board) == TRUE) {
        //get_move returns -1 if the user wants to stop playing
        if (get_move(&move, *board, current_player) < 0) {
            return FALSE;
        }

        //input is valid, board is updated to include move
        update_board(move, board);
        print_board(*board);
        if (won_game(*board, move) == TRUE) {
            printf("\nCongratulations Player %d!! You won the game!\n",
                   current_player);
            return 0;
        }
        if (current_player == 1)
            current_player = 2;
        else
            current_player = 1;

    }
    printf("\n\nGame Over: No more possible moves!\n\n");
    return FALSE;
}

int pvc_play(t_board *board) {
    srand(time(NULL));
    //keep track of which player's turn it is
    //player 1 is the computer, player 2 is human player
    int current_player = 1;

    //stores player's desired move
    t_move move = {-1, -1};

    //print_board(*board);

    while (remaining_moves(*board) == TRUE) {
        //human player
        if (current_player == 2) {
            //get_move returns -1 if the user wants to stop playing
            if (get_move(&move, *board, current_player) < 0) {
                return FALSE;
            }

            //input is valid, board is updated to include move
            update_board(move, board);
            print_board(*board);
            if (won_game(*board, move) == TRUE) {
                printf("\nCongratulations Player %d!! You won the game!\n",
                       current_player);
                return 0;
            }
        } else {
            move.row = rand() % 3;
            move.column = rand() % 4;
            while (valid_board_move(move, *board) == FALSE) {
                move.row = rand() % 3;
                move.column = rand() % 4;
            }
            update_board(move, board);
            print_board(*board);
            if (won_game(*board, move) == TRUE) {
                printf("\nThe computer won. Try again next time.\n");
                return 0;
            }
        }
        if (current_player == 1)
            current_player = 2;
        else
            current_player = 1;

    }
    printf("\n\nGame Over: No more possible moves!\n\n");
    return FALSE;
}