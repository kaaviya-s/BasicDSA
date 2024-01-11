#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct contact
{
    char name[40];
    char number[10];
    int occur;
    int check;
    struct contact *next;
};
int main()
{
    char read[100], s1[100], s2[100];
    int length = 0, i = 0, count = 0;
    FILE *f;
    struct contact *head, *curr, *temp, *loop1, *loop2;

    head = (struct contact *)malloc(sizeof(struct contact));

    curr = head;
    f = fopen("100-contacts.csv", "r");
    while (fgets(read, 100, f))
    {
        int column = 0;
        char *token;
        token = strtok(read, ",");
        while (token != NULL)
        {
            if (column == 0)
                strcpy(curr->name, token);
            else if (column == 1)
            {
                strcpy(curr->number, token);
                curr->check = 0;
            }
            token = strtok(NULL, ",");
            column++;
        }
        length++;
        curr->next = (struct contact *)malloc(sizeof(struct contact));
        curr = curr->next;
        curr->next = NULL;
    }
    loop1 = head;
    loop2 = head;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {    
            if (!(strcmp(loop1->name, loop2->name)) && !(i == j) && loop2->check != 1)
            {
                loop2->check = 1;
                loop1->check = 1;
                count += 1;
            }
            loop2 = loop2->next;
        }
        loop2 = head;
        loop1->occur = count;
        loop1 = loop1->next;
        count = 0;
    }
    curr = head;
    printf("\n-------------------------------------------------------------");
    printf("\n\t\tRepeated Entries ");
    printf("\n-------------------------------------------------------------");
    while (1)
    {
        if (curr == NULL) break;
        else if (curr->check == 1 && curr->occur > 0)      
            printf("\nname : %s\t number :%s \trepeated : %d", curr->name, curr->number, curr->occur);
        curr = curr->next;
    }
}