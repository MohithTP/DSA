#include<stdio.h>
int main(){
    int n, a[100][100],i,j,k,visited[100],count;
    int next;
    int distance[100];
    printf("Enter the no. of nodes");
    scanf("%d",&n);
    printf("Enter the elements");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    if(a[i][j]==0){
        a[i][j]=999;
    }
    printf("Enter the starting node:");
    scanf("%d",&k);
    for(i=0;i<n;i++){
        distance[i]=a[k][i];
        visited[i]=0;
    }
}