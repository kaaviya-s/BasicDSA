#include <stdio.h>
#include <math.h>

int main()
{
    int ex, x;
    float sum = 0;
    int arr[20];
    printf("Enter the value of exponential term(power):");
    scanf("%d", &ex);

    printf("Enter the value of 'x':");
    scanf("%d", &x);

    for (int i = ex; i >= 0; i--)
    {
        printf("Enter co-efficient of X^%d: ", i);
        scanf("%d", &arr[i]);
    }

    for (int i = ex; i >= 0; i--)
    {

        printf("%d*(%d^%d)+", arr[i], x, i);
        sum = sum + (arr[i] * pow(x, i));
    }
    printf("\n%f\n", sum);

    return 0;
}