//Team: JAC
//Date: 4/13/17
//File: move.c

#include <stdio.h>

/* Include all necessary files */

#include "display.h"
#include "move.h"

char move(int *x, int *y, int map[][HEIGHT], int length)
{

    /* Declare character to move */

    char m;

    /* Get the characters from player in order to move */

    m = getchar();

    /* Account for whitespace/space */

    draw_symbol(*x, *y, ' ');

    switch(m)
    {

        /* Move down */

        case 'w':
        case 'k':
        *y = *y - 1;
        break;

        /* Move left */

        case 'a':
        case 'h':
        *x = *x - 1;
        break;

        /* Move up */

        case 's':
        case 'j':
        *y = *y + 1;
        break;

        /* Move right*/

        case 'd':
        case 'l':
        *x = *x + 1;
        break;

    }


    /* Teleport when Timmy reaches the borders of the game */


    /* Teleport left and right */

    if (*x >= 40)
    {
        *x = 0;
    }
    if(*x <= - 1)
    {
        *x = 39;
    }

    /* Teleport up and down */

    if (*y >= 20)
    {
        *y = 0;
    }
    if(*y <= - 1)
    {
        *y = 19;
    }

    /* Check for an open space */

    if (map[*x][*y] <= 0)
        map[*x][*y] = length;
    
    /* Print GAME OVER if collides with itself */
    
    else
    {
        printf("GAME OVER");
        return 'q';
    }

    return m;

}

