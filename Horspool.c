#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 256

void shifttable(char pattern[],int shift[]){
    int m=strlen(pattern);
    for(int i=0;i<256;i++) shift[i]=m;
    for(int i=0;i<m-1;i++) shift[(unsigned char)pattern[i]]=m-1-i;

}
void horspool(char text[],char pattern[]){
    int n=strlen(text);
    int m=strlen(pattern);
    int shift[MAX];
    shifttable(pattern,shift);

    int i=m-1;
    int found=0;
    while(i<n){
        int k=0;
        while(k<m && pattern[m-1-k]==text[i-k]) k++;
        if(k==m){
            printf("Pattern found at index %d\n", i - m + 1);
            found = 1;
        }
        i += shift[(unsigned char)text[i]];
    }
    if (!found) printf("Pattern not found.\n");

}
int main(){
    char text[100],pattern[100];
    printf("Enter the string: ");
    fgets(text,sizeof(text),stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter the pattern: ");
    fgets(pattern,sizeof(pattern),stdin);
    pattern[strcspn(pattern, "\n")] = '\0';

    horspool(text,pattern);
    return 0;
    
}