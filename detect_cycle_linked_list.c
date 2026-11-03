
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int hasCycle(struct Node *head) {
    struct Node *slow = head;
    struct Node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return 1;
    }

    return 0;
}

int main() {
    struct Node *head = NULL;
    struct Node *tail = NULL;
    struct Node *newNode;
    int n, value, position;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of nodes!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        newNode = malloc(sizeof(struct Node));

        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        printf("Enter value: ");
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else
            tail->next = newNode;

        tail = newNode;
    }

    printf("Enter position to connect tail (-1 for no cycle): ");
    scanf("%d", &position);

    if (position >= 0 && position < n) {
        struct Node *temp = head;

        for (int i = 0; i < position; i++)
            temp = temp->next;

        tail->next = temp;
    }

    if (hasCycle(head))
        printf("Cycle detected!\n");
    else
        printf("No cycle detected!\n");

    // Free memory only when there is no cycle
    if (position == -1) {
        while (head != NULL) {
            struct Node *temp = head;
            head = head->next;
            free(temp);
        }
    } else if (position < -1 || position >= n) {
        while (head != NULL) {
            struct Node *temp = head;
            head = head->next;
            free(temp);
        }
    }

    return 0;
}
