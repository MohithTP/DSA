<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *tree = NULL;

struct node *insertElement(struct node *, int);
void preorderTraversal(struct node *);
void inorderTraversal(struct node *);
void postorderTraversal(struct node *);
struct node *findSmallestElement(struct node *);
struct node *findLargestElement(struct node *);
struct node *deleteElement(struct node *, int);
struct node *mirrorImage(struct node *);
int totalNodes(struct node *);
int totalExternalNodes(struct node *);
int totalInternalNodes(struct node *);
int Height(struct node *);
struct node *deleteTree(struct node *);

int main() {
    int option, val;
    struct node *ptr;

    do {
        printf("\n****** MAIN MENU ******\n");
        printf("1. Insert Element\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Find the smallest element\n");
        printf("6. Find the largest element\n");
        printf("7. Delete an element\n");
        printf("8. Count the total number of nodes\n");
        printf("9. Count the total number of external nodes\n");
        printf("10. Count the total number of internal nodes\n");
        printf("11. Determine the height of the tree\n");
        printf("12. Find the mirror image of the tree\n");
        printf("13. Delete the tree\n");
        printf("14. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Enter the value of the new node: ");
                scanf("%d", &val);
                tree = insertElement(tree, val);
                break;
            case 2:
                printf("Preorder Traversal: ");
                preorderTraversal(tree);
                printf("\n");
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorderTraversal(tree);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorderTraversal(tree);
                printf("\n");
                break;
            case 5:
                ptr = findSmallestElement(tree);
                if (ptr)
                    printf("Smallest element: %d\n", ptr->data);
                break;
            case 6:
                ptr = findLargestElement(tree);
                if (ptr)
                    printf("Largest element: %d\n", ptr->data);
                break;
            case 7:
                printf("Enter the element to be deleted: ");
                scanf("%d", &val);
                tree = deleteElement(tree, val);
                break;
            case 8:
                printf("Total number of nodes: %d\n", totalNodes(tree));
                break;
            case 9:
                printf("Total number of external nodes: %d\n", totalExternalNodes(tree));
                break;
            case 10:
                printf("Total number of internal nodes: %d\n", totalInternalNodes(tree));
                break;
            case 11:
                printf("The height of the tree: %d\n", Height(tree));
                break;
            case 12:
                tree = mirrorImage(tree);
                break;
            case 13:
                tree = deleteTree(tree);
                printf("Tree deleted.\n");
                break;
        }
    } while(option != 14);

    return 0;
}

struct node *insertElement(struct node *tree, int val) {
    struct node *ptr, *parentptr, *nodeptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->left = ptr->right = NULL;

    if (tree == NULL) {
        return ptr;
    }

    parentptr = NULL;
    nodeptr = tree;

    while (nodeptr != NULL) {
        parentptr = nodeptr;
        if (val < nodeptr->data)
            nodeptr = nodeptr->left;
        else
            nodeptr = nodeptr->right;
    }

    if (val < parentptr->data)
        parentptr->left = ptr;
    else
        parentptr->right = ptr;

    return tree;
}

void preorderTraversal(struct node *tree) {
    if (tree != NULL) {
        printf("%d ", tree->data);
        preorderTraversal(tree->left);
        preorderTraversal(tree->right);
    }
}

void inorderTraversal(struct node *tree) {
    if (tree != NULL) {
        inorderTraversal(tree->left);
        printf("%d ", tree->data);
        inorderTraversal(tree->right);
    }
}

void postorderTraversal(struct node *tree) {
    if (tree != NULL) {
        postorderTraversal(tree->left);
        postorderTraversal(tree->right);
        printf("%d ", tree->data);
    }
}

struct node *findSmallestElement(struct node *tree) {
    while (tree && tree->left != NULL)
        tree = tree->left;
    return tree;
}

struct node *findLargestElement(struct node *tree) {
    while (tree && tree->right != NULL)
        tree = tree->right;
    return tree;
}

