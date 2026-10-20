
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int upper = 0, lower = 0;
    int digit = 0, special = 0;
    int score = 0;

    printf("=== PASSWORD STRENGTH CHECKER ===\n");
    printf("Enter a password: ");

    scanf("%99s", password);

    int len = strlen(password);

    for (int i = 0; password[i] != '\0'; i++) {
        if (isupper((unsigned char)password[i]))
            upper = 1;
        else if (islower((unsigned char)password[i]))
            lower = 1;
        else if (isdigit((unsigned char)password[i]))
            digit = 1;
        else
            special = 1;
    }

    if (len >= 8)
        score++;
    if (upper)
        score++;
    if (lower)
        score++;
    if (digit)
        score++;
    if (special)
        score++;

    printf("\nPassword length: %d\n", len);

    if (score <= 2)
        printf("Strength: Weak\n");
    else if (score <= 4)
        printf("Strength: Moderate\n");
    else
        printf("Strength: Strong\n");

    printf("\nSuggestions:\n");

    if (len < 8)
        printf("- Use at least 8 characters.\n");
    if (!upper)
        printf("- Add an uppercase letter.\n");
    if (!lower)
        printf("- Add a lowercase letter.\n");
    if (!digit)
        printf("- Add a number.\n");
    if (!special)
        printf("- Add a special character.\n");

    if (score == 5)
        printf("Great! All strength checks passed.\n");

    return 0;
}
