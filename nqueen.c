#include <stdio.h>
#include <stdlib.h>   // for abs()
#include <conio.h>    // optional (for getch), only works on Turbo C or Windows compilers

int x[30], count = 0;

int place(int pos)
{
    int i;
    for (i = 1; i < pos; i++)
    {
        if ((x[i] == x[pos]) || (abs(x[i] - x[pos]) == abs(i - pos)))
            return 0;
    }
    return 1;
}

void printboard(int n)
{
    int i, j;
    count++;
    printf("\n\nSolution %d:\n", count);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (x[i] == j)
                printf("Q%d\t", i);
            else
                printf("*\t");
        }
        printf("\n");
    }
}

void queen(int n)
{
    int k = 1;
    x[k] = 0;
    while (k != 0)
    {
        x[k] = x[k] + 1;
        while ((x[k] <= n) && !place(k))
            x[k]++;
        if (x[k] <= n)
        {
            if (k == n)
                printboard(n);
            else
            {
                k++;
                x[k] = 0;
            }
        }
        else
            k--;
    }
}

int main()
{
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    queen(n);
    printf("\nPossible solutions: %d", count);
    getch();  // remove this if using GCC on Linux
    return 0;
}