struct node *deleteElement(struct node *tree, int val) {
    if (tree == NULL) return tree;

    if (val < tree->data)
        tree->left = deleteElement(tree->left, val);
    else if (val > tree->data)
        tree->right = deleteElement(tree->right, val);
    else {
        if (tree->left == NULL) {
            struct node *temp = tree->right;
            free(tree);
            return temp;
        } else if (tree->right == NULL) {
            struct node *temp = tree->left;
            free(tree);
            return temp;
        }

        struct node *temp = findSmallestElement(tree->right);
        tree->data = temp->data;
        tree->right = deleteElement(tree->right, temp->data);
    }
    return tree;
}

int totalNodes(struct node *tree) {
    if (tree == NULL) return 0;
    return totalNodes(tree->left) + totalNodes(tree->right) + 1;
}

int totalExternalNodes(struct node *tree) {
    if (tree == NULL) return 0;
    if (tree->left == NULL && tree->right == NULL) return 1;
    return totalExternalNodes(tree->left) + totalExternalNodes(tree->right);
}

int totalInternalNodes(struct node *tree) {
    if (tree == NULL || (tree->left == NULL && tree->right == NULL)) return 0;
    return totalInternalNodes(tree->left) + totalInternalNodes(tree->right) + 1;
}

int Height(struct node *tree) {
    if (tree == NULL) return -1;
    int leftHeight = Height(tree->left);
    int rightHeight = Height(tree->right);
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

struct node *mirrorImage(struct node *tree) {
    if (tree == NULL) return tree;
    struct node *temp = tree->left;
    tree->left = mirrorImage(tree->right);
    tree->right = mirrorImage(temp);
    return tree;
}

struct node *deleteTree(struct node *tree) {
    if (tree == NULL) return NULL;
    deleteTree(tree->left);
    deleteTree(tree->right);
    free(tree);
    return NULL;
}
=======
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *tree = NULL;

struct node *insertElement(struct node *, int);
void preorderTraversal(struct node *);
void inorderTraversal(struct node *);
void postorderTraversal(struct node *);
struct node *findSmallestElement(struct node *);
struct node *findLargestElement(struct node *);
struct node *deleteElement(struct node *, int);
struct node *mirrorImage(struct node *);
int totalNodes(struct node *);
int totalExternalNodes(struct node *);
int totalInternalNodes(struct node *);
int Height(struct node *);
struct node *deleteTree(struct node *);

int main() {
    int option, val;
    struct node *ptr;

    do {
        printf("\n****** MAIN MENU ******\n");
        printf("1. Insert Element\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Find the smallest element\n");
        printf("6. Find the largest element\n");
        printf("7. Delete an element\n");
        printf("8. Count the total number of nodes\n");
        printf("9. Count the total number of external nodes\n");
        printf("10. Count the total number of internal nodes\n");
        printf("11. Determine the height of the tree\n");
        printf("12. Find the mirror image of the tree\n");
        printf("13. Delete the tree\n");
        printf("14. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Enter the value of the new node: ");
                scanf("%d", &val);
                tree = insertElement(tree, val);
                break;
            case 2:
                printf("Preorder Traversal: ");
                preorderTraversal(tree);
                printf("\n");
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorderTraversal(tree);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorderTraversal(tree);
                printf("\n");
                break;
            case 5:
                ptr = findSmallestElement(tree);
                if (ptr)
                    printf("Smallest element: %d\n", ptr->data);
                break;
            case 6:
                ptr = findLargestElement(tree);
                if (ptr)
                    printf("Largest element: %d\n", ptr->data);
                break;
            case 7:
                printf("Enter the element to be deleted: ");
                scanf("%d", &val);
                tree = deleteElement(tree, val);
                break;
            case 8:
                printf("Total number of nodes: %d\n", totalNodes(tree));
                break;
            case 9:
                printf("Total number of external nodes: %d\n", totalExternalNodes(tree));
                break;
            case 10:
                printf("Total number of internal nodes: %d\n", totalInternalNodes(tree));
                break;
            case 11:
                printf("The height of the tree: %d\n", Height(tree));
                break;
            case 12:
                tree = mirrorImage(tree);
                break;
            case 13:
                tree = deleteTree(tree);
                printf("Tree deleted.\n");
                break;
        }
    } while(option != 14);

    return 0;
}

struct node *insertElement(struct node *tree, int val) {
    struct node *ptr, *parentptr, *nodeptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->left = ptr->right = NULL;

    if (tree == NULL) {
        return ptr;
    }

    parentptr = NULL;
    nodeptr = tree;

    while (nodeptr != NULL) {
        parentptr = nodeptr;
        if (val < nodeptr->data)
            nodeptr = nodeptr->left;
        else
            nodeptr = nodeptr->right;
    }

    if (val < parentptr->data)
        parentptr->left = ptr;
    else
        parentptr->right = ptr;

    return tree;
}

void preorderTraversal(struct node *tree) {
    if (tree != NULL) {
        printf("%d ", tree->data);
        preorderTraversal(tree->left);
        preorderTraversal(tree->right);
    }
}

void inorderTraversal(struct node *tree) {
    if (tree != NULL) {
        inorderTraversal(tree->left);
        printf("%d ", tree->data);
        inorderTraversal(tree->right);
    }
}

void postorderTraversal(struct node *tree) {
    if (tree != NULL) {
        postorderTraversal(tree->left);
        postorderTraversal(tree->right);
        printf("%d ", tree->data);
    }
}

struct node *findSmallestElement(struct node *tree) {
    while (tree && tree->left != NULL)
        tree = tree->left;
    return tree;
}

struct node *findLargestElement(struct node *tree) {
    while (tree && tree->right != NULL)
        tree = tree->right;
    return tree;
}

struct node *deleteElement(struct node *tree, int val) {
    if (tree == NULL) return tree;

    if (val < tree->data)
        tree->left = deleteElement(tree->left, val);
    else if (val > tree->data)
        tree->right = deleteElement(tree->right, val);
    else {
        if (tree->left == NULL) {
            struct node *temp = tree->right;
            free(tree);
            return temp;
        } else if (tree->right == NULL) {
            struct node *temp = tree->left;
            free(tree);
            return temp;
        }

        struct node *temp = findSmallestElement(tree->right);
        tree->data = temp->data;
        tree->right = deleteElement(tree->right, temp->data);
    }
    return tree;
}

int totalNodes(struct node *tree) {
    if (tree == NULL) return 0;
    return totalNodes(tree->left) + totalNodes(tree->right) + 1;
}

int totalExternalNodes(struct node *tree) {
    if (tree == NULL) return 0;
    if (tree->left == NULL && tree->right == NULL) return 1;
    return totalExternalNodes(tree->left) + totalExternalNodes(tree->right);
}

int totalInternalNodes(struct node *tree) {
    if (tree == NULL || (tree->left == NULL && tree->right == NULL)) return 0;
    return totalInternalNodes(tree->left) + totalInternalNodes(tree->right) + 1;
}

int Height(struct node *tree) {
    if (tree == NULL) return -1;
    int leftHeight = Height(tree->left);
    int rightHeight = Height(tree->right);
    return (leftHeight > rightHeight) ? leftHeight + 1 : rightHeight + 1;
}

struct node *mirrorImage(struct node *tree) {
    if (tree == NULL) return tree;
    struct node *temp = tree->left;
    tree->left = mirrorImage(tree->right);
    tree->right = mirrorImage(temp);
    return tree;
}

struct node *deleteTree(struct node *tree) {
    if (tree == NULL) return NULL;
    deleteTree(tree->left);
    deleteTree(tree->right);
    free(tree);
    return NULL;
}
>>>>>>> f10fbf957f2472c96c7daf55a328653aec7beb42
