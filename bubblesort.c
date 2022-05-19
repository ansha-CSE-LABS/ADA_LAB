#include <stdio.h>
#include <time.h>
     
void swap(int *x, int*y){
    int temp = *x;
    *x=*y;
    *y=temp;
}

void sort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}
void display(int arr[],int n){
    for(int i=0; i<n ;i++){
        printf("%d\n",arr[i]);
    }
}
int main(void)
{
    int n;
    printf("Ënter n:");
    scanf("%d",&n);
    
    int arr[n];
    printf("enter array elements:\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Original array is:");
    
    display(arr,n);
    
    clock_t t;
    t = clock();
    
    sort(arr,n);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
  
    printf("\nsort() took %f seconds to execute \n", time_taken);
    
    printf("\nSorted array is:\n");
    display(arr,n);
    
}
