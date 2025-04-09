#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Structure for a tree node
struct Node {
    char data;
    struct Node *left, *right;
};

// Stack for tree nodes
struct Stack {
    struct Node* data[100];
    int top;
} stack;

// Push node into stack
void push(struct Node* node) {
    stack.data[++stack.top] = node;
}

// Pop node from stack
struct Node* pop() {
    return stack.data[stack.top--];
}

// Create a new node
struct Node* createNode(char value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Build an expression tree from a postfix expression
struct Node* buildExpressionTree(char postfix[]) {
    stack.top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        struct Node* newNode = createNode(postfix[i]);

        if (isdigit(postfix[i])) {  
            // If operand, push to stack
            push(newNode);
        } else {  
            // If operator, pop two elements and set as left/right children
            newNode->right = pop();
            newNode->left = pop();
            push(newNode);
        }
    }
    return pop();  // Root of the expression tree
}

// Inorder Traversal (Prints expression in infix form)
void inorder(struct Node* root) {
    if (root) {
        if (!isdigit(root->data)) printf("(");
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
        if (!isdigit(root->data)) printf(")");
    }
}

// Postorder Traversal (Evaluation Order)
void postorder(struct Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

// Preorder Traversal (Prefix Notation)
void preorder(struct Node* root) {
    if (root) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    char postfix[] = "32+54-*";  // Postfix representation of (3 + 2) * (5 - 4)
    
    struct Node* root = buildExpressionTree(postfix);

    printf("Inorder Expression: ");
    inorder(root);
    printf("\n");

    printf("Postorder Expression: ");
    postorder(root);
    printf("\n");

    printf("Preorder Expression: ");
    preorder(root);
    printf("\n");

    return 0;
}
