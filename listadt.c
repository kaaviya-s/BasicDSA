#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int unchanged;
int arr[MAX];
int choice,size;
int num,place;
int fav;


void create(int size){
    printf("Enter numbers one by one:");
    for(int i=0;i<size;++i){
        scanf("%d",&arr[i]);
    }
    printf("Successfully inserted!!\n");
}

void insert(int num,int fav){
    if(size<unchanged){
        for(int i=MAX-1;i>=fav;i--){
        arr[i+1]=arr[i];
    }
    arr[fav]=num;
    printf("It is inserted successfully!");
    size++;
    }else{
        printf("The list is full!\n");
    }
}

void display(void){
    for (int i=0;i<=size-1;i++){
      printf("%d\n",arr[i]);
    }
}

void search(int arr[],int num){
    for(int i=0;i<=size-1;i++){
        if(arr[i]==num){
        printf("The number %d is in position %d\n",num,i+1);  
        }
    }  
}

void delete(int place){
    if(place<=size-1){
        for(int i=place;i<=size-1;i++){
        arr[i]=arr[i+1];
    }
    size--;
    printf("Deleted!\n");
    }else{
        printf("Invalid position\n");
    }
    
}

int main(){
    
    do{
        printf("Enter your choice:");
        printf("\n1)CREATE\n2)INSERT\n3)DISPLAY\n4)SEARCH\n5)DELETE\n6)EXIT\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
             printf("Enter the size of the array:"); 
             scanf("%d",&size);
             unchanged=size;
             create(size);
             break;
            case 2 :
             printf("Enter the number you want to insert:\n");
             scanf("%d",&num);
             printf("Enter the position u want to insert(in index):");
             scanf("%d",&fav);
             insert(num,fav);
             break;
            case 3:
             display();
             break;
            case 4:
             printf("\nEnter the number to be searched:");
             scanf("%d",&num);
             search(arr,num);
             break;
            case 5:
             printf("Enter the index you want to delete:\n");
             scanf("%d",&place);
             delete(place);
             break;
             case 6:
             exit(0);
             break;
            default:
             printf("It is an invalid input");
        }
    }while(choice!=6);
    return 0;
}