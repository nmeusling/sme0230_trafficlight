# Traffic Light

Repository for the final project for *SME0230* - traffic light game for
Introdução a Programação de Computadores de USP São Carlos.

## How to run it

* Using terminal navigate to the root of this project.
* Then execute: ```make```
* The binary file will be created on root folder. 
* To run the program, simply execute: ```./trafficlight```

## About the project

The work will be completed in four parts, described below.

### Part 1

Displays a menu with basic game instructions.

Asks a user for input. It verifies if the input is in a valid format and will
continue to prompt the user for input until it has a valid format. The format
is considered valid if the input position is within the game grid. For example,
4D is invalid because the grid has only three rows. 3D is valid since the game
grid has 3 rows and 4 columns.

The input is then validated to see if it is a valid move. A move is valid if it
is to a position that does not already contain the highest possible piece (#).
If the move is invalid, execution is stopped. If the move is valid, the
updated game board is displayed.
