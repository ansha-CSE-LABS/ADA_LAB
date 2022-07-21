#include <stdio.h>
#include <time.h>

#define MAX 10000

void merge(int a[], int i1, int j1, int i2, int j2)
{
    int temp[MAX];
    int i, j, k;
    i = i1;
    j = i2;
    k = 0;
    while (i <= j1 && j <= j2)
    {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while (i <= j1)
        temp[k++] = a[i++];
    while (j <= j2)
        temp[k++] = a[j++];

    for (i = i1, j = 0; i <= j2; i++, j++)
        a[i] = temp[j];
}

void mergesort(int a[], int i, int j)
{
    int mid;
    if (i < j)
    {
        mid = (i + j) / 2;
        mergesort(a, i, mid);
        mergesort(a, mid + 1, j);
        merge(a, i, mid, mid + 1, j);
    }
}

int main(void)
{
    int n = 100;
    while (n < MAX)
    {
        int a[n];
        clock_t start, end;
        start = clock();
        for (int i = n; i > 0; i--)
        {
            a[i] = i;
        }
        for (int i = 0; i < 100; i++)
        {
            mergesort(a, 0, n - 1);
        }

        end = clock();
        printf("%f\n", (double)(end - start) / CLOCKS_PER_SEC);
        n = n + 100;
    }
    printf("\n Each merge sort for 100 iterations");
    return 0;
}
