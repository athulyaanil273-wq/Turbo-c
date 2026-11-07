//Problem statement:

//Given an array representing the heights of elevation bars, calculate how much rainwater can be trapped between the bars after rainfall.
#include <stdio.h>

int trap(int height[], int n) {
    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int water = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= leftMax)
                leftMax = height[left];
            else
                water += leftMax - height[left];

            left++;
        } else {
            if (height[right] >= rightMax)
                rightMax = height[right];
            else
                water += rightMax - height[right];

            right--;
        }
    }

    return water;
}

int main() {
    int n;

    scanf("%d", &n);

    if (n < 0) {
        printf("Invalid input\n");
        return 0;
    }

    int height[n > 0 ? n : 1];

    for (int i = 0; i < n; i++) {
        scanf("%d", &height[i]);

        if (height[i] < 0) {
            printf("Invalid height\n");
            return 0;
        }
    }

    printf("Trapped rainwater: %d\n", trap(height, n));

    return 0;
}
