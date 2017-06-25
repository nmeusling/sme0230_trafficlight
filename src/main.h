/** @file main.h
 *  @brief Header file for main function, containing all struct definitions
 *
 *  This file contains the structs that will be used in other functions and
 *  defines the constants, TRUE, FALSE, ROW_SIZE and COLUMN_SIZE that will
 *  be used throughout the program.
 *
 *  @author Natalie Menato (10295051)
 */


#ifndef MAIN_H
#define MAIN_H

#define TRUE 1
#define FALSE 0
#define ROW_SIZE 3
#define COLUMN_SIZE 4

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/** @struct t_board
 *  @brief Stores the state of the board
 *  @var t_board::elements
 *  Member 'elements' matrix that stores pieces on board
 */
typedef struct {
    int elements[ROW_SIZE][COLUMN_SIZE];
} t_board;

/** @struct t_move
 *  @brief Stores the desired location of a move
 *  @var t_board::row
 *  Member 'row' stores the index of the row of move
 *  @var t_board::column
 *  Member 'column' stores the index of the column of move
 */
typedef struct {
    int row, column;
} t_move;

/** @struct t_possible_moves
 *  @brief Stores all possible valid board moves
 *  @var t_board::possible_moves
 *  Member 'possible_moves' is an array that stores all valid moves for the board
 *  @var t_board::num_moves
 *  Member 'num_moves' contains the current number of valid board moves
 */
typedef struct {
    t_move possible_moves[ROW_SIZE * COLUMN_SIZE];
    int num_moves;

} t_possible_moves;

#endif
