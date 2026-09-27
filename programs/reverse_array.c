/*
Reverse an Array Using Functions and Pointers

Write a C program to reverse the elements of an integer array using functions.

The program should:

1.Define a function swap() to swap two integers using pointers.
2.Define a function reverseArray() to reverse the elements of an array.
3.Use the swap() function inside reverseArray().
4.Pass the array and its size to reverseArray().
5.Display the elements of the array after reversing.
*/

#include <stdio.h>

// Function prototypes
void swap(int *a, int *b);
void reverseArray(int arr[], int n);

// Function to swap two numbers
void swap(int *a, int *b)
{
    int temp = 0;
    
    temp = *a;
    *a = *b;
    *b = temp;

}

// Function to reverse an array
void reverseArray(int arr[], int n)
{
    int *start = &arr[0];
    int *end = &arr[n - 1];
    int t = 0;
    
    // Continue until left crosses right
    while (start < end)
    {
        swap(start, end);
        
        t = *start;
        *start = *end;
        *end = t;

        start++;
        end--;

    }
}

int main()
{
    int arr[] = {1, 4, 3, 2, 6, 5};

    int n = sizeof(arr) / sizeof(arr[0]);

    reverseArray(arr, n);


    // Display the reversed array
    for (int i = 0; i < n; i++)
    {
        
        printf("%d ", arr[i]);

    }

    return 0;
}
