#include <stdio.h>
#include <time.h>

void delay(){
    int k,i;
    for (i=0; i<10000;i++){
        for(int j=0;j<500;j++)
            k=1234/55;
    }
}

int linearsearch (int arr[], int n, int key){
    int res;
    n--;
    delay();

    if(n>=0){
        if(arr[n]==key)
            return n;
        else{
            res = linearsearch(arr,n,key);
        }
    }
    else
        return -1;

    return res;
}

int binarysearch(int array[], int start_index, int end_index, int element){
    delay();
    if (end_index >= start_index){
      int middle = start_index + (end_index - start_index )/2;
      if (array[middle] == element)
         return middle;
      if (array[middle] > element)
         return binarysearch(array, start_index, middle-1, element);
      return binarysearch(array, middle+1, end_index, element);
   }
   return -1;
}

int main(){
    int n, arr[10000],key,choice;
    clock_t start,end;
    int res;

    printf("Enter value for n:");
    scanf("%d",&n);

    for (int i=0;i<n;i++){
        arr[i]=i;
    }
    key = arr[0];
    //key=-5;
    int initial =0, final = n;

    printf("Choose 1. Linear Search\n"
            "2.Binary search\n");
    scanf("%d",&choice);

    start = clock();
    switch(choice){
        case 1: res = linearsearch(arr,n,key);
                break;

        case 2: res = binarysearch(arr,initial,final,key);
                break;
    }
    end = clock();

    if(res!=-1)
        printf("Element found at position %d\n",res);
    else
        printf("Element not found!\n");

    printf("Execution time is %f\n",(double)((end-start)/CLOCKS_PER_SEC));

    return 0;
}



