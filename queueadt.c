#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int front=0,rear=0,size,choice,num;
int q[MAX];
int main(){
    void insert();
    void delete();
    void display();
    printf("\tQueue ADT\n");
    printf("Enter the size of queue:\n");
    scanf("%d",&size);
    do{
        printf("Enter your choice:\n");
        printf("1)Push\n");
        printf("2)Pop\n");
        printf("3)Display\n");
        printf("4)Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
             insert();
             break;
            case 2:
             delete();
             break;
            case 3:
             display();
             break;
            case 4:
             exit(0);
             break;
            default:
             printf("Invalid input\n");
        }
    }while(choice!=4);
    return 0;
}

void insert(){
    if(rear>=size){
        printf("Queue is full!\n");
    }else{
        printf("Enter the number:\n");
        scanf("%d",&num);
        q[rear]=num;
        rear++;
    }
}

void delete(){
    if(front==rear){
        printf("Queue is empty\n");
    }else{
        printf("The deleted element:%d\n",q[front]);
        for (int i=0;i<rear;i++){
            q[i]=q[i+1];
        } 
    }
    rear--;
}

void display(){
    if(front==rear){
        printf("Queue is empty!\n");
    }else{
        printf("The numbers you insereted were:\n");
        for(int i=front;i<rear;i++){
            printf("%d\n",q[i]);
        }
    }
}