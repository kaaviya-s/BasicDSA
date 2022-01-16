#include <stdio.h>
#include <math.h>

float stack[100];
int top = -1;

void push(float co, int ex)
{
    stack[++top] = co;
    stack[++top] = ex;
}

int pop()
{
    int a = stack[top--];
    return a;
}

int main()
{
    int x, size, expo;
    float coeff;
    float sum = 0;
    printf("\t\tPolynomial Addition Using Stack\t\t\n");
    printf("Enter the value for 'x': ");
    scanf("%d", &x);
    printf("Enter no.of terms: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        printf("Enter the coefficient of term %d: ", i + 1);
        scanf("%f", &coeff);
        printf("Enter the exponent for term %d: ", i + 1);
        scanf("%d", &expo);
        push(coeff, expo);
    }

    for (int i = 0; i < size; i++)
    {
        int ex = pop();
        float co = pop();
        sum += co * pow(x, ex);
        printf("(%.1f x^%d)", co, ex);
        if (i == size - 1)
        {
            printf("\n");
        }
        else
        {
            printf("+");
        }
    }
    printf("Evaluated answer: %f", sum);
    return 0;
}