#include <stdio.h>
#include <stdlib.h>

// Iterative Binary Search
int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

// Recursive Binary Search
int binarySearchRecursive(int arr[], int low, int high, int key) {
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid;
    else if (arr[mid] > key)
        return binarySearchRecursive(arr, low, mid - 1, key);
    else
        return binarySearchRecursive(arr, mid + 1, high, key);
}

int main() {
    int arr[20];
    int size, key, ch, result;

    printf("Enter size of the array: ");
    scanf("%d", &size);

    printf("Enter %d elements in sorted order:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the key element to search: ");
    scanf("%d", &key);

    while (1) {
        printf("\nMenu\n");
        printf("1. Binary Search (Iterative)\n");
        printf("2. Binary Search (Recursive)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                result = binarySearch(arr, size, key);
                if (result != -1)
                    printf("Element found at index %d\n", result);
                else
                    printf("Element not found\n");
                break;

            case 2:
                result = binarySearchRecursive(arr, 0, size - 1, key);
                if (result != -1)
                    printf("Element found at index %d\n", result);
                else
                    printf("Element not found\n");
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid option!\n");
        }
    }

    return 0;
}