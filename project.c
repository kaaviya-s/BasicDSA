
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define NUM 1
struct item{
char brand[20];
char id[10];
float in_price;
float out_price;
int storage;
};
struct item_node{
struct item wanted;
int amount;
struct item_node *next;
};

int menu();
void establish();
void display_all();
void shop_cart();
int cart_menu();
void add();
void calculate();
void display();
struct item goods[NUM];
struct item_node *cart;


void main()
{
printf("Welcome tosupermarket managment system\n");
while(1){
switch(menu())
{
case 1:
establish();break;
case 2:
display_all();break;
case 3:
shop_cart();break;
case 4:
calculate();break;
case 5:
printf("Thanks for using, goodbye!\n");
exit(0);
}
}
}
int menu()
{
char str[5];
int n;
printf("\n\n Please select a number to operate\n");
printf("1.Create inventory information\n");
printf("2.Show all products\n");
printf("3,Shopping cart\n");
printf("4.Settlement\n");
printf("5.Exit\n");
printf("Please select the corresponding number 1-5:");
while(1){
gets(str);
n=atoi(str);
if(n<1||n>5)
printf("Input errors,Please re-enter:");
else
break;
}
return n;
}

void establish(){
FILE *fp;
int i;
printf("Please enter the cargo information\n");
for(i=0;i<NUM;i++){
printf("Name of the goods:");
fflush(stdin);
gets(goods[i].brand);
printf("Item No.:");
fflush(stdin);
gets(goods[i].id);
printf("Purchase Price:");
fflush(stdin);
scanf("%f",&goods[i].in_price);
printf("Whistle Price:");
fflush(stdin);
scanf("%f",&goods[i].out_price);
printf("Quantity:");
fflush(stdin);
scanf("%d",&goods[i].storage);
printf("\n");
}
if((fp=fopen("goods.txt","a"))==NULL){
printf("Failed to Create file.\n");
return;
}
fwrite(goods,sizeof(struct item),NUM,fp);
fclose(fp);
}

void display_all()
{
int i;
FILE *fp;
fp= fopen("goods.txt","r");
for(i=0;(fread(goods+i,sizeof(struct item),1,fp))!=0;i++)
{
printf("Goods  of the goods  The unit price   inventory \n");
printf("%5s%5s%7.2f%8d\n",goods[i].id,goods[i].brand,goods[i].out_price,goods[i].storage);
}
fclose(fp);
}

void shop_cart(){
while(1)
switch(cart_menu()){
case 1:display();break;
case 2:add();break;
case 3:return;
}
}

int cart_menu(){
char str[5];
int n;
printf("\n Please Choose an action\n\n");
printf("1.Display the current shopping list\n");
printf("2.Add proudcts\n");
printf("3.Exit\n\n");
printf("Please select the corresponding number 1-3:\n");
while(1){
gets(str);
n=atoi(str);
if(n<1||n>3)
printf("Input error,Please re-enter :\n");
else
break;
}
return n;
}

void display(){
struct item_node *p=cart;
if(p==NULL){
printf("Item No. Item Name Unit price Quantity\n");
printf("%10s %20s %7.2f %8d\n",p->wanted.id,p->wanted.brand,p->wanted.out_price,p->amount);
p=p->next;
}
}

void add(){
FILE *fp;
int i,w;
char str[20];
char choice1,choice2;
struct item_node *p,*p1;
do{
printf("Enter the name or item number of the requried item:\n");
gets(str);
if((fp=fopen("goods.txt","r"))==NULL){
printf("Failed to open file\n");
continue;
}

for(i=0;fread(goods+i,sizeof(struct item),1,fp)!=0;i++){
if((strcmp(goods[i].brand,str)==0 || strcmp(goods[i].id,str)==0)&&goods[i].storage!=0){
printf("The required item has been found:\n\n");
printf("Item No. Item Name Unit price Inventory Quantity\n");
printf("%10s %20s %7.2f %8d\n",goods[i].id,goods[i].brand,goods[i].out_price,goods[i].storage);
printf("please Enter the required Quantity :");
scanf("%d",&w);
if(w>goods[i].storage){
printf("Insufficient inventory\n");
break;
}

printf("\n Do you want to buy? (Y/N)");
choice1=getchar();
if(choice1=='Y' || choice1=='y'){
p1=(struct item_node*)malloc(sizeof(struct item_node));
if(p1==NULL){
printf("Memory request failed!\n");
exit(1);
}

p1->amount=w;
p1->wanted=goods[i];
p1->next=NULL;
p=cart;
if(cart==NULL)
cart=p1;
else{
while(p->next!=NULL)
p=p->next;
p1->next=p->next;
p->next=p1;
}
}
break;
}
}
if(i==NULL)
printf("The required item was not found\n");
fclose(fp);
printf("Do you want to continue shopping? (Y/N)");
choice2=getchar();
}while(choice2=='Y' || choice2=='y');
}



void calculate(){
float total =0,pay;
struct item_node *p;
int i;
FILE *fp;
printf("The following is a shopping list:\n");
display();
if((fp=fopen("goods.txt","r"))==NULL){
printf("Failed to open file.\n");
return;
}
for(i=0;(fread(goods+i,sizeof(struct item),1,fp))!=0;i++);
fclose(fp);

p=cart;
while(p!=NULL){
total+=p->wanted .out_price*p->amount;
for(i=0;strcmp(goods[i].id,p->wanted.id)!=0;i++)
goods[i].storage-=p->amount;
p=p->next;
}
printf("Total %7.2f",total);
printf("\nEnter the actual amonut paid:");
scanf("%f",&pay);
printf("payment: %7.2f change: %7.2f",pay,pay-total);
if((fp=fopen("goods.txt","w"))==NULL){
printf("Failed to open file.\n");
return;
}
fwrite(goods,sizeof(struct item),NUM,fp);
fclose(fp);
}
