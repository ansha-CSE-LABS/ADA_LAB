#include <stdio.h>

int min(int a, int b)
{
    return (a < b ? a : b);
}
void floyd(int w[][10], int n)
{
    int i, j, k;
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
}
int main()
{
    int a[10][10];
    int n, i, j;
    printf("Enter the number of vertices:");
    scanf("%d", &n);
    printf("Enter the weighted matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    floyd(a, n);
    printf("\n All pairs shortest path\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
