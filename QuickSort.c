#include<stdio.h>
#include<time.h>

void swap(int *a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int s,int e){
    int i,j;
    int m=arr[e];
    i=s-1;

    for(j=s;j<e;j++){
        if(arr[j]<arr[m]){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[e]);
    return i+1;
}

void quicksort(int arr[],int s,int e){
    if(s<e){
        int m=partition(arr,s,e);

        quicksort(arr,s,m-1);
        quicksort(arr,m+1,e);
    }
}



int main(){
    int n;
    printf("Enter values of n:");
    scanf("%d",&n);
    int a[n];
    printf("Enter array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    quicksort(a,0,n-1);
    printf("The resultant array is: ");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}