#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000

void delay(){
    for(int i=0; i<100000; i++){
        int k = 2222/55;
    }
}

void insertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;

    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}

void display(int arr[],int n)
{
    for(int i=0; i<n ; i++)
    {
        printf("%d\t",arr[i]);
    }
}

int main(void)
{
    int n, arr[SIZE];
    clock_t start, end;
    double time_taken;

    printf("Enter array size:");
    scanf("%d",&n);

    for(int i=n; i>=0; i--)
    {
        arr[n-i]=i;
    }


    display(arr,n);

    start = clock();
    delay();
    for(int i=0; i<10000; i++)
    {
        insertionSort(arr,n);
    }
    end = clock();

    time_taken = (end-start)/(double)CLOCKS_PER_SEC *10000;

    printf("\n\n");
    display(arr,n);

    printf("\nTime taken to execute insertion sort is %lf for 10000 iiterations\n",time_taken);

    return 0;

}
