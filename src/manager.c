/** @file manager.c
 *  @brief Contains functions related to game management
 *
 *  This file contains the functions related to user input, including getting
 *  the next move and validating it.
 *
 *  @author Natalie Menato (10295051)
 */

#include "manager.h"

/*
 * Clears the board and prints the opening menu, starting a new game.
 */
void begin_game(t_board *board) {
// Clears the board and prints the opening menu.
    clear_board(board);
    print_menu();
}

/*
 * Prints the game opening with basic instructions for play.
 */
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
             "\n\nEnter 'Q' to quit at any point.\n\n");

    return;
}

/*
 * Asks user to choose desired play mode (PvP or PvC)
 */
int get_game_type() {
    int game_type;
    printf("\nEnter '1' for player vs computer mode or '2' for player vs player mode: ");
    game_type = getchar();
    flush_std_in();
    while (game_type != (int) '1' && game_type != (int) '2') {
        if (game_type == (int) 'q' || game_type == (int) 'Q')
            return FALSE;
        printf("Invalid selection. Try again: ");
        game_type = getchar();
        flush_std_in();
    }
    if (game_type == '1')
        return 1;
    return 2;
}

/*
 * Control PvP play until a player wins or quits
 */
int pvp_play(t_board *board) {
    // controls which player is currently playing
    int current_player = 1;

    // stores the next desired move
    t_move move = {-1, -1};

    print_board(*board);

    int continue_playing = TRUE;
    while (continue_playing == TRUE) {
        //get_move returns FALSE if the user chooses to quit with q or Q
        continue_playing = get_move(&move, *board, current_player);
        if (continue_playing == FALSE) {
            return -1;
        }

        make_move(move, board);
        print_board(*board);
        if (won_game(*board, move) == TRUE) {
            printf("\nCongratulations Player %d!! You won the game!\n",
                   current_player);
            return 0;
        }

        current_player = switch_player(current_player);
    }
    return -1;
}


/*
 * Controls PvC play until a player wins or quits
 */
int pvc_play(t_board *board) {

    //player 1 is the computer, player 2 is human player
    int current_player = first_player();
    int first_play = TRUE;
    //returns false if user wants to quit
    if (current_player == 0)
        return FALSE;
    if (current_player == 2) {
        print_board(*board);
    }

    //stores player's desired move
    t_move move = {-1, -1};

    int continue_playing = TRUE;
    while (continue_playing == TRUE) {
        //it is the human player's turn
        if (current_player == 2) {
            //get_move returns FALSE if the user wants to stop playing
            continue_playing = get_move(&move, *board, 0);
            if (continue_playing == FALSE) {
                return -1;
            }

            make_move(move, board);
            print_board(*board);
            if (won_game(*board, move) == TRUE) {
                printf("\nCongratulations Player!! You won the game!\n");
                return 0;
            }
        } else {
            // it is the computer's turn
            if (first_play == TRUE) {
                random_move(&move, *board);
            } else {
                move = computer_move(*board);
            }
            make_move(move, board);
            printf("\n\nThe Computer's Move: %d%c\n", move.row + 1,
                   column_letter(move.column));
            print_board(*board);
            if (won_game(*board, move) == TRUE) {
                printf("\nThe computer won. Try again next time.\n");
                return 0;
            }
        }
        first_play = FALSE;
        current_player = switch_player(current_player);
    }
    return -1;
}

/*
 * Asks player who should have the first move for PvC play
 */
int first_player() {
    int first_player = 0;
    do {
        printf("\nWho should have the first move?\n"\
        "1 - Player, 2 - Computer, 3 - Random: ");
        first_player = getchar();
        flush_std_in();
        if (first_player == (int) 'q' || first_player == (int) 'Q')
            return 0;
    } while (first_player != (int) '1' && first_player != (int) '2' &&
             first_player != (int) '3');
    //player goes first
    if (first_player == '1') {
        return 2;
        //computer goes first
    } else if (first_player == '2') {
        return 1;
        //random choice of first player
    } else {
        return (rand() % 2) + 1;
    }
}

/*
 * Switches which player's turn it is
 */
int switch_player(int current_player) {
    if (current_player == 1)
        return 2;
    else
        return 1;
}

/*
 * Returns column letter based on column index, for printing computer's move
 */
char column_letter(int column) {
    if (column == 0)
        return 'A';
    if (column == 1)
        return 'B';
    if (column == 2)
        return 'C';
    return 'D';
}

