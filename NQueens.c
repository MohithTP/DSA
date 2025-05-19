#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int board[MAX];
int solcount = 0;
int N;

int isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

void printSol() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

void solve(int row) {
    if (row == N) {
        solcount++;
        printSol();
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solve(row + 1);
        }
    }
}

int main() {
    printf("Enter No. of Queens (up to %d): ", MAX);
    scanf("%d", &N);

    if (N < 4) {
        printf("No possible solution found for %d-Queens problem\n", N);
        return 0;
    }

    solve(0);
    printf("Total number of solutions for %d-Queens problem: %d\n", N, solcount);

    return 0;
}
