#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void create(int);
void display(int, int);

struct node
{
    int coeff;
    struct node *next;
};
struct node *head = NULL;

void main()
{
    int order, x, co;
    printf("Enter the order of the polynomial: ");
    scanf("%d", &order);
    printf("Enter the value of 'x': ");
    scanf("%d", &x);

    for (int i = order; i >= 0; i--)
    {
        printf("Enter coefficient for term X^%d: ", order);
        scanf("%d", &co);
        create(co);
    }

    display(order, x);
}

void create(int co)
{

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    temp->coeff = co;
    
    if (head == NULL)
    {
        temp->next = NULL;
        head = temp;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        temp->next = NULL;
        ptr->next = temp;
    }
}

void display(int order, int x)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    float sum = 0;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d*x^%d", ptr->coeff, order);
        if (ptr->next == NULL)
        {
            printf("\n");
        }
        else
        {
            printf("+");
        }
        sum += (float)(ptr->coeff) * pow(x, order);
        ptr = ptr->next;
        order--;
    }
    printf("Evaluated answer: %f", sum);
}