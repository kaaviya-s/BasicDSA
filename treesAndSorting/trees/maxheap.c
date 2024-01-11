#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[], int i, int size)
{
    int largest = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;

    if (left < size && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < size && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;

        heapify(arr, largest, size);
    }
}

void display(int arr[], int size)
{
    printf("Elements are:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
}

void main()
{
    int arr[] = {21, 22, 5, 23, 40, 86, 10, 3, 89};

    int size = sizeof(arr) / sizeof(int);

    for (int i = (size / 2) - 1; i >= 0; i--)
    {
        printf("i=%d\n", i);
        heapify(arr, i, size);
    }

    display(arr, size);

    for (int i = size - 1; i >= 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, 0, i);
    }
    display(arr, size);
}
