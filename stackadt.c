#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int size ,choice,top=-1;
int arr[MAX];
int main(){
    void push();
    void pop();
    void display();
    printf("Enter size of array:\n");
    scanf("%d",&size);
    do{
       printf("Enter your choice:\n");
       printf("\n1)push");
       printf("\n2)pop");
       printf("\n3)display");
       printf("\n4)exit\n");
       scanf("%d",&choice);

      switch(choice){
        case 1:
          push();
          break;
        case 2:
          pop();
          break;
        case 3:  
          display();
          break;
        case 4:
          printf("Gonna exit!");
          exit(0);
          break;
        default:
          printf("Invalid input\n");
    }
    }while(choice!=4);
    return 0;
}

void push(){
    
        int num;
        if(top==size-1){
            printf("Array is full\n");
        }else{
             printf("Enter the number  you want to push:\n");
            scanf("%d",&num);
            top=top+1;
            arr[top]=num;
            printf("Successfully inserted!\n");
        }    
}

void pop(){
        int num;
        if(!(top<=-1)){
            printf("Popped element:%d\n",arr[top]);
            top=top-1;
        }else{
             printf("array is underflow\n");
        }      
}

void display(){
    printf("the entered numbers are:");
        if(top>=0){
          for (int i=top;i>=0;i--){
            printf("%d\n",arr[i]);
          }
        }else{
            printf("array is empty\n");
        }    
}