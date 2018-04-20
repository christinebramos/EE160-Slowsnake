//File: display.h
//By: jbyoung
//Date: 16 March 2017

/* display module for gsnake */

/* Dimensions of the map */
#define WIDTH 40 
#define HEIGHT 20
/* NOTE: if you change these values, the board won't change size */

#define TIMMY 'o'
#define JUJU '$'
#define MOOK 'M'

void draw_map();
/* This function initalizes the game board. It should be called at the 
 * beginging of the game. It also intializes one-key input (no need press
 * enter)
 * Given: Nothing
 * Returns: Nothing */

void clear_screen();
/* This function terminates the dislpay. It should be called at the end
 * of the game.
 * Given: Nothing
 * Returns: Nothing */

void draw_symbol(int x, int y, char sym);
/* This function draws a symbol on the map at the specified coordinates.
 * The origin is in the upper lefthand corner. x increases going right, and
 * y increases going down.
 * Given: (x,y) position and symbol to print.
 * Returns: nothing. */

void display_pos(int x, int y);
/* This function displays the position (x,y) below the map
 * Given: (x,y) 
 * Returns: nothing */

void display_score(int score);
/* This function will display the score on the line below where the position
 * could be shown.
 * Given: score
 * Returns: nothing */

void debug_num(int line, float num);
/* This function will print a number on the specified line. It can be used
 * to help you debug things. For versitiality, the number is specified as a
 * float, if you want to print an integer, cast your varaible when you pass it.
 * If the line number corresponds to one where the board exists, it will print
 * on the side of the map. Note the line number is not the same as the y 
 * coordinate.
 * Given: line number and a number to print
 * Returns: nothing */

void debug_wds(int line, char *wds);
/* This function will print some words on the specified line. It can be used
 * to help you debug things. The words to print are denoted by  "".
 * If the line number corresponds to one where the board exists, it will print
 * on the side of the map. Note the line number is not the same as the y 
 * coordinate.
 * Given: line number and words to print
 * Returns: nothing */
