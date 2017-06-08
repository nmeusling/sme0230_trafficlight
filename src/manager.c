/* Natalie Menato
   Numero USP: 10295051
   27/05/2017
   Submissao para Trabalho Parte 3  */

#include "manager.h"
#include "input.h"

void print_menu() {
// Prints the game opening with basic instructions for play.
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

void begin_game(t_board *board) {
// Clears the board and prints the opening menu.
    clear_board(board);
    print_menu();
}

int get_game_type() {
// Asks user for play mode (PvP or PvC)
// Returns 1 for PvC, 2 for PvP, 0 to quit program
    int game_type;
    printf("\nEnter '1' for player vs computer mode or '2' for player vs player mode: ");
    game_type = getchar();
    flush_std_in();
    while (game_type != (int) '1' && game_type != (int) '2') {
        if (game_type == (int) 'q' || game_type == (int) 'Q')
            return 0;
        printf("Invalid selection. Try again: ");
        game_type = getchar();
        flush_std_in();
    }
    if (game_type == '1')
        return 1;
    return 2;
}

int pvp_play(t_board *board) {
// Controls PvP play until a player wins or quits
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
            return FALSE;
        }

        update_board(move, board);
        print_board(*board);
        if (won_game(*board, move) == TRUE) {
            printf("\nCongratulations Player %d!! You won the game!\n",
                   current_player);
            return 0;
        }

        current_player = switch_player(current_player);
    }
    return FALSE;
}

int pvc_play(t_board *board) {
// Controls PvC play until a player wins or quits

    //player 1 is the computer, player 2 is human player
    int current_player = 1;

    //stores player's desired move
    t_move move = {-1, -1};

    t_possible_moves *poss_moves = (t_possible_moves *) malloc(
            sizeof(t_possible_moves));
    poss_moves->num_moves = 0;

    int continue_playing = TRUE;
    while (continue_playing == TRUE) {
        //it is the human player's turn
        if (current_player == 2) {
            //get_move returns FALSE if the user wants to stop playing
            continue_playing = get_move(&move, *board, current_player);
            if (continue_playing == FALSE) {
                return FALSE;
            }

            update_board(move, board);
            print_board(*board);
            if (won_game(*board, move) == TRUE) {
                printf("\nCongratulations Player %d!! You won the game!\n",
                       current_player);
                return 0;
            }
        } else {
            // it is the computer's turn
//            random_move(&move, *board);
            computer_move(&move, *board, poss_moves);
//            poss_moves = possible_moves(*board, poss_moves);
            update_board(move, board);
            printf("\n\nThe Computer's Move: %d%c\n", move.row + 1,
                   column_letter(move.column));
            print_board(*board);
            if (won_game(*board, move) == TRUE) {
                printf("\nThe computer won. Try again next time.\n");
                return FALSE;
            }
        }
        current_player = switch_player(current_player);
    }

    return FALSE;
}


int switch_player(int current_player) {
// Switches which player's turn it is
    if (current_player == 1)
        return 2;
    else
        return 1;
}

//void random_move(t_move *move, t_board board) {
//// Saves a valid, random move to move
//    move->row = rand() % 3;
//    move->column = rand() % 4;
//    while (valid_board_move(*move, board) == FALSE) {
//        move->row = rand() % 3;
//        move->column = rand() % 4;
//    }
//    return;
//}

char column_letter(int column) {
// returns column letter based on column index
    if (column == 0)
        return 'A';
    if (column == 1)
        return 'B';
    if (column == 2)
        return 'C';
    return 'D';
}

