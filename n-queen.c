#include <stdio.h>
#include <stdbool.h>

// Function to print the chessboard with queen positions
void printBoard(int board[], int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i] == j) {
                printf("Q ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

bool isSafe(int board[], int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || board[i] - i == col - row || board[i] + i == col + row)   
        {
            return false;
        }
    }
    return true;
}

bool solveNQueens(int board[], int row, int N) {
    if (row == N) {
        return true; 
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col; 
            if (solveNQueens(board, row + 1, N)) {
                return true;
            }
            board[row] = -1; 
        }
    }

    return false; 
}

int main() {
    int N;
    printf("Dhurv Varshney\nA2305221157\n");
    printf("Enter the board size (N): ");
    scanf("%d", &N);

    int board[N];
    for (int i = 0; i < N; i++) {
        board[i] = -1; 
    }

    if (solveNQueens(board, 0, N)) {
        printf("Solution exists:\n");
        printBoard(board, N);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}
