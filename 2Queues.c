<<<<<<< HEAD
#include <stdio.h>
#define Max 5
#define WaitingMax 5

int op[Max];
int waitingList[WaitingMax];
int waitFront = -1, waitRear = -1;

void insert(int *f, int *r, int x) {
    if ((*r + 1) % Max == *f) {
        if (waitRear == WaitingMax - 1) {
            printf("Queue and waiting list are full\n");
        } else {
            if (waitFront == -1) waitFront = 0;
            waitingList[++waitRear] = x;
            printf("Queue is full, added %d to waiting list\n", x);
        }
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
    
    if (waitFront != -1) {
        int newElement = waitingList[waitFront];
        printf("Moving %d from waiting list to queue\n", newElement);
        insert(f, r, newElement);
        if (waitFront == waitRear) {
            waitFront = waitRear = -1;
        } else {
            waitFront++;
        }
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

void displayWaitingList() {
    if (waitFront == -1) {
        printf("Waiting list is empty\n");
        return;
    }
    printf("Waiting list: ");
    for (int i = waitFront; i <= waitRear; i++) {
        printf("%d ", waitingList[i]);
    }
    printf("\n");
}

int main() {
    int front = -1, rear = -1;

    insert(&front, &rear, 10);
    insert(&front, &rear, 20);
    insert(&front, &rear, 30);
    insert(&front, &rear, 40);
    insert(&front, &rear, 50);
    insert(&front, &rear, 60);
    insert(&front, &rear, 70);
    
    display(front, rear);
    displayWaitingList();

    delete(&front, &rear);
    delete(&front, &rear);
    
    display(front, rear);
    displayWaitingList();
    
    return 0;
=======
#include <stdio.h>
#define Max 5
#define WaitingMax 5

int op[Max];
int waitingList[WaitingMax];
int waitFront = -1, waitRear = -1;

void insert(int *f, int *r, int x) {
    if ((*r + 1) % Max == *f) {
        if (waitRear == WaitingMax - 1) {
            printf("Queue and waiting list are full\n");
        } else {
            if (waitFront == -1) waitFront = 0;
            waitingList[++waitRear] = x;
            printf("Queue is full, added %d to waiting list\n", x);
        }
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
    
    if (waitFront != -1) {
        int newElement = waitingList[waitFront];
        printf("Moving %d from waiting list to queue\n", newElement);
        insert(f, r, newElement);
        if (waitFront == waitRear) {
            waitFront = waitRear = -1;
        } else {
            waitFront++;
        }
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

void displayWaitingList() {
    if (waitFront == -1) {
        printf("Waiting list is empty\n");
        return;
    }
    printf("Waiting list: ");
    for (int i = waitFront; i <= waitRear; i++) {
        printf("%d ", waitingList[i]);
    }
    printf("\n");
}

int main() {
    int front = -1, rear = -1;

    insert(&front, &rear, 10);
    insert(&front, &rear, 20);
    insert(&front, &rear, 30);
    insert(&front, &rear, 40);
    insert(&front, &rear, 50);
    insert(&front, &rear, 60);
    insert(&front, &rear, 70);
    
    display(front, rear);
    displayWaitingList();

    delete(&front, &rear);
    delete(&front, &rear);
    
    display(front, rear);
    displayWaitingList();
    
    return 0;
>>>>>>> f10fbf957f2472c96c7daf55a328653aec7beb42
}