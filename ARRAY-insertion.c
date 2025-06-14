#include <stdio.h>
#include <stdlib.h>

// Traversal of array
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
    printf("\n");
}

// Insertion in an Array
int indInsertion(int arr[], int size, int element, int capacity, int index)
{
    if (size >= capacity)
    {
        return -1; // Cannot insert
    }
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i]; // Shift elements right
    }
    arr[index] = element;
    return 1; // Success
}

int main()
{
    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5, element = 45, index = 3;

    printf("Original array:\n");
    display(arr, size);

    if (indInsertion(arr, size, element, 100, index) == 1)
    {
        size += 1;
        printf("Array after insertion:\n");
        display(arr, size);
    }
    else
    {
        printf("Insertion failed: Array is full.\n");
    }

    return 0;
}
