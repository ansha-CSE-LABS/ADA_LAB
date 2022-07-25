#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t start, end;
double time_taken;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selection_sort(int arr[], int n)
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(&arr[min], &arr[i]);
    }
}
int main(void)
{
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];

    for (int i = n; i > 0; i--)
    {
        arr[n - i] = i;
    }

    start = clock();
    selection_sort(arr, n);
    end = clock();

    // printf("\nSorted array: ");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", arr[i]);
    // }

    time_taken = (end - start) / (double)CLOCKS_PER_SEC * 10000;
    printf("\nTime taken: %f\n", time_taken);

    return 0;
}
