#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

int binarySearch(int arr[], int l, int r, int key)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] > key)
            return binarySearch(arr, l, mid - 1, key);
        return binarySearch(arr, mid + 1, r, key);
    }
    return -1;
}

int main(void)
{
    int n = 100;
    int arr[SIZE], key, choice;
    clock_t start, end;
    int index = 0;
    double time_taken;

    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
    key = arr[n - 1];
    printf("time in ms for 1000 observations\n");

    while (n < SIZE)
    {
        int a[n];
        clock_t start, end;
        start = clock();
        for (int i = n; i > 0; i--)
        {
            a[i] = i;
        }
        for (int i = 0; i < 100000; i++)
        {
            index = binarySearch(arr, 0, n - 1, key);
        }

        end = clock();
        printf("%f\n", (double)(end - start) / CLOCKS_PER_SEC * 1000);
        n = n + 100;
    }
    printf("\n Each binary search for 100000 iterations");
    return 0;
}
