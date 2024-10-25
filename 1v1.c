#include <stdio.h>
#include <ctype.h>
#include "file-header.h"

const char PLAYER_1 = 'X';
const char PLAYER_2 = 'O';

void friend_1Move()
{
    int n;
loop:
    printf("PLAYER 1 - Enter Your Position  : \n");
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
                        array[i][j] = PLAYER_1;
                        break;
                    }
                } while (array[i][j] != ' ');
            }
            else
            continue;
        }
    }
}
void friend_2Move()
{
    int n;
loop:
    printf("PLAYER 2 - Enter Your position : \n");
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
                        array[i][j] = PLAYER_2;
                        break;
                    }
                } while (array[i][j] != ' ');
            }
            else
            continue;
        }
    }
}

void print1v1(char winner)
{
    if (winner == PLAYER_1)
        printf("PLAYER 1 WINS");
    else if (winner == PLAYER_2)
        printf("PLAYER 2 WINS");
    else
        printf("A TIE");
}