#include <stdio.h>
#define Max 100

int op[Max];

void insert(int *f, int *r, int x) {
    if ((*r + 1) % Max == *f) {
        printf("Queue is full\n");
        return;
    }
    if (*f == -1) {
        *f = *r = 0;
    } else {
        *r = (*r + 1) % Max;
    }
    op[*r] = x;
}

void delete(int *f, int *r) {
    if (*f == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Deleted: %d\n", op[*f]);
    if (*f == *r) {
        *f = *r = -1;
    } else {
        *f = (*f + 1) % Max;
    }
}

void display(int f, int r) {
    if (f == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    int i = f;
    while (1) {
        printf("%d ", op[i]);
        if (i == r) break;
        i = (i + 1) % Max;
    }
    printf("\n");
}

int main() {
    int front = -1, rear = -1;

    insert(&front, &rear, 10);
    insert(&front, &rear, 20);
    insert(&front, &rear, 30);
    display(front, rear);

    delete(&front, &rear);
    display(front, rear);

    insert(&front, &rear, 40);
    insert(&front, &rear, 50);
    display(front, rear);

    return 0;
}
