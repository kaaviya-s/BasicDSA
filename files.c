#include<stdio.h>

void main(){
    char str[200];
    char text[200];
    FILE *fp;
    fp=fopen("testing.txt","a");
    printf("Enter something:  \n");
    gets(str);
    fprintf(fp,str);
    fclose(fp);
    fp=fopen("testing.txt","r");
    fgets(text,60,fp);
    printf("%s",text);
    fclose(fp);
}