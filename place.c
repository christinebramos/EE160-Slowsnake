/*
file: place.c
by:
login:
date:
team:   JAC
members:
*/

#include <stdio.h>

/* Include all necessary files */

#include "place.h"
#include "time.h"

/* Account for a different library */
#include "stdlib.h"

void place(int *x, int *y)
{
    
    /* Randomize coordinates */
    
    srand(time(NULL));
    
    /* Create coordinates within the borders of the game */
    
    *x = rand() % 40;
    *y = rand() % 20;

}
