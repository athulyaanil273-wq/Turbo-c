
#include <stdio.h>
#include <ctype.h>

#define MAX 100

int main() {
    char exp[MAX];
    int stack[MAX];
    int top = -1;

    scanf("%99s", exp);

    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        if (isdigit((unsigned char)ch)) {
            stack[++top] = ch - '0';
        }
        else {
            if (top < 1) {
                printf("Invalid expression\n");
                return 0;
            }

            int b = stack[top--];
            int a = stack[top--];
            int result;

            switch (ch) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;

                case '/':
                    if (b == 0) {
                        printf("Division by zero\n");
                        return 0;
                    }
                    result = a / b;
                    break;

                default:
                    printf("Invalid operator\n");
                    return 0;
            }

            stack[++top] = result;
        }
    }

    if (top != 0) {
        printf("Invalid expression\n");
    } else {
        printf("Result: %d\n", stack[top]);
    }

    return 0;
}
