#include <iostream>
#include <vector>
using namespace std;

// A function to do counting sort based on the digit represented by exp
void countingSortForRadix(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};
    
    // Step 1: Count occurrences of digits
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    
    // Step 2: Modify the count array to store the actual positions
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    
    // Step 3: Build the output array using the count array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    
    // Step 4: Copy the sorted output to arr[]
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Function to perform Radix Sort
void radixSort(int arr[], int n) {
    // Find the maximum number to determine the number of digits
    int maxVal = *max_element(arr, arr + n);
    
    // Perform counting sort for every digit
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSortForRadix(arr, n, exp);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0;
