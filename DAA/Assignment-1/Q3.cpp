#include <iostream>
using namespace std;

// Function to perform Bubble Sort
void bubbleSort(int arr[], int size) {
    bool swapped;
    
    // Traverse through all elements of the array
    for (int i = 0; i < size - 1; i++) {
        swapped = false; // Reset the swapped flag at the start of each iteration
        
        // Last i elements are already sorted, no need to check them
        for (int j = 0; j < size - i - 1; j++) {
            // Compare adjacent elements and swap them if they are in the wrong order
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                swap(arr[j], arr[j + 1]);
                swapped = true; // Indicate that a swap has occurred
            }
        }
        
        // If no two elements were swapped in the inner loop, then the array is sorted
        if (!swapped) {
            break;
        }
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90}; // Example array
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, size);

    bubbleSort(arr, size);

    cout << "Sorted array: ";
    printArray(arr, size);

    return 0;
}
