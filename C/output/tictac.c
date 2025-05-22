#include <stdio.h>
#include <conio.h>

void printBorad();
int checkWin();
void system();

char Board[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

void main()
{
    int player = 1, input, status = -1;
    printBorad();

    while (status == -1)
    {
        player = (player % 2 == 0) ? 2 : 1;
        char mark = (player == 1) ? 'X' : 'O';
        printf("please enter number for player %d\n", player);
        scanf("%d", &input);
        if (input < 1 || input > 9)
        {
            printf("invalid input");
        }

        Board[input] = mark;
        printBorad();

        int result = checkWin();

        if (result == 1)
        {
            printf("player %d is the Winner", player);
            return;
        }
        else if (result == 0)
        {
            printf("draw");
            return;
        }

        player++;
    }
}

void printBorad()
{
    system("cls");
    printf("\n\n");
    printf("=== TIC TAC TOE ===\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n",Board[1],Board[2],Board[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n",Board[4],Board[5],Board[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n",Board[7],Board[8],Board[9]);
    printf("     |     |     \n");
    printf("\n\n");
}

int checkWin()
{
    if (Board[1] == Board[2] && Board[2] == Board[3])
    {
        return 1; // Player 1 wins
    }

    if (Board[1] == Board[4] && Board[4] == Board[7])
    {
        return 1; // Player 1 wins
    }

    if (Board[7] == Board[8] && Board[8] == Board[9])
    {
        return 1; // Player 1 wins
    }

    if (Board[3] == Board[6] && Board[6] == Board[9])
    {
        return 1; // Player 1 wins
    }

    if (Board[1] == Board[5] && Board[5] == Board[9])
    {
        return 1; // Player 1 wins
    }

    if (Board[3] == Board[5] && Board[5] == Board[7])
    {
        return 1; // Player 1 wins
    }

    if (Board[2] == Board[5] && Board[5] == Board[8])
    {
        return 1; // Player 1 wins
    }

    if (Board[14] == Board[5] && Board[5] == Board[6])
    {
        return 1; // Player 1 wins
    }

    int count = 0;
    for (int i = 1; i <= 9; i++)
    {
        if (Board[i] == 'X' || Board[i] == 'O')
        {
            count++;
        }
    }

    if (count == 9)
    {
        return 0;
    }
    return -1;
}