#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "file-header.h"

const char HUMAN = 'X';
const char AI = 'O';

void humanMove()
{
    int n;
loop:
    printf("Enter the Posotion : \n");
    scanf("%d", &n);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (protoType[i][j] == n)
            {
                do
                {
                    if (array[i][j] != ' ')
                    {
                        printf("INVALID INPUT\n");
                        goto loop;
                    }
                    else
                    {
                        array[i][j] = HUMAN;
                        break;
                    }
                } while (array[i][j] != ' ');
            }
        }
    }
}

void aiMove()
{
    int x, y;
    srand(time(0));
    if (ifSpaceLeft() > 0)
    {
        do
        {
            x = rand() % 3;
            y = rand() % 3;
        } while (array[x][y] != ' ');
        array[x][y] = AI;
    }
    else
    {
        printvComputer(' ');
    }
}




void printvComputer(char winner)
{
    if (winner == HUMAN)
        printf("YOU WON");
    else if (winner == AI)
        printf("YOU LOOSE");
    else
        printf("A TIE");
}

