#include<stdio.h>
int main(){
int A[100][100];
    int i,j,n;
    do {
    printf("entre n");
    scanf("%d" & n);}
    while(n<0)||(n>100);
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
         printf("A[%d][%d]=%d ",i,j,A[i][j]);
         scanf("%d" & A[i][j]);
        }
        printf("\n");
    }
    printf("le permutation \n");
       for (i=0; i<n; i++){
        for (j=0; j<n; j++){
         if (i!=j){
          A[j][i]=A[i][n-i-1];
        }
        printf(" %d ",A[i][j]);
        }printf("\n");}
    return 0;
    }