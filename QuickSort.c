#include<stdio.h>
#include<time.h>

void swap(int *a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[],int s,int e){
    int i,j;
    int pivot=arr[s];
    i=s+1;
    j=e;
    while(i<=j){
        while(i<=e && arr[i]<=pivot) i++;
        while(arr[j]>pivot) j--;
        if (i < j) swap(&arr[i], &arr[j]);
    }
    swap(&arr[s], &arr[j]); 
    return j;

}

void quicksort(int arr[],int s,int e){
    if(s<e){
        int m=partition(arr,s,e);

        quicksort(arr,s,m-1);
        quicksort(arr,m+1,e);
    }
}

int duplicates(int arr[],int n){
    for(int i=0;i<n;i++){
        if(arr[i]==arr[i+1]){
            return arr[i+1];
        }
    }
    return -1;

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
    int dup=duplicates(a,n);
    printf("\nThe duplicate is: %d",dup);
    return 0;
}