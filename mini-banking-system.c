```c
#include <stdio.h>

int main() {
    int choice;
    double balance = 1000.00;
    double amount;

    printf("================================\n");
    printf("       MINI BANKING SYSTEM\n");
    printf("================================\n");

    do {
        printf("\n1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            return 1;
        }

        switch (choice) {
            case 1:
                printf("Current Balance: Rs. %.2f\n", balance);
                break;

            case 2:
                printf("Enter deposit amount: Rs. ");
                if (scanf("%lf", &amount) != 1) {
                    printf("Invalid amount!\n");
                    return 1;
                }

                if (amount > 0) {
                    balance += amount;
                    printf("Deposit successful!\n");
                    printf("Updated Balance: Rs. %.2f\n", balance);
                } else {
                    printf("Amount must be positive!\n");
                }
                break;

            case 3:
                printf("Enter withdrawal amount: Rs. ");
                if (scanf("%lf", &amount) != 1) {
                    printf("Invalid amount!\n");
                    return 1;
                }

                if (amount <= 0) {
                    printf("Amount must be positive!\n");
                } else if (amount > balance) {
                    printf("Insufficient balance!\n");
                } else {
                    balance -= amount;
                    printf("Withdrawal successful!\n");
                    printf("Remaining Balance: Rs. %.2f\n", balance);
                }
                break;

            case 4:
                printf("Thank you for using our banking system!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}
```
