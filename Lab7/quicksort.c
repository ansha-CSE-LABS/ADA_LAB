#include <stdio.h>
#include <time.h>

#define MAX 10000

int partition(int a[], int l, int u){
    int v, i, j, temp;
    v = a[l];
    i = l;
    j = u + 1;
    do{
        do
            i++;
        while (a[i] < v && i <= u);
        do
            j--;
        while (v < a[j]);
        if (i < j){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);
    a[l] = a[j];
    a[j] = v;
    return (j);
}

void quick_sort(int a[], int l, int u)
{
    int j;
    if (l < u){
        j = partition(a, l, u);
        quick_sort(a, l, j - 1);
        quick_sort(a, j + 1, u);
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
        for (int i = n; i > 0; i--){
            a[i] = i;
        }
        quick_sort(a, 0, n - 1);

        end = clock();
        printf("%f\n", (double)(end - start) / CLOCKS_PER_SEC);
        n = n + 100;
    }
    return 0;
}
