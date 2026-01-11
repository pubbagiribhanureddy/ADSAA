#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a Jobs
typedef struct Jobs {
   char id; // Jobs Id
   int dead; // Deadline of Jobs
   int profit; // Profit if Jobs is over before or on deadline
} Jobs;

// This function is used for sorting all Jobs according to profit
int compare(const void* a, const void* b){
   Jobs* temp1 = (Jobs*)a;
   Jobs* temp2 = (Jobs*)b;
   return (temp2->profit - temp1->profit);
}

// Find minimum between two numbers.
int min(int num1, int num2){
   return (num1 > num2) ? num2 : num1;
}
int main(){
   Jobs arr[] = { 
      { 'a', 2, 100 },
      { 'b', 2, 20 },
      { 'c', 1, 40 },
      { 'd', 3, 35 },
      { 'e', 1, 25 }
   };
   int n = sizeof(arr) / sizeof(arr[0]);
   printf("Following is maximum profit sequence of Jobs: \n");
   qsort(arr, n, sizeof(Jobs), compare);
   int result[n]; // To store result sequence of Jobs
   bool slot[n]; // To keep track of free time slots
   int TF=0;

   // Initialize all slots to be free
   for (int i = 0; i < n; i++)
      slot[i] = false;

   // Iterate through all given Jobs
   for (int i = 0; i < n; i++) {

      // Find a free slot for this Job
      for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {

         // Free slot found
         if (slot[j] == false) {
            result[j] = i;
            slot[j] = true;
            break;
         }
      }
   }

   // Print the result
   for (int i = 0; i < n; i++)
      if (slot[i])
      {
    printf("\n%c \t %d ", arr[result[i]].id,arr[result[i]].profit);
     TF+=arr[result[i]].profit;
      }
   printf("\n TotalProfit gained :\t%d",TF);
   return 0;
}
