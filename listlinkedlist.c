#include<stdio.h>
#include<stdlib.h>

struct box{
    int data;
    struct box* link;
};

struct box* head=NULL;

int count(struct box* head){
     int count;
     struct box* ptr=head;
     while(ptr!=NULL){
         count++;
         ptr=ptr->link;
     }
     return count;
}

struct box* insert(struct box* head,int no){
    
    int num;
    int pos;
    int i=1;
    struct box* temp=(struct box*)malloc(sizeof(struct box));
    struct box* ptr=(struct box*)malloc(sizeof(struct box));
    struct box* link=NULL;
    if(head==NULL){
        temp->data=no;
        temp->link=NULL;
        head=temp;
        printf("Inserted successfully!!\n");
        return head;
    }else{
        printf("Enter 0(For inserting at specific position) or 1(For appending):\n");
        scanf("%d",&num);
      switch(num){
        case 0:
         ptr=head;
         int nodes=count(head);
         printf("Enter position:\n");
         scanf("%d",&pos);
         temp->data=no;
         temp->link=NULL;
         if(pos>nodes){
             printf("Invalid position\n");
         }else{
             while(i<pos-1){
                 ptr=ptr->link;
                 i++;
             }
             temp->link=ptr->link;
             ptr->link=temp;
             return head;
         }
         
         break;

        case 1:
         link=head;
         temp->data=no;
         temp->link=NULL;
         while(link->link!=NULL){
            link=link->link;
         }
         link->link=temp;
         printf("Done!\n");
         return head;
         break;
       }
    
    }
}
    


struct box*  delete(struct box* head){
    int pos;
    printf("Enter position:\n");
    scanf("%d",&pos);
    int len=count(head);
    if(pos>len){
        printf("Invalid position\n");
    }else{
        int i=1;
        struct box* ptr=NULL;
        struct box* node=NULL;
        ptr=head;
        while(i<pos-1){
            ptr=ptr->link;
            i++;
        }
        node=ptr->link;
        ptr->link=node->link;
        free(node);
    }
    return head;
}

void display(struct box* head){
    if(head==NULL){
        printf("List is empty!\n");
    }else{
        struct box* ex=NULL;
        printf("Invoked\n");
        ex=head;
        while(ex!=NULL){
        printf("%d\n",ex->data);
        ex=ex->link;
    }
    }

}


int main(){
    
    int choice,no,num;
    
    do{
        printf("Enter choice:\n");
        printf("1)INSERT\n2)DELETE\n3)DISPLAY\n4)EXIT\n");
        scanf("%d",&choice);
        switch(choice){
          case 1:
             printf("Enter number:\n");
             scanf("%d",&no);
             head=insert(head,no);
              break;
         case 2:
            head=delete(head);
             break;
         case 3:
            display(head);
            break;
         case 4:
           exit(0);
           break;
         default:
           printf("Invalid position\n");
         
         
       }
    }while(choice!=4);
    
    return 0;
}