
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Build tree using preorder input (-1 represents NULL)
struct Node* buildTree() {
    int value;
    scanf("%d", &value);

    if (value == -1)
        return NULL;

    struct Node *root = createNode(value);

    root->left = buildTree();
    root->right = buildTree();

    return root;
}

int areIdentical(struct Node *a, struct Node *b) {
    if (a == NULL && b == NULL)
        return 1;

    if (a == NULL || b == NULL)
        return 0;

    return (a->data == b->data &&
            areIdentical(a->left, b->left) &&
            areIdentical(a->right, b->right));
}

void freeTree(struct Node *root) {
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    struct Node *tree1, *tree2;

    printf("Enter first tree:\n");
    tree1 = buildTree();

    printf("Enter second tree:\n");
    tree2 = buildTree();

    if (areIdentical(tree1, tree2))
        printf("Trees are identical\n");
    else
        printf("Trees are not identical\n");

    freeTree(tree1);
    freeTree(tree2);

    return 0;
}
