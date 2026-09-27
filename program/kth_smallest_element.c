/*
Given an integer array arr[] and an integer k, find and return the kth smallest element in the given array.
Note: The kth smallest element is determined based on the sorted order of the array.

Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105
1 ≤ k ≤  arr.size() 
*/

#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers for qsort
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);

}

// Function to find the kth smallest element
int kthSmallest(int arr[], int n, int k)
{
    // Sort the array
    qsort(arr, n, sizeof(int), compare);


    // Return the kth smallest element
    return arr[k - 1];

}

int main()
{
    int n, k;
    int *arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid input.\n");
        return 1;
    }

    // Dynamically allocate memory for the array
    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr + i);

    }

    printf("Enter the value of k: ");
    scanf("%d", &k);

    if (k < 1 || k > n)
    {
        printf("Invalid value of k.\n");
        free(arr);
        return 1;
    }

    // Find and display the kth smallest element
    printf("The %dth smallest element is: %d\n",
           k, kthSmallest(arr, n, k));

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
