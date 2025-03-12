#include<stdio.h>
void print(int n){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(j==i||j==n-i-1){
        printf("*");
      }
      else
        printf(" ");
    }
    printf("\n");
  }
  
}
int main(){
  int size;
  printf("Enter the size of X:");
  scanf("%d",&size);
  if(size<2){
    printf("The size should be greater than 2.");
    return 1;
  }
  print(size);
  return 0;
}
