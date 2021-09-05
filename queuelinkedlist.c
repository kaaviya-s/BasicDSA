#include<stdio.h>
#include<stdlib.h>

struct node{
    int num;
    struct node* next;
};

struct node* front=NULL;
struct node* rear=NULL;


void push(){
    int data;

    struct node* temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter number:\n");
    scanf("%d",&data);
    temp->num=data;
    temp->next=NULL;
    if(rear==NULL){
        front=rear=temp;
    }
    else{
       rear->next=temp;
       rear=temp;
    }
  
}

void  pop(){
    
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp=front;

    if(front==NULL){
        printf("List is empty!\n");
    
    }else{    
        
        printf("The popped element:%d\n",front->num);
        front=front->next;
        free(temp);
    }
  
}    

void peek(){
    
    if(front==NULL&&rear==NULL){
        printf("List is empty!\n");
    }else{
        
        printf("The element that is in peek : %d\n",front->num);
    }
}

void display(){
    
    if(front==NULL&&rear==NULL){
        printf("List is empty!\n");
    }else{
        struct node* temp=(struct node*)malloc(sizeof(struct node));
        temp=front;
        while(temp!=NULL){
            printf("%d\n",temp->num);
            temp=temp->next;
        }
    }
}

int main(){

    int choice;
    printf("\t\t QUEUE\t\t\n");
    do{
        printf("Enter choice:\n");
        printf("1)push\n2)pop\n3)peek\n4)display\n5)exit\n");
        scanf("%d",&choice);

        switch(choice){
        case 1:
         push();
         break;
        case 2:
         pop();
         break;
        case 3:
         peek();
         break;
        case 4:
         display();
         break;
        case 5:
         exit(0);
        default:
         printf("\nINVALID POSITION");
        }
    }while(choice!=5);

    return 0;
}