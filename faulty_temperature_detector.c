
#include <stdio.h>

int main() {
    int n, i, count = 0;
    float T = 45.0;
    float temp[n];
    float faulty[n];

    printf("Enter the number of temperature readings: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of readings!\n");
        return 1;
    }

    printf("Enter %d temperature readings:\n", n);

    for (i = 0; i < n; i++) {
        scanf("%f", &temp[i]);
    }

    for (i = 0; i < n; i++) 
    {
        if (temp[i] > T) 
        {
            faulty[count] = temp[i];
            count++;
        }
    }

    printf("\nTrigger temperature: %.2f\n", T);
    printf("Faulty temperatures: ");

    if (count == 0) 
    {
        printf("None");
    } 
    else 
    {
        for (i = 0; i < count; i++) 
        {
            printf("%.2f ", faulty[i]);
        }
    }

    printf("\nNumber of faulty temperatures: %d\n", count);
    printf("Length of faulty array: %d\n", count);

    return 0;
}
```
