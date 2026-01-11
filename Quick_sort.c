#include<stdio.h>
void Quick_Sort(int a[],int low,int high);

int main()
{
int a[25];
int i,j,temp,n,key;
printf("------QUICK SORT------\n");
printf("Enter the no.of elements : ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter a[%d] element : ",i);
scanf("%d",&a[i]);
}
printf("Before Sorting array elements are : ");
for(i=0;i<n;i++)
{
printf("%d ",a[i]);
}
Quick_Sort(a,0,n-1);
printf("\nAfter Sorting array elements are : ");
for(i=0;i<n;i++)
{
printf("%d ",a[i]);
}
}

void Quick_Sort(int a[],int low,int high)
{
int pivot,i,j,temp;
i=low;
j=high;
pivot=low;
while(i<j)
{
while(a[i]<=a[pivot]&&i<=high)
    i++;
while(a[j]>=a[pivot]&&j>low)
    j--;
if(i<j)
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
if(i>j)
{
temp=a[pivot];
a[pivot]=a[j];
a[j]=temp;
pivot=j;
}
if(low<pivot)
    Quick_Sort(a,low,pivot-1);
if(high>pivot)
    Quick_Sort(a,pivot+1,high);
}
