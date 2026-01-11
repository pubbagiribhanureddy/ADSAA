
#include <stdio.h>
#define MAX 200
int n; // Number of items
float W; // Capacity of knapsack
float weight[MAX], value[MAX];
int currentSet[MAX], bestSet[MAX];
float maxValue = 0;
void knapsack(int i, float currWeight, float currValue)
{
int j;
if (currWeight <= W && currValue > maxValue)
{
maxValue = currValue;
for (j = 0; j < n; j++)
bestSet[j] = currentSet[j];
}
if (i >= n) return;
if (currWeight + weight[i] <= W)
{
currentSet[i] = 1;
knapsack(i + 1, currWeight + weight[i], currValue + value[i]);
}
currentSet[i] = 0;
knapsack(i + 1, currWeight, currValue);
}
int main()
{
int i;
printf("Enter number of items: ");
scanf("%d", &n);
printf("Enter knapsack capacity: ");
scanf("%f", &W);
printf("Enter weights:\n");
for (i = 0; i < n; i++)
scanf("%f", &weight[i]);
printf("Enter Profots:\n");
for (i = 0; i < n; i++)
scanf("%f", &value[i]);
knapsack(0, 0, 0);
printf("\nMaximum value = %.2f\n", maxValue);
printf("Items included (1 = yes, 0 = no): ");
for (i = 0; i < n; i++)
printf("%d ", bestSet[i]);
printf("\n");
return 0;
}
