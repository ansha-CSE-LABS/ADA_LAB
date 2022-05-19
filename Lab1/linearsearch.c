#include <stdio.h>
#include <time.h>

int main(void)
{
    int n,flag=0;
    printf("Ënter n:");
    scanf("%d",&n);
    
    int arr[n];
    printf("enter array elements:\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    int key;
    printf("Enter key:");
    scanf("%d",&key);
    
    clock_t t;
    t = clock();
    
    for(int i=0;i<n; i++){
        if(arr[i]==key)
            flag=1;
    }
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
  
    printf("\nLinear search took %f seconds to execute \n", time_taken);
    
    if(flag==1)
        printf("Element found");
    else
        printf("Element not found");
}
