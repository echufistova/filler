# filler
Filler is an algorithmic game which consists in filling a grid of a known size in advance with pieces of random size and shapes, without the pieces being stacked more than one square above each other and without them exceeding the grid. If one of these conditions is not met, the game stops.

There are 3 types of a map. Small, medium and the biggest.

The goal of this project is to create a filler player to win:
- It reads the board and the game pieces placed on the standard output.
- Each turn the filler rewrites the board map and includes a new piece to be placed.
- In order to place the game piece on the board, the player will have to write it’s coordinates on the standard ouput.
- You will collect points each time you place a piece.

To check the work of the project you need to compile it.
In the root of repository write "make" in your terminal, press Enter and then exe named "ychufist.filler" will be created. Then go to diectory to_test. To start write: "/filler_vm -p1 ../ychufist.filler -p2 players/chosen_player -v -f maps/map00" in the terminal, where chosen_player can be chosen by you from the directory players and map00/map01/map02 - from directory maps.
