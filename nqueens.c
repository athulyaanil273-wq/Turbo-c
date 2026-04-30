#include <stdio.h>
#include <math.h>

int x[10];
int n;

int place(int k, int i)
{
    int j;
    for (j = 1; j < k; j++)
    {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return 0;
    }
    return 1;
}

void nQueen(int k)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        if (place(k, i))
        {
            x[k] = i;

            if (k == n)
            {
                int j;
                printf("Solution: ");
                for (j = 1; j <= n; j++)
                    printf("%d ", x[j]);
                printf("\n");
            }
            else
            {
                nQueen(k + 1);
            }
        }
    }
}

int main()
{
    printf("Enter number of queens: ");
    scanf("%d", &n);

    nQueen(1);

    return 0;
}
