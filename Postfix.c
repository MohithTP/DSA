#include<stdio.h>
#include<ctype.h>
#define mx 25
int top = -1;
char op[mx];

void push(char ele)
{
    if(top == mx-1) return;
    op[++top] = ele;
    return;
}

char pop()
{
    if(top == -1) return;
    return op[top--];
}

char peek()
{
    if(top == -1) return;
    return op[top];
}

int priority(char x)
{
    if(x == '(' || x == ')') return 0;
    if(x == '+' || x == '-') return 1;
    if(x == '*' || x == '/') return 2;
    return;
}

int main()
{
    char infix[50], postfix[50], ch;
    int i, j=0;

    printf("Enter the infix expression: ");
    gets(infix);

    for(i=0; infix[i]!='\0'; i++)
    {
        ch = infix[i];
        if(ch == '(')
        {
            push(ch);
            continue;
        }
        if(ch == ')')
        {
            char x;
            while((x = pop()) != '(')
            {
                postfix[j++] = x;
            }
            continue;
        }
        if(isalnum(ch))
        {
            postfix[j++] = ch;
            continue;
        }

        while(priority(peek()) >= priority(ch))
        {
            printf("HI");
            postfix[j++] = pop();
        }

        push(ch);
    }

    while(top>-1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("The postfix expression is: %s", postfix);

    return 1;
}