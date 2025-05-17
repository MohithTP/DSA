#include<stdio.h>

void insertion(int arr[],int n){
    int key=0;
    for(int i=1;i<n;i++){
        key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main(){
    int arr[]={2,4,1,3};
    insertion(arr,4);
    for (int i = 0; i < 4; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}