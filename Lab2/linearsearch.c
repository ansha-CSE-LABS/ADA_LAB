#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void delay(){
    int x;
    for(int i=0;i<5000;i++){
        x=123456/3;
    }
}
int main(){
    int n, arr[10000], key, i;
    clock_t start, end;

    printf("Enter value for n:");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        arr[i]=i;
    }
    key= arr[n-1];

    start = clock();
    for(i=0;i<n;i++){
        delay();
        if(arr[i]==key)
            break;
    }
    end = clock();

    printf("Execution time is %f\n", (double)(end-start/CLOCKS_PER_SEC));
    if(i<n)
        printf("Found at %d", i+1);
    else
        printf("Not found");
    return 0;
}

/*
Enter value for n:1000
Execution time is 2310.000000
Found at 1000

Enter value for n:2000
Execution time is 2439.000000
Found at 2000

Enter value for n:3000
Execution time is 3531.000000
Found at 3000

Enter value for n:4000
Execution time is 3841.000000
Found at 4000

Enter value for n:5000
Execution time is 4761.000000
Found at 5000

Enter value for n:6000
Execution time is 6384.000000
Found at 6000

Enter value for n:7000
Execution time is 7292.000000
Found at 7000

*/
