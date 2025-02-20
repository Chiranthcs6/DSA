#include<stdio.h>
int main(){
  int i,j,n;
  n=5;
  for(i=0;i<n;i++){
    if(i==0 || i==(n-1)){
      for(j=0;j<n;j++){
        printf("* ");
      }
      
    }
    else{
      for(j=0;j<n-i-1;j++){
        printf("  ");
      }
      printf("* ");
    }
  printf("\n");
  }
  return 0;
}