#include<stdlib.h>
#include<stdio.h>
#define Max 5
int op1[Max];
int op2[Max];
int top1=-1;
int top2=-1;

void push(int c){
    if(top1<Max-1) op1[++top1]=c;
    else if(top2<Max-1) op2[++top2]=c;
    else printf("Both Stack Overflow");
}

int pop(){
    if(top1>=0) return op1[top1--];
    else if (top2>=0) return op2[top2--];
    else printf("Both Stack Underflow");
}

void printStacks() {
    printf("Stack 1: ");
    for (int i = 0; i <= top1; i++) {
        printf("%d ", op1[i]);
    }
    printf("\nStack 2: ");
    for (int i = 0; i <= top2; i++) {
        printf("%d ", op2[i]);
    }
    printf("\n");
}

int main(){
    int n,x;
    printf("Enter value of n");
    scanf("%d",&n);
    printf("Enter stack elements");
    for(int i=0;i<n;i++){
    scanf("%d",&x);
    push(x);
    }
    
    printStacks();
    printf("Popped elements: ");
    while (top1 >= 0 || top2 >= 0) { 
        printf("%d ", pop());
    }
    printf("\n");

    return 0;
}