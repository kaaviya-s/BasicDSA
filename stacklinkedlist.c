#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct node* push(struct node* top){
    int data;
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
     scanf("%d",&data);
     temp->data=data;
     temp->link=top;
     top=temp;
     printf("successfully inserted!\n");
     return top;
}

struct node* pop(struct node* top){
    if(top==NULL){
        printf("List is empty!\n");
    }else{
        struct node* temp=top;
        printf("The popped element is: %d\n",top->data);
        top=top->link;
        free(temp);
        return top;
    }
    
}

void peek(struct node* top){
    if(top==NULL){
        printf("List is empty!\n");
    }else{
        printf("The top element is:%d\n",top->data);
        
        
    }
    
}

void display(struct node* top){
    if(top==NULL){
        printf("List is empty!\n");
    }else{
        struct node* temp=(struct node*)malloc(sizeof(struct node*));
        temp=top;
        while(temp!=NULL){
            printf("%d\n",temp->data);
            temp=temp->link;
        }
    }
    
}

int main(){
    int choice;
    struct node* top=(struct node*)malloc(sizeof(struct node*));
    top=NULL;
    printf("\t\t STACK \t\t\n");
    do{
        printf("Enter choice:\n");
        printf("1)push\n2)pop\n3)peek\n4)display\n5)exit\n");
        scanf("%d",&choice);

        switch(choice){
        case 1:
         top=push(top);
         break;
        case 2:
         top=pop(top);
         break;
        case 3:
         peek(top);
         break;
        case 4:
         display(top);
         printf("done!\n");
         break;
        case 5:
         exit(0);
        default:
         printf("\nINVALID POSITION");
        }
    }while(choice!=5);    

      
    return 0;
}