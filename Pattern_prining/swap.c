#include<stdio.h>
int main(){
  int a;
  int b;
  printf("Enter the value of A \n");
  scanf("%d",&a);
  printf("Enter the value of B \n");
  scanf("%d",&b);
  a=a^b;
  b=b^a;
  a=a^b;
  printf("A: %d\n",a);
  printf("B: %d\n",b);
  return 0;
} 