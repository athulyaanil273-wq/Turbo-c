
#include <stdio.h>
#include <string.h>

#define MAX 100
#define LEN 100

int areAnagrams(char a[], char b[]) {
    int count[256] = {0};

    if (strlen(a) != strlen(b))
        return 0;

    for (int i = 0; a[i] != '\0'; i++) {
        count[(unsigned char)a[i]]++;
        count[(unsigned char)b[i]]--;
    }

    for (int i = 0; i < 256; i++) {
        if (count[i] != 0)
            return 0;
    }

    return 1;
}

int main() {
    int n;
    char words[MAX][LEN];
    int grouped[MAX] = {0};

    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid input\n");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%99s", words[i]);
    }

    printf("Anagram Groups:\n");

    for (int i = 0; i < n; i++) {
        if (grouped[i])
            continue;

        printf("[ ");

        for (int j = i; j < n; j++) {
            if (!grouped[j] && areAnagrams(words[i], words[j])) {
                printf("%s ", words[j]);
                grouped[j] = 1;
            }
        }

        printf("]\n");
    }

    return 0;
}
