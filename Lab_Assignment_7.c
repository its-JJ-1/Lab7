#include <stdio.h>

//Lab Assignment 7
//Name: Jonathan Guzman
//Date: 3/7/2024

// Function to perform Bubble Sort and count swaps
int bubbleSort(int arr[], int n, int swaps[]) 
{
    int i, j, temp, totalSwaps = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps[arr[j + 1]]++;
                swaps[arr[j]]++; // Increment for the previous value to track swaps correctly
                totalSwaps++;
            }
        }
    }
    return totalSwaps;
}

// Function to perform Selection Sort and count swaps
int selectionSort(int arr[], int n, int swaps[])
 {
    int i, j, min_index, temp, totalSwaps = 0;
    for (i = 0; i < n - 1; i++) 
    {
        min_index = i;
        for (j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i) 
        {
            // Swap arr[i] and arr[min_index]
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
            swaps[arr[i]]++;
            swaps[arr[min_index]]++; // Increment for the swapped value to track swaps correctly
            totalSwaps++;
        }
    }
    return totalSwaps;
}

int main() 
{
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);

    int bubbleSwaps1[100] = {0}; 
    int bubbleSwaps2[100] = {0}; 
    int selectionSwaps1[100] = {0}; 
    int selectionSwaps2[100] = {0}; 

    // Bubble Sort on array1
    int bubbleTotalSwaps1 = bubbleSort(array1, size1, bubbleSwaps1);

    // Bubble Sort on array2
    int bubbleTotalSwaps2 = bubbleSort(array2, size2, bubbleSwaps2);

    // Reset arrays to original unsorted state
    int array1_original[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2_original[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    // Selection Sort on array1
    int selectionTotalSwaps1 = selectionSort(array1_original, size1, selectionSwaps1);

    // Selection Sort on array2
    int selectionTotalSwaps2 = selectionSort(array2_original, size2, selectionSwaps2);

    // Output for Bubble Sort on array1
    printf("array1 bubble sort:\n");
    for (int i = 0; i < size1; i++) 
    {
        printf("%d: %d\n", array1[i], bubbleSwaps1[array1[i]]);
    }
    printf("Total number of swaps: %d\n\n", bubbleTotalSwaps1);

    // Output for Bubble Sort on array2
    printf("array2 bubble sort:\n");
    for (int i = 0; i < size2; i++) 
    {
        printf("%d: %d\n", array2[i], bubbleSwaps2[array2[i]]);
    }
    printf("Total number of swaps: %d\n\n", bubbleTotalSwaps2);

    // Output for Selection Sort on array1
    printf("array1 selection sort:\n");
    for (int i = 0; i < size1; i++)
    {
        printf("%d: %d\n", array1_original[i], selectionSwaps1[array1_original[i]]);
    }
    printf("Total number of swaps: %d\n\n", selectionTotalSwaps1);

    // Output for Selection Sort on array2
    printf("array2 selection sort:\n");
    for (int i = 0; i < size2; i++)
    {
        printf("%d: %d\n", array2_original[i], selectionSwaps2[array2_original[i]]);
    }
    printf("Total number of swaps: %d\n", selectionTotalSwaps2);

    return 0;
}
