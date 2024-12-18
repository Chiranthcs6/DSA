#include<stdio.h>
#include<stdlib.h>
# define MAX 10

int s[MAX];
int top=-1;

void push(int item);
int pop();
void palindrome();
void display();
void main(){
    int choice,item;
    while(1){
        printf("\n------------------MENU CONTENT-------------------\n");
        printf("\n 1.Push to stack");
        printf("\n 2.Pop from stach");
        printf("\n 3.Palindrome");
        printf("\n 4.Display");
        printf("\n Enter your choice");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\n Enter the element to push to  stack");
                scanf("%d",&item);
                push(item);
                break;

            case 2:
                item=pop();
                if(top!=-1)
                    printf("The element poped from the stack is %d \n", item);
                break;

            case 3:
                palindrome();
                break;
            
            case 4:
                display();
                break;
            default:
                printf("Enter a valid choice. \n");
        }
    }
}
void push(int item){
    if(top==MAX-1){
        printf("\n---------STACK OVERFLOW-------------\n");
        return;
        }
        top=top+1;
        s[top]=item;
        printf("%d item pushed to the stack.\n",item);
    }
int pop(){
    int item;
    if(top==-1){
        printf("\n------------STACK EMPTY-------------\n");
        return -1;
    }
    item=s[top];
    top=top-1;
    return item;
}
void display(){
    int i;
    if(top==-1){
        printf("\n-----------STACK EMPTY-------------\n");
        return;
    }
    printf("\n Stack elements are: \n");
    for(i=top;i>=0;i--){
        printf("|%d|\n",s[i]);
    }
}
void palindrome(){
    int flag=1,i;
    if(top==-1){
        printf("Stack empty\n");
        return;
    }
    for(i=0;i<=top/2;i++){
    if(s[i]!=s[top-i]){
        flag=0;
        break;
    }}
    if(flag==1){
        printf("It's palindrome ");
    }
    else{
        printf("It's not palindrome");
    }
}
