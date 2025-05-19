#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>

void selectionsort(int arr[],int n){
    int min_ind;
    for(int i=0;i<n-1;i++){
        min_ind=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_ind]){
                min_ind=j;
            }
        }
        int temp = arr[min_ind];
        arr[min_ind] = arr[i];
        arr[i] = temp;
    }
}

int main(){
    struct timeval start,end;

    for(int i=1;i<=10;i++){
        int n=1000*i;
        int arr[n];
        arr[n]=rand()%(i+1);
        int size=sizeof(arr) / sizeof(arr[0]);
        gettimeofday(&start,NULL);
        selectionsort(arr,n-1);
        gettimeofday(&end,NULL);
        float time = (end.tv_usec - start.tv_usec)/1000000.0;
    printf("Time taken for %d elements : %f microseconds*\n", n, time);
    }
    return 0;
}