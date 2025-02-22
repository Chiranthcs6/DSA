#include<stdio.h>
int main(){
  int i,j,n;
  printf("Enter the number of rows");
  scanf("%d",&n);
  //Upper part
  for(i=1;i<=n;i++){
    for(j=1;j<=i;j++){
      printf("*");
    }
    for(j=1;j<=2*(n-i);j++){
      printf(" ");
    }
    for(j=1;j<=i;j++){
      printf("*");
    }
    printf("\n");
  }
  //Lower part
  for(i=n;i>=1;i--){
    for(j=1;j<=i;j++){
      printf("*");
    }
    for(j=1;j<=2*(n-i);j++){
      printf(" ");
    }
    for(j=1;j<=i;j++){
      printf("*");
    }
    printf("\n");
  }
  return 0;
}