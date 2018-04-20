#include <stdio.h>
#include "move.h"
#include "place.h"
#include "display.h"

int main()
{
  /* Declare variables */

  int x = 4, y = 3;
  int *xpos = &x, *ypos = &y; //Timmy's position
  int jx = 0, jy = 0; //Jujus
  char m;
  int score = 0;
  int map[WIDTH][HEIGHT];
  int length = 1;

    for (char game = 'y'; game != 'n'; )
    {
    draw_map(); //Create borders of game

    /* Create beginning of snake game  */
    length = 1;
    score = 0;//begin score

    /* Initializing the whole array or 'map' to be zero */

      for (int i = 0; i < WIDTH; i++)
        for(int j = 0; j <HEIGHT; j++)
            map[i][j] = 0;

        /* Place the symbols for Timmy and jujus */

        place (&jx, &jy);
        draw_symbol(x, y,'O');
        map[x][y] = length;

        /* Place juju */

        draw_symbol(jx, jy,'$');
        map[jx][jy] = -1;

        /* Game functions while alive */

        while (m != 'q')
        {
            m = move(xpos, ypos, map, length);


            /* Collect jujus when Timmy and jujus share the same location */

            if (jx == x && jy == y)
            {
                length = length + 1; //Adds one to the length
                score += 1; //For each juju collected, the score increases by one point
                place (&jx, &jy); //Reposition new juju
                draw_symbol(jx, jy,'$'); //Create juju
                map[jx][jy] = -1;

                /*  Increase counter of snake's body  */

                for (int i = 0; i < WIDTH; i++)
                {
                        for(int j = 0; j <HEIGHT; j++)
                        {
                                if (map[i][j] > 0)
                                        map[i][j] += 1;
                        }
                }

            }

    /* As long as Timmy's width is within the borders add 1 */

    for (int i = 0; i < WIDTH; i++)
    {
        /* As long as Timmy's height is within the borders add 1 */

        for(int j = 0; j < HEIGHT; j++)
            {
                /* Draw juju if the number of Timmy's current spot is less than 0 */

                if (map[i][j] < 0)
                    {draw_symbol(i, j, '$');
                    }

                /* Draw addition to body when Timmy's current spot is greater than 0 */

                else if (map[i][j] > 0)
                    {draw_symbol(i, j, 'o');
                    map[i][j] -= 1;
                    }

                /* Draw head when if Timmy's current spot is equal to the number of the length */


                else if (map[i][j] == length)
                    {draw_symbol(i, j, 'O');
                    map[i][j] -= 1;
                    }

                /* Create blank space when Timmy's current spot is equal to 0 to "delete" last portion of snake */

                else if (map[i][j] == 0)
                    draw_symbol(i, j, ' ');

            }
    }
            /* Display Timmy's current position */

            display_pos(x, y);

            /* Display player's current score */

            display_score(score);

        }

    /*  Create text  */
    draw_symbol(WIDTH + 1, 2, ' ');
    printf(" n = quit,Any key = continue");

    /*  Prevents move function from returning 'q'  */
    m = 'e';

/*  Sets highscore  */
FILE *highscore;
int hs;
      highscore = fopen("hsfile", "r");
      fscanf(highscore, "%d", &hs);
      fclose(highscore);
/*  Replaces previous high score with new highscore  */
if (score > hs)
{       highscore = fopen("hsfile", "w");
        fprintf(highscore, "%d", score);
        fclose(highscore);
}

    scanf("%c", &game);//Decide to continue or quit

    /* Clear the screen after gameplay */

    clear_screen();
    }
        /*  Print highscore  */
        FILE *highscore;
        int hs;
        highscore = fopen("hsfile", "r");
        fscanf(highscore, "%d", &hs);
        printf("Current high score is %d\n", hs);
        fclose(highscore);

        /*  END  */
        return 0;
}
