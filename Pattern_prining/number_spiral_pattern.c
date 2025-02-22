#include<stdio.h>
int main(){
  int i,j,n;
  printf("Enter the number of rows");
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      if(i==1 || i==n || j==1 || j==n ){
        printf("1 ");}
      else if(i==2 || i==n-1 || j==2 || j==n-1){
        printf("2 ");
      }
      else{
        printf("3 ");
      }
      
    }
    printf("\n");
  }
  return 0;
}