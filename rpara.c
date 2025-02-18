#include<stdio.h>
int main(){
  int i,j,n,k;
  printf("Enter the number of rows");
  scanf("%d",&n);

  for(i=n-1;i>=0;i--){
    for(j=0;j<n-i-1;j++){
      printf(" ");
    }
    for(k=0;k<n;k++){
      printf("*");
    }
    printf("\n");
  }
  return 0;
}