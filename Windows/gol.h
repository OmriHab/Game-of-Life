#ifndef GOL_H_
#define GOL_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#define BOARDSIZE 50
#define DEAD ' '
#define ALIVE '*'
#define PENDING_DEATH 'p' 	//these characters will not be seen therefore the chars have only a sybolical meaning
#define PENDING_LIFE 'l'	//^^^^
#define inBounds(x,y) ((x)>=0 && (x)<BOARDSIZE && (y)>=0 && (y)<BOARDSIZE)


typedef char Board[BOARDSIZE][BOARDSIZE];


void start_message();
void init_board(Board b); //Returns initialized board with all positions dead
void get_dots(Board b); //Gets from the standard input positions of alive cells
void next(Board b); //Advance to next move
void execute_and_birth(Board b); //Change all the pending deaths to dead and all the pending alive to alive
int num_neighbours(Board b, int x, int y);
void run_game(Board b);
void print_board(Board b);

#endif
