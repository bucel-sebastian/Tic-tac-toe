#include <stdio.h>

char board[3][3];
char currentPlayer = 'X';

// Inițializarea tablei de joc cu spații goale
void initializeBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

// Afișarea tablei de joc
void displayBoard()
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2)
        {
            printf("-----------\n");
        }
    }
    printf("\n");
}

// Verificarea dacă jocul a fost câștigat de un jucător sau este remiză
int checkWin()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
        {
            return 1;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
        {
            return 1;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
    {
        return 1;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
    {
        return 1;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return 0;
            }
        }
    }

    return -1;
}

int main()
{
    initializeBoard();
    int row, col, result;

    printf("Jocul Tic-tac-toe\n");

    while (1)
    {
        displayBoard();
        printf("Jucătorul %c, introdu rândul și coloana (ex. 1 2): ", currentPlayer);
        scanf("%d %d", &row, &col);

        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ')
        {
            printf("Mișcare invalidă. Vă rugăm să alegeți din nou.\n");
            continue;
        }

        board[row - 1][col - 1] = currentPlayer;
        result = checkWin();

        if (result == 1)
        {
            displayBoard();
            printf("Jucătorul %c a câștigat! Felicitări!\n", currentPlayer);
            break;
        }
        else if (result == -1)
        {
            displayBoard();
            printf("Jocul s-a încheiat cu remiză.\n");
            break;
        }

        // Schimbăm jucătorul curent
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
