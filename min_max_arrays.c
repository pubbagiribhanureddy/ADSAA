#include <stdio.h>
#include <stdlib.h>

int findMin(int a[], int n) {
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min)
            min = a[i];
    }
    return min;
}

int findMax(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

int rfindMin(int a[], int n) {
    if (n == 1)
        return a[0];
    int min = rfindMin(a, n - 1);
    return (a[n - 1] < min) ? a[n - 1] : min;
}

int rfindMax(int a[], int n) {
    if (n == 1)
        return a[0];
    int max = rfindMax(a, n - 1);
    return (a[n - 1] > max) ? a[n - 1] : max;
}

int main() {
    int n, a[10], ch;
    int maximum, minimum;

    printf("\nEnter total number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    while (1) {
        printf("\nMenu:");
        printf("\n1. Minimum element (Iterative)");
        printf("\n2. Maximum element (Iterative)");
        printf("\n3. Minimum element (Recursive)");
        printf("\n4. Maximum element (Recursive)");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                minimum = findMin(a, n);
                printf("Minimum element: %d\n", minimum);
                break;

            case 2:
                maximum = findMax(a, n);
                printf("Maximum element: %d\n", maximum);
                break;

            case 3:
                minimum = rfindMin(a, n);
                printf("Minimum element (Recursive): %d\n", minimum);
                break;

            case 4:
                maximum = rfindMax(a, n);
                printf("Maximum element (Recursive): %d\n", maximum);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid option!\n");
        }
    }

    return 0;
}