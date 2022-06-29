#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100000

int linearSearch(int arr[], int n, int index, int key)
{
    if (index > n)
        return -1;
    else if (arr[index] == key)
        return index;
    else
        return linearSearch(arr, n, index + 1, key);
}

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
    int arr[SIZE], key, choice;
    clock_t start, end;
    int index = 0, n;
    double time_taken;

    while (choice != 3)
    {

        printf("\nChoose\n"
               "1. Linear Search\n"
               "2. Binary search\n"
               "3. Exit\n");
        scanf("%d", &choice);

        if (choice == 3)
            break;

        printf("Enter value for n:");
        scanf("%d", &n);

        for (int i = 0; i < n; i++)
        {
            arr[i] = i;
        }
        key = arr[n - 1];

        start = clock();
        switch (choice)
        {
        case 1:
            for (int i = 0; i < 1000; i++)
            {
                index = linearSearch(arr, n, 0, key);
            }
            break;

        case 2:
            for (int i = 0; i < 1000; i++)
            {
                index = binarySearch(arr, 0, n - 1, key);
            }
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
        end = clock();

        time_taken = (end - start) / (double)CLOCKS_PER_SEC * 1000;

        if (index == -1)
            printf("\nElement not found!\n");
        else
            printf("\nElement found at position %d\n", index);

        printf("Execution time is %lf\n", time_taken);
    }
}
