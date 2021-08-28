#include <stdio.h>
#include <stdlib.h>

struct node{
        int data;
        struct node* link;
    };

void insert(struct node* head,int data){
    
    if (head==NULL){
        head->data=data;
        head->link=NULL;
    }else{
        struct node* ptr=NULL;
        struct node* temp=NULL;
        temp=(struct node*)malloc(sizeof(struct node*));
        temp->data=data;
        temp->link=NULL;
        ptr=head;
        while(ptr->link!=NULL){
          ptr=ptr->link;
        }
        ptr->link=temp;
    }
    

}
void print(struct node*head){
    //head=(struct node*)malloc(sizeof(struct node));
    if(head==NULL){
        printf("List is empty\n");
    }else{
         struct node *ptr=NULL;
         ptr=head;
         if(head==NULL){
        printf("it is empty");
    }else{
        while(ptr->link!=NULL){
            printf("%d\n",ptr->data);
            ptr=ptr->link;
        }
    }
    }
   
}

void main(){
    struct node* head=NULL;

    int choice,num;
    do{
        printf("Enter your choice:\n");
        printf("1)INSERT\n3)DISPLAY\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
             printf("Enter a number:");
             scanf("%d",&num);
             insert(head,num);
             break;
            case 3:
             print(head);
             break;
            case 4:
             exit(0);
             break;
            
        }
    }while(choice!=4);
}
    