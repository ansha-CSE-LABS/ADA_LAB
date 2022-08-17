#include <stdio.h>
#define MAX 10

int max(int a, int b){
    return (a > b ? a : b);
}
int knapsack(int W, int wt[], int val[], int n)
{
    int i, w;
    int k[n + 1][W + 1];

    for (i = 0; i <= n; i++)
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                k[i][w] = 0;
            else if (wt[i - 1] <= w)
                k[i][w] = max(val[i - 1] + k[i - 1][w - wt[i - 1]], k[i - 1][w]);
            else
                k[i][w] = k[i - 1][w];
        }
    return k[n][W];
}
int main(void)
{
    int i, j, totalProfit, num;
    int weight[MAX], profit[MAX], loaded[MAX];
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

    int res = knapsack(capacity, weight, profit, num);
    printf("\nThe maximum profit is %d", res);
    return 0;
}
