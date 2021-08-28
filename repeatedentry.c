#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct contact{
    char name[40];
    char number[10];
    int occur;
    int check;
};
int main(){
    char read[100];
    int length = 7, i = 0, count = 0;
    FILE *f;
    f = fopen("numbrs.csv", "r");  

    // while (fgets(read, 100, f))
    //     length +=1;

    struct contact c[length];
    while (fgets(read, 100, f))
    {
        int column = 0;
        char *token;
        token = strtok(read, ",");
        while (token != NULL)
        {
            if (column == 0)
                strcpy(c[i].name, token);
            else if (column == 1){               
                strcpy(c[i].number, token);
                c[i].check = 0;
            }
            token = strtok(NULL, ",");
            column++;
        }
        i += 1;
    }
    for (int i = 0; i < length; i++){
        for (int j = 0; j < length; j++){
            if (!(strcmp(c[i].name, c[j].name)) && (i != j)&& c[j].check != 1 ){
                c[j].check = 1;
                c[i].check = 0;
                count += 1;
            }
        }
        c[i].occur = count;
        count = 0;
    }
    printf("\nRepeated entries \n");
    for (int i = 0; i < length; i++){
        if (c[i].occur > 0 && c[i].check == 0)     
            printf("\nname : %s\tnumber : %s", c[i].name, c[i].number);       
    }

}