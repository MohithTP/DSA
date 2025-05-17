#include<stdio.h>
#define Max 100
int stack[Max];
int top=-1;
void topology(int matrix[Max][Max],int n){
   int in[Max]={0};
   int visited[Max]={0};
   for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(matrix[i][j]==1){
            in[j]++;
        }
    }
   }
   int count=0;
   while(count<n){
    int found=0;
    for(int i=0;i<n;i++){
        if(in[i]==0 && !visited[i]){
            stack[++top]=i;
            found=1;
            visited[i]=1;
            break;
        }
    }
    if(!found) {
        printf("Cycle detected! Topological sort not possible.\n");
        return;
    }

    int node = stack[top--];
    printf("%d ", node);
    //printf("%c",node+'A'); // If input is alphabet
    count++;

        for (int j = 0; j < n; j++) {
            if (matrix[node][j] == 1)
                in[j]--;
        }
    }
}
int main(){
    int n, matrix[Max][Max];
    printf("Enter no. of vertices: ");
    scanf("%d",&n);

    printf("Enter the adjacent matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    printf("Topological Sort: ");
    topology(matrix,n);
    return 0;

}