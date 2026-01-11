#include <stdio.h>
#define MAX 100

int heap[MAX], size = 0;
int isMinHeap = 1;  // 1 for Min Heap, 0 for Max Heap

int compare(int a, int b) {
    return isMinHeap ? a < b : a > b;
}

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

void heapifyDown(int i)
{
    int left = 2 * i, right = 2 * i + 1, best = i;
    if (left <= size && compare(heap[left], heap[best]))
        best = left;
    if (right <= size && compare(heap[right], heap[best]))
        best = right;
    if (best != i)
    {
        swap(&heap[i], &heap[best]);
        heapifyDown(best);
    }
}

void heapifyUp(int i)
{
    while (i > 1 && compare(heap[i], heap[i / 2]))
    {
        swap(&heap[i], &heap[i / 2]);
        i /= 2;
    }
}

void insert(int val)
{
    heap[++size] = val;
    heapifyUp(size);
}

void deleteAt(int pos) {
    if (pos > size || pos < 1)
    {
        printf("Invalid position\n");
        return;
    }
    printf("Deleted: %d\n", heap[pos]);
    heap[pos] = heap[size--];
    heapifyDown(pos);
}

void display() {
    printf("%s Heap: ", isMinHeap ? "Min" : "Max");
    for (int i = 1; i <= size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    int choice, val, pos;
    printf("Choose heap type (1.Min Heap, 0.Max Heap): ");
    scanf("%d", &isMinHeap);

    while (1) {
        printf("\n1.Insert  2.Delete  3.Display  4.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter value: ");
            scanf("%d", &val);
            insert(val); break;
            case 2: printf("Enter position to delete: ");
            scanf("%d", &pos);
            deleteAt(pos); break;
            case 3: display();
            break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
