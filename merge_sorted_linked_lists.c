
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

struct Node* mergeLists(struct Node *a, struct Node *b) {
    struct Node dummy;
    struct Node *tail = &dummy;

    dummy.next = NULL;

    while (a != NULL && b != NULL) {
        if (a->data <= b->data) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }

        tail = tail->next;
    }

    tail->next = (a != NULL) ? a : b;

    return dummy.next;
}

void display(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void freeList(struct Node *head) {
    while (head != NULL) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n, m, value;
    struct Node *a = NULL, *b = NULL;
    struct Node *tailA = NULL, *tailB = NULL;

    scanf("%d", &n);

    if (n < 0 || n > 10000) {
        printf("Invalid input\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node *newNode = createNode(value);

        if (a == NULL)
            a = tailA = newNode;
        else {
            tailA->next = newNode;
            tailA = newNode;
        }
    }

    scanf("%d", &m);

    if (m < 0 || m > 10000) {
        freeList(a);
        printf("Invalid input\n");
        return 0;
    }

    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        struct Node *newNode = createNode(value);

        if (b == NULL)
            b = tailB = newNode;
        else {
            tailB->next = newNode;
            tailB = newNode;
        }
    }

    struct Node *merged = mergeLists(a, b);

    printf("Merged List: ");
    display(merged);

    freeList(merged);

    return 0;
}
