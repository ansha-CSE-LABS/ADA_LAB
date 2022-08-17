#include <stdio.h>

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
    int arr[20];
    int i, j, size;

    printf("Enter the number of elements to sort : ");
    scanf("%d", &size);
    printf("Enter elements of array:\n");
    for (i = 1; i <= size; i++)
    {
        scanf("%d", &arr[i]);
    }

    heapsort(arr, size);

    printf("Sorted elements:\t");

    for (i = 1; i <= size; i++)
        printf("%d\t ", arr[i]);

    return 0;
}
