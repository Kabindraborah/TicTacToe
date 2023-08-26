#include <stdio.h>
#include <stdbool.h>


void displayBoard(char board[3][3]) {
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}


bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

int main() {
    char board[3][3] = { { ' ', ' ', ' ' },
                         { ' ', ' ', ' ' },
                         { ' ', ' ', ' ' } };

    char currentPlayer = 'X';
    int row, col;
    int moves = 0;

    while (moves < 9) {
        displayBoard(board);
        printf("Player %c's turn. Enter row (0-2) and column (0-2): ", currentPlayer);
        
        while (true) {
            if (scanf("%d %d", &row, &col) != 2 || row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
                printf("Invalid move. Try again.\n");
                
                while (getchar() != '\n');
            } else {
                break;
            }
        }

        board[row][col] = currentPlayer;
        moves++;

        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            printf("Player %c wins!\n", currentPlayer);
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    if (moves == 9) {
        displayBoard(board);
        printf("It's a draw!\n");
    }

    return 0;
}
