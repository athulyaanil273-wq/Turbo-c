
#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 3
#define HASH_SIZE 101

typedef struct Node {
    int key, value;
    struct Node *prev, *next;
} Node;

Node *head, *tail;
Node *hashTable[HASH_SIZE];

int hash(int key) {
    int h = key % HASH_SIZE;
    return h < 0 ? h + HASH_SIZE : h;
}

Node* find(int key) {
    Node *temp = hashTable[hash(key)];

    while (temp != NULL) {
        if (temp->key == key)
            return temp;
        temp = temp->next;
    }

    return NULL;
}

void removeNode(Node *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

void insertFront(Node *node) {
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
}

void deleteFromHash(Node *node) {
    int h = hash(node->key);
    Node **current = &hashTable[h];

    while (*current != NULL) {
        if (*current == node) {
            *current = node->next;
            return;
        }
        current = &((*current)->next);
    }
}

void addToHash(Node *node) {
    int h = hash(node->key);
    node->next = hashTable[h];
    hashTable[h] = node;
}

void initialize() {
    head = malloc(sizeof(Node));
    tail = malloc(sizeof(Node));

    if (head == NULL || tail == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    head->next = tail;
    tail->prev = head;
    head->prev = NULL;
    tail->next = NULL;
}

void get(int key) {
    Node *node = find(key);

    if (node == NULL) {
        printf("GET %d: -1 (Cache Miss)\n", key);
        return;
    }

    removeNode(node);
    insertFront(node);

    printf("GET %d: %d (Cache Hit)\n", key, node->value);
}

void put(int key, int value) {
    Node *node = find(key);

    if (node != NULL) {
        node->value = value;
        removeNode(node);
        insertFront(node);
        return;
    }

    if (head->next == tail) {
        // Cache is not full.
    } else {
        int count = 0;
        Node *temp = head->next;

        while (temp != tail) {
            count++;
            temp = temp->next;
        }

        if (count == CAPACITY) {
            Node *lru = tail->prev;
            removeNode(lru);
            deleteFromHash(lru);
            free(lru);
        }
    }

    node = malloc(sizeof(Node));

    if (node == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    node->key = key;
    node->value = value;

    insertFront(node);
    addToHash(node);
}

void display() {
    Node *temp = head->next;

    printf("Cache (Most Recent -> Least Recent): ");

    while (temp != tail) {
        printf("[%d:%d] ", temp->key, temp->value);
        temp = temp->next;
    }

    printf("\n");
}

int main() {
    int choice, key, value;

    initialize();

    printf("LRU Cache Capacity: %d\n", CAPACITY);

    while (1) {
        printf("\n1. PUT\n2. GET\n3. DISPLAY\n4. EXIT\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1)
            break;

        switch (choice) {
            case 1:
                printf("Enter key and value: ");
                if (scanf("%d %d", &key, &value) != 2)
                    return 1;
                put(key, value);
                break;

            case 2:
                printf("Enter key: ");
                if (scanf("%d", &key) != 1)
                    return 1;
                get(key);
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
