#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int findCelebrity(int mat[MAX][MAX], int n) {
    int stack[MAX];
    int top = -1;

    // Push all people onto the stack
    for (int i = 0; i < n; i++) {
        stack[++top] = i;
    }

    // Eliminate non-celebrities
    while (top > 0) {
        int person1 = stack[top--];
        int person2 = stack[top--];

        if (mat[person1][person2] == 1) {
            // person1 knows person2, so person1 cannot be a celebrity
            stack[++top] = person2;
        } else {
            // person1 does not know person2, so person2 cannot be a celebrity
            stack[++top] = person1;
        }
    }

    // If the stack is empty, there is no celebrity
    if (top == -1) {
        return -1;
    }

    // Check if the remaining person is a celebrity
    int candidate = stack[top];

    for (int i = 0; i < n; i++) {
        if (i != candidate) {
            // A celebrity should not know anyone and should be known by everyone
            if (mat[candidate][i] == 1 || mat[i][candidate] == 0) {
                return -1;
            }
        }
    }

    return candidate;
}

int main() {
    int mat[MAX][MAX], n;

    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);

    printf("Enter the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    int celebrity = findCelebrity(mat, n);

    if (celebrity == -1) {
        printf("No celebrity found.\n");
    } else {
        printf("The celebrity is person %d.\n", celebrity);
    }

    return 0;
}
