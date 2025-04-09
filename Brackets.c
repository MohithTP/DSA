<<<<<<< HEAD
#include <stdio.h>
#include <string.h>

#define Max 100
int op[Max];
int top = -1;

void push(char c) {
    if (top == Max - 1) return;
    op[++top] = c;
}

char pop() {
    if (top == -1) return '\0';
    return op[top--];
}

int isValid(char* s) {
    int n = strlen(s);

    for (int i = 0; i < n; i++) {
        char c = s[i];

        if (c == '(' || c == '{' || c == '[') {
            push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            char x = pop();
            if ((c == ')' && x != '(') || 
                (c == '}' && x != '{') || 
                (c == ']' && x != '[')) {
                return 0;
            }
        }
    }
    
    return (top == -1);
}

int main() {
    char s[100];

    printf("Enter the expression: ");
    scanf("%s", s);

    if (isValid(s)) {
        printf("Valid Expression\n");
    } else {
        printf("Invalid Expression\n");
    }

    return 0;
}
=======
#include <stdio.h>
#include <string.h>

#define Max 100
int op[Max];
int top = -1;

void push(char c) {
    if (top == Max - 1) return;
    op[++top] = c;
}

char pop() {
    if (top == -1) return '\0';
    return op[top--];
}

int isValid(char* s) {
    int n = strlen(s);

    for (int i = 0; i < n; i++) {
        char c = s[i];

        if (c == '(' || c == '{' || c == '[') {
            push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            char x = pop();
            if ((c == ')' && x != '(') || 
                (c == '}' && x != '{') || 
                (c == ']' && x != '[')) {
                return 0;
            }
        }
    }
    
    return (top == -1);
}

int main() {
    char s[100];

    printf("Enter the expression: ");
    scanf("%s", s);

    if (isValid(s)) {
        printf("Valid Expression\n");
    } else {
        printf("Invalid Expression\n");
    }

    return 0;
}
>>>>>>> f10fbf957f2472c96c7daf55a328653aec7beb42
