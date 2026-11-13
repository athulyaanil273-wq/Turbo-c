
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 26
#define MAX 100

struct TrieNode {
    struct TrieNode *children[SIZE];
    int isEnd;
};

struct TrieNode* createNode() {
    struct TrieNode *node = calloc(1, sizeof(struct TrieNode));

    if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    return node;
}

int validWord(char word[]) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] < 'a' || word[i] > 'z')
            return 0;
    }
    return word[0] != '\0';
}

void insert(struct TrieNode *root, char word[]) {
    struct TrieNode *current = root;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (current->children[index] == NULL)
            current->children[index] = createNode();

        current = current->children[index];
    }

    current->isEnd = 1;
}

int search(struct TrieNode *root, char word[]) {
    struct TrieNode *current = root;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (current->children[index] == NULL)
            return 0;

        current = current->children[index];
    }

    return current->isEnd;
}

int startsWith(struct TrieNode *root, char prefix[]) {
    struct TrieNode *current = root;

    for (int i = 0; prefix[i] != '\0'; i++) {
        int index = prefix[i] - 'a';

        if (current->children[index] == NULL)
            return 0;

        current = current->children[index];
    }

    return 1;
}

void freeTrie(struct TrieNode *root) {
    if (root == NULL)
        return;

    for (int i = 0; i < SIZE; i++)
        freeTrie(root->children[i]);

    free(root);
}

int main() {
    struct TrieNode *root = createNode();
    char word[MAX], query[MAX], prefix[MAX];
    int n;

    scanf("%d", &n);

    if (n < 0 || n > 100) {
        printf("Invalid input\n");
        freeTrie(root);
        return 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%99s", word);

        if (!validWord(word)) {
            printf("Invalid word\n");
            freeTrie(root);
            return 0;
        }

        insert(root, word);
    }

    scanf("%99s", query);
    scanf("%99s", prefix);

    if (!validWord(query) || !validWord(prefix)) {
        printf("Invalid query\n");
        freeTrie(root);
        return 0;
    }

    if (search(root, query))
        printf("Word found\n");
    else
        printf("Word not found\n");

    if (startsWith(root, prefix))
        printf("Prefix exists\n");
    else
        printf("Prefix does not exist\n");

    freeTrie(root);

    return 0;
}
