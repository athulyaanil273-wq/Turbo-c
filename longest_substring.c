```c
#include <stdio.h>
#include <string.h>

int main() {
    char s[100001];

    scanf("%100000s", s);

    int last[256];
    for (int i = 0; i < 256; i++)
        last[i] = -1;

    int start = 0, maxLen = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)s[i];

        if (last[ch] >= start)
            start = last[ch] + 1;

        last[ch] = i;

        int len = i - start + 1;

        if (len > maxLen)
            maxLen = len;
    }

    printf("%d\n", maxLen);

    return 0;
}
```
