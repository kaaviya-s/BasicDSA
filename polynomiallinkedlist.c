#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int size;
float x;

struct node
{
    float coeff;
    int expo;
    struct node *link;
};

struct node *result = NULL;

struct node *insert(struct node *head, float co, int ex)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = NULL;

    newnode->coeff = co;
    newnode->expo = ex;
    newnode->link = NULL;
    if (head == NULL || ex > head->expo)
    {

        newnode->link = head;
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp->link != NULL && temp->link->expo > ex)
        {
            temp = temp->link;
        }
        newnode->link = temp->link;
        temp->link = newnode;
    }
    return head;
}

struct node *gettingData(struct node *head)
{

    int ex;
    float co;
    printf("Enter no.of terms: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++)
    {
        printf("Enter coefficient of term %d: ", i + 1);
        scanf("%f", &co);
        printf("Enter exponential for term %d: ", i + 1);
        scanf("%d", &ex);

        head = insert(head, co, ex);
    }
    return head;
}

void toPrint(struct node *head)
{
    struct node *ptr = NULL;
    if (head == NULL)
    {
        printf("There is no expression in the list..!\n");
    }
    else
    {
        ptr = head;
        while (ptr != NULL)
        {
            printf("(%.1f x^%d)", ptr->coeff, ptr->expo);
            ptr = ptr->link;
            if (ptr != NULL)
            {
                printf("+");
            }
            else
            {
                printf("\n");
            }
        }
    }
}

void toEvaluate(struct node *head)
{
    int sum = 0;
    if (head == NULL)
    {
        printf("There is no expression in the list..!\n");
    }
    else
    {
        struct node *temp = head;
        while (temp != NULL)
        {
            sum += (temp->coeff * pow((int)x, temp->expo));
            temp = temp->link;
        }
        printf("Evaluated value of the given polynomial: %d", sum);
    }
}

struct node *polyAdd(struct node *poly1, struct node *poly2)
{
    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->expo == poly2->expo)
        {
            result = insert(result, (poly1->coeff + poly2->coeff), poly1->expo);
            poly1 = poly1->link;
            poly2 = poly2->link;
        }
        else if (poly1->expo > poly2->expo)
        {
            result = insert(result, poly1->coeff, poly1->expo);
            poly1 = poly1->link;
        }
        else if (poly1->expo < poly2->expo)
        {
            result = insert(result, poly2->coeff, poly2->expo);
            poly2 = poly2->link;
        }
    }

    while (poly1 != NULL)
    {
        result = insert(result, poly1->coeff, poly1->expo);
        poly1 = poly1->link;
    }
    while (poly2 != NULL)
    {
        result = insert(result, poly2->coeff, poly2->expo);
        poly2 = poly2->link;
    }
    return result;
}

int main()
{

    struct node *head = NULL;
    struct node *poly1 = NULL;
    struct node *poly2 = NULL;

    printf("Enter the value of  'X': \n");
    scanf("%f", &x);

    printf("Enter 1st polynomial:\n ");
    poly1 = gettingData(head);
    printf("Polynomial 1: ");
    toPrint(poly1);

    printf("Enter 2nd polynomial:\n");
    poly2 = gettingData(head);
    printf("Polynomial 2: ");
    toPrint(poly2);

    result = polyAdd(poly1, poly2);
    printf("Resultant polynomial:\n");
    toPrint(result);
    toEvaluate(result);

    return 0;
}