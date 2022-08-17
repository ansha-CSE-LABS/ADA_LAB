#include <stdio.h>
#include <time.h>

#define SIZE 1000

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i;
    int r = (2 * i) + 1;

    if (l <= n && arr[l] > arr[largest])
        largest = l;
    if (r <= n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapsort(int arr[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n; i >= 1; i--)
    {
        swap(&arr[1], &arr[i]);
        heapify(arr, i - 1, 1);
    }
}

int main(void)
{
    int n = 100;
    printf("\nTime taken each, for 10 observations:\n");
    while (n < SIZE)
    {
        int a[n];
        clock_t start, end;
        start = clock();
        for (int i = n; i > 0; i--)
        {
            a[n - i] = i;
        }
        for (int i = 0; i < 1000; i++)
        {
            heapsort(a, n);
        }
        end = clock();
        printf("%f\n", (double)(end - start) / CLOCKS_PER_SEC * 1000);
        n = n + 100;
    }
    printf("\nEach heap sort for 1000 iterations");
    return 0;
}
