#include <stdio.h> 
#include <stdlib.h> 
// Structure for a job 
typedef struct { 
char id;       
// Job ID (A, B, C, ...) 
int deadline;  // Deadline of job 
int profit;    // Profit if job is done 
} Job; 
// Compare function for sorting jobs by descending profit 
int compare(const void *a, const void *b) { 
Job *j1 = (Job *)a; 
Job *j2 = (Job *)b; 
return j2->profit - j1->profit;  // descending order 
} 
// Function to find maximum of two numbers 
int max(int a, int b) { 
return (a > b) ? a : b; 
} 
// Function to schedule jobs to maximize profit 
void jobSequencing(Job jobs[], int n) { 
// Step 1: Sort all jobs by profit (high -> low) 
qsort(jobs, n, sizeof(Job), compare); 
// Step 2: Find maximum deadline 
int maxDeadline = 0; 
for (int i = 0; i < n; i++) 
maxDeadline = max(maxDeadline, jobs[i].deadline); 
// Step 3: Create a time slot array 
int slot[maxDeadline + 1]; 
for (int i = 0; i <= maxDeadline; i++) 
slot[i] = -1;  // -1 means free slot 
// Step 4: Fill slots for jobs 
int totalProfit = 0; 
int jobsDone = 0; 
for (int i = 0; i < n; i++) { 
// try to put job in its last possible slot 
for (int j = jobs[i].deadline; j > 0; j--) { 
if (slot[j] == -1) { 
slot[j] = i;   // assign this job 
totalProfit += jobs[i].profit; 
jobsDone++; 
break; 
} 
        } 
    } 
 
    // Step 5: Print the scheduled jobs 
    printf("Scheduled Jobs: "); 
    for (int i = 1; i <= maxDeadline; i++) { 
        if (slot[i] != -1) 
            printf("%c ", jobs[slot[i]].id); 
    } 
    printf("\nTotal Jobs Done: %d", jobsDone); 
    printf("\nTotal Profit: %d\n", totalProfit); 
} 
 
// Main function 
int main() { 
    int n; 
    printf("Enter number of jobs: "); 
    scanf("%d", &n); 
 
    Job jobs[n]; 
    printf("Enter Job ID, Deadline, Profit for each job:\n"); 
    for (int i = 0; i < n; i++) { 
        scanf(" %c %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit); 
    } 
 
    jobSequencing(jobs, n); 
 
    return 0; 
} 