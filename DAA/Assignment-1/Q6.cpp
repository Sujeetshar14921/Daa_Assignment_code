#include <iostream>
using namespace std;

// Function to partition the array into two halves
int partition(int arr[], int low, int high) {
    // Choose the pivot element (here we choose the last element)
    int pivot = arr[high];
    int i = low - 1;  // Index of smaller element

    // Traverse through the array and rearrange elements based on the pivot
    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;  // Increment index of smaller element
            swap(arr[i], arr[j]);  // Swap elements
        }
    }
    // Swap the pivot element with the element at i+1
    swap(arr[i + 1], arr[high]);

    // Return the partitioning index
    return i + 1;
}

// Function to implement the Quick Sort algorithm
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Get the partition index
        int pi = partition(arr, low, high);

        // Recursively sort the elements before and after partition
        quickSort(arr, low, pi - 1);  // Left side of the pivot
        quickSort(arr, pi + 1, high);  // Right side of the pivot
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
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
