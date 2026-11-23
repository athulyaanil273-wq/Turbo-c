
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    int height;
    struct Node *left, *right;
};

int max(int a, int b) {
    return a > b ? a : b;
}

int height(struct Node *node) {
    return node == NULL ? 0 : node->height;
}

struct Node* createNode(int key) {
    struct Node* node = malloc(sizeof(struct Node));

    if (node == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    node->key = key;
    node->height = 1;
    node->left = node->right = NULL;

    return node;
}

int balanceFactor(struct Node *node) {
    return node == NULL ? 0 :
           height(node->left) - height(node->right);
}

struct Node* rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *temp = x->right;

    x->right = y;
    y->left = temp;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

struct Node* leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

struct Node* insert(struct Node *node, int key) {
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = balanceFactor(node);

    // Left Left case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    struct Node *root = NULL;
    int n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n < 1 || n > 1000) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        root = insert(root, key);
    }

    printf("Inorder traversal of AVL tree:\n");
    inorder(root);
    printf("\n");

    return 0;
}
