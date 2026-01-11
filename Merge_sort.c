#include <stdio.h>
#include <conio.h>
#define size 100

void merge(int a[], int, int, int);
void merge_sort(int a[],int, int);

void main()
{
int arr[size], i, n;
printf("------MERGE SORT------\n");
printf("\n Enter the number of elements in the array : ");
scanf("%d", &n);

for(i=0;i<n;i++)
{
    printf("Enter a[%d] element : ",i);
    scanf("%d", &arr[i]);
}
printf("Before Sorting array elements are : ");
for(i=0;i<n;i++)
{
printf("%d ",arr[i]);
}
merge_sort(arr, 0, n-1);
printf("\nAfter Sorting the Array Elements are: \n");
for(i=0;i<n;i++)
    printf("%d  ", arr[i]);
//getch();
}

void merge(int arr[], int low, int mid, int high)
{
int i=low, j=mid+1, index=low, temp[size], k;
while((i<=mid) && (j<=high))
{
    if(arr[i] < arr[j])
    {
    temp[index] = arr[i];
    i++;
    }
    else
    {
    temp[index] = arr[j];
    j++;
    }
index++;
}
if(i>mid)
{
    while(j<=high)
    {
    temp[index] = arr[j];
    j++;
    index++;
    }
}
else
{
    while(i<=mid)
    {
    temp[index] = arr[i];
    i++;
    index++;
    }
}
for(k=low;k<index;k++)
    arr[k] = temp[k];
}


void merge_sort(int arr[], int low, int high)
{
int mid;
if(low<high)
{
mid = (low+high)/2;
merge_sort(arr, low, mid);
merge_sort(arr, mid+1, high);
merge(arr, low, mid, high);
}
}
