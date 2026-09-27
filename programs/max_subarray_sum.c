/*
You are given an integer array arr[]. You need to find the maximum sum of a subarray (containing at least one element) in the array arr[].

Examples:

Input: arr[] = [2, 3, -8, 7, -1, 2, 3]
Output: 11
Explanation: The subarray [7, -1, 2, 3] has the largest sum 11.
Input: arr[] = [-2, -4]
Output: -2
Explanation: The subarray [-2] has the largest sum -2.
Input: arr[] = [5, 4, 1, 7, 8]
Output: 25
Explanation: The subarray [5, 4, 1, 7, 8] has the largest sum 25.
Constraints:
1 ≤ arr.size() ≤ 105
-104 ≤ arr[i] ≤ 104
*/

#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum sum of a subarray
int maxSubarraySum(int arr[], int n)
{
    int currentSum = arr[0];
    int maxSum = arr[0];


    for (int i = 1; i < n; i++)
    {
        if(currentSum + arr[i] > arr[i]){
            currentSum = currentSum + arr[i];
        }
        else{
            currentSum = arr[i];
        }
        
        if(currentSum > maxSum){
            
            maxSum = currentSum;
        }
    }

    return maxSum;
}

int main()
{
    int n;
    int *arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid input.\n");
        return 1;
    }

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

    // Find and display the maximum subarray sum
    printf("Maximum subarray sum: %d\n",
           maxSubarraySum(arr, n));

    free(arr);

    return 0;
}
