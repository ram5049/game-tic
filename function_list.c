#include <stdio.h>
#include <ctype.h>
#include "file-header.h"

void print()
{
    printf("  %c  |  %c  |  %c  ", array[0][0], array[0][1], array[0][2]);
    printf("\n-----|-----|-----\n");
    printf("  %c  |  %c  |  %c  ", array[1][0], array[1][1], array[1][2]);
    printf("\n-----|-----|-----\n");
    printf("  %c  |  %c  |  %c  ", array[2][0], array[2][1], array[2][2]);
    printf("\n");
}

void printprotoType()
{
    printf("The Format Of The Game Is : \n");
    printf("  %d  |  %d  |  %d  ", protoType[0][0], protoType[0][1], protoType[0][2]);
    printf("\n-----|-----|-----\n");
    printf("  %d  |  %d  |  %d  ", protoType[1][0], protoType[1][1], protoType[1][2]);
    printf("\n-----|-----|-----\n");
    printf("  %d  |  %d  |  %d  ", protoType[2][0], protoType[2][1], protoType[2][2]);
    printf("\n");
}

void set_to_new()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            array[i][j] = ' ';
        }
    }
}

char condition()
{
    for (int i = 0; i < 3; i++)
    {
        if (array[i][0] == array[i][1] && array[i][0] == array[i][2] && array[i][0] != ' ')
            return array[i][0];
    }
    for (int i = 0; i < 3; i++)
    {
        if (array[0][i] == array[1][i] && array[0][i] == array[2][i] && array[0][i] != ' ')
            return array[0][i];
    }
    if (array[0][0] == array[1][1] && array[0][0] == array[2][2] && array[0][0] != ' ')
        return array[0][0];

    if (array[0][2] == array[1][1] && array[0][2] == array[2][0] && array[0][2] != ' ')
        return array[0][2];
    return ' ';
}

int ifSpaceLeft()
{
    int freeSpace = 9;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (array[i][j] != ' ')
                freeSpace--;
        }
    }
    return freeSpace;
}
