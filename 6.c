#include<stdio.h>
#include<stdlib.h>
#define MAX 5

char circular_queue[MAX];
int front=1,rear=-1;

int isEmpty(){
    if(front==-1 && rear ==-1)
    return 1;
    else
    return 0;
}
int isFull(){
    if((rear+1)%MAX==front)
    return 1;
    else
    return 0;
}
void insertElement(char element){
    if(isFull()){
        printf("Stack is full\n");
        return;
    }
    else if(isEmpty()){
        front=rear=0;
    }
    else{
        rear=(rear+1)%MAX;
    }
    circular_queue[rear]=element;
}
void deleteElement(){
    if(isEmpty()){
        printf("Stack is empty \n");
    }
    else if(isFull()){
        front=rear=-1;
    }
    else{
        front=(front+1)%MAX;
    }
}
void display(){
    int i;
    if(isEmpty()){
        printf("Circular queue is Empty\n");
    }
    printf("Circular queue elements are:");
    i=front;
    do{
        printf("%c",circular_queue[i]);
        i=(i+1)%MAX;
    }while(i!=(rear+1)%MAX);
    printf("\n");
    
}
int main(){
    int choice;
    char element;
    while(choice!=4){
    printf("\n----------MENU CONTENT-------------\n");
    printf("1.Inset to stack \n");
    printf("2.Delete from stack \n");
    printf("3.Display circular queue \n");
    printf("4.Exit \n");
    scanf("%d",&choice);
    getchar();
    switch (choice){ 
        case 1:
        printf("Enter the element: \n");
        scanf("%c",&element);
        insertElement(element);
        break;

        case 2:
        deleteElement();

        break;

        case 3:
        display();
        break;

        case 4:
        printf("Exisitng.....\n");
        break;

        default:
        printf("Enter a valid choice!");
        break;


    }
   
}
return 0;
}