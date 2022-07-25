//insertion sort optimised for worst case scenario with time as output for 100 readings

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000

void insertionSort(int array[], int size)
{
    for (int step = 1; step < size; step++)
    {
        int key = array[step];
        int j = step - 1;

        while (key < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

int main(void)
{
    int n = 100;
    printf("time taken each, for 100 observations");
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
            insertionSort(a, n);
        }

        end = clock();
        printf("%f\n", (double)(end - start) / CLOCKS_PER_SEC * 1000);
        n = n + 100;
    }
    printf("\n Each insertion sort for 1000 iterations");
    return 0;
}
