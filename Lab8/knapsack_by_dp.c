#include <stdio.h>

#define MAX 10

int max(int a, int b)
{
    return a > b ? a : b;
}
// w - weight, p - profit
// n - number of items, c - knapsack capacity
void profitTable(int w[MAX], int p[MAX], int n, int c, int t[MAX][MAX])
{
    int i, j;

    for (j = 0; j <= c; j++)
        t[0][j] = 0;

    for (i = 0; i <= n; i++)
        t[i][0] = 0;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= c; j++)
        {
            if (j - w[i] < 0)
                t[i][j] = t[i - 1][j];
            else
                t[i][j] = max(t[i - 1][j], p[i] + t[i - 1][j - w[i]]);
        }
    }
}

void backtrackSelect(int n, int c, int t[MAX][MAX], int w[MAX], int l[MAX])
{
    int i, j;
    i = n;
    j = c;

    while (i >= 1 && j >= 1)
    {
        if (t[i][j] != t[i - 1][j])
        {
            l[i] = 1;
            j = j - w[i];
            i--;
        }
        else
            i--;
    }
}
int main(void)
{
    int i, j, totalProfit,num;
    int weight[MAX],profit[MAX],loaded[MAX];
    int capacity;
    int table[MAX][MAX];
    
    printf("Enter the maxium number of objects : ");
    scanf("%d", &num);

    printf("Enter the weights : \n");
    for (i = 1; i <= num; i++)
    {
        printf("\nWeight of %d:", i);
        scanf("%d", &weight[i]);
    }
    printf("\nEnter the profits : \n");
    for (i = 1; i <= num; i++)
    {
        printf("\nProfit of %d:", i);
        scanf("%d", &profit[i]);
    }
    printf("\nEnter the capacity : ");
    scanf("%d", &capacity);

    totalProfit = 0;

    for (i = 1; i <= num; i++)
        loaded[i] = 0;

    profitTable(weight, profit, num, capacity, table);
    backtrackSelect(num, capacity, table, weight, loaded);
    printf("\nProfit matrix : \n");
    for (i = 0; i <= num; i++)
    {
        for (j = 0; j <= capacity; j++)
        {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }

    printf("\nLoaded items : \n");
    for (i = 1; i <= num; i++)
    {
        if (loaded[i])
        {
            printf("%d ", i);
            totalProfit += profit[i];
        }
    }
    printf("\nTotal profit : %d", totalProfit);
    return 0;
}
