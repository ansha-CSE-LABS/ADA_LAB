#include <stdio.h>

void manage(int *arr, int i)
{
    int tmp;
    tmp = arr[i];
    while ((i > 1) && (arr[i / 2] < tmp))
    {
        arr[i] = arr[i / 2];

        i = i / 2;
    }
    arr[i] = tmp;
}

void heapsort(int *arr, int i, int size)
{
    int tmp, j;
    tmp = arr[i];
    j = i * 2;
    while (j <= size)
    {
        if ((j < size) && (arr[j] < arr[j + 1]))
            j++;

        if (arr[j] < arr[j / 2])
            break;
        arr[j / 2] = arr[j];
        j = j * 2;
    }
    arr[j / 2] = tmp;
}
int main(void)
{
    int arr[20];
    int i, j, size, tmp, k;

    printf("Enter the number of elements to sort : ");
    scanf("%d", &size);
    printf("Enter The element In Array\n");

    for (i = 1; i <= size; i++)
    {
        scanf("%d", &arr[i]);
        manage(arr, i);
    }
    j = size;
    for (i = 1; i <= j; i++)
    {
        tmp = arr[1];
        arr[1] = arr[size];
        arr[size] = tmp;
        size--;
        heapsort(arr, 1, size);
    }
    size = j;
    printf("Sorted Elements:\t");

    for (i = 1; i <= size; i++)
        printf("%d\t ", arr[i]);

    return 0;
}
