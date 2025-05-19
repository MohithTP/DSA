#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>

void merge(int arr[], int s,int m,int e){

    int i,j,k;
    int n1=m-s+1;
    int n2=e-m;

    int *arr1=(int*)malloc(n1*sizeof(int));
    int *arr2=(int*)malloc(n2*sizeof(int));

    for(i=0;i<n1;i++){
        arr1[i]=arr[s+i];
    }
    for(j=0;j<n2;j++){
        arr2[j]=arr[m+1+j];
    }
    i=0;
    j=0;
    k=s;

    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            arr[k]=arr1[i];
            i++;
        }
        else{
                arr[k]=arr2[j];
                j++;
            }
        k++;
    }

    while(i<n1){
        arr[k]=arr1[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=arr2[j];
        j++;
        k++;
    }
    free(arr1);
    free(arr2);
}
void sort(int arr[],int start,int end){

    if(start<end){
        int m = (start+end)/2;
        sort(arr,start,m);
        sort(arr,m+1,end);

        merge(arr,start,m,end);
    }
   
}
int main(){
    struct timeval start, end;
    //int size;
    // printf("Enter size of array:");
    // scanf("%d", &size);
    // int arr[size];
    // printf("Enter elements:\n");
    // for (int i = 0; i < size; i++) {
    //     scanf("%d", &arr[i]);
    // }
    // printf("Array:\n");
    // for (int i = 0; i < size; i++) {
    //     printf("%d ", arr[i]);
    // }

    // start = clock();
    // sort(arr, 0, size - 1);
    // end = clock();
    // time = (double)(end - start) / CLOCKS_PER_SEC;

    // printf("\nSorted Array:\n");
    // for (int i = 0; i < size; i++) {
    //     printf("%d ", arr[i]);
    // }
    // printf("\nTime: %lf", time);
    for(int i=1;i<=10;i++){
        int n=i*1000;
        int arr[n];
        arr[n]=rand()%(i+1);
        int size=sizeof(arr) / sizeof(arr[0]);
        gettimeofday(&start,NULL);
        sort(arr, 0, n - 1);
        gettimeofday(&end,NULL);
        float time = (end.tv_usec-start.tv_usec)/1000000.0; 
        printf("No. of elements is %d, Time take is %f\n",n,time);
    }
    return 0;

}