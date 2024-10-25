#include <stdio.h>
#include <ctype.h>
#include "ai.c"
#include "1v1.c"
#include "function_list.c"
int main()
{
    char victor;
    char opt;
    int a = 1, x;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            protoType[i][j] = a;
            a++;
        }
    }
start:
    printf("MODE 1 : v/s Computer");
    printf("\nMODE 2 : v/s Friend\n");
    scanf("%d", &x);
    switch (x)
    {
    case 1:
        do
        {
            victor = ' ';
            opt = ' ';
            set_to_new();
            printprotoType();
            while (victor == ' ' && ifSpaceLeft() != 0)
            {
                humanMove();
                victor = condition();
                if (victor != ' ' || ifSpaceLeft() == 0)
                {
                    break;
                }
                aiMove();
                victor = condition();
                if (victor != ' ' || ifSpaceLeft() == 0)
                {
                    break;
                }

                print();
            }
            print();
            printvComputer(victor);
        sec:
            printf("\nWould you like to play again (Y/N) :\n");
            scanf(" %c", &opt);
            opt = toupper(opt);
        } while (opt == 'Y');
        if (opt == 'N')
            printf("Thanks For Playing!!\n");
        else
        {
            printf("Invalid Instruction");
            goto sec;
        }
        break;
    case 2:
        printf("PLAYER 1 : X\n");
        printf("PLAYER 2 : O\n");
        do
        {
            victor = ' ';
            opt = ' ';
            set_to_new();
            printprotoType();
            while (victor == ' ' && ifSpaceLeft() != 0)
            {
                friend_1Move();
                victor = condition();
                if (victor != ' ' || ifSpaceLeft() == 0)
                {
                    break;
                }
                print();
                friend_2Move();
                victor = condition();
                if (victor != ' ' || ifSpaceLeft() == 0)
                {
                    break;
                }
                print();
            }
            print();

            print1v1(victor);
        sec1:
            printf("\nWould you like to play again (Y/N) :\n");
            scanf(" %c", &opt);
            opt = toupper(opt);
        } while (opt == 'Y');
        if (opt == 'N')
            printf("Thanks For Playing!!\n");
        else
        {
            printf("Invalid Instruction");
            goto sec1;
        }
        break;
    default:
        printf("Invalid Input\n");
        goto start;
    }

    return 0;
}
