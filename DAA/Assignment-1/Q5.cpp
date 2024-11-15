#include <iostream>
using namespace std;

// Function to merge two halves of an array
void merge(int arr[], int left, int right) {
    if (left >= right) return;
    
    // Find the middle of the array
    int mid = left + (right - left) / 2;

    // Recursively sort the first and second halves
    merge(arr, left, mid);
    merge(arr, mid + 1, right);

    // Create temporary arrays to hold the left and right subarrays
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* leftArr = new int[n1];
    int* rightArr = new int[n2];

    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];

    for (int i = 0; i < n2; ++i)
        rightArr[i] = arr[mid + 1 + i];

    // Merge the temporary arrays back into the original array
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            ++i;
        } else {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

    // Copy any remaining elements of leftArr[] if any
    while (i < n1) {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }

    // Copy any remaining elements of rightArr[] if any
    while (j < n2) {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }

    // Clean up dynamic memory
    delete[] leftArr;
    delete[] rightArr;
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    // Example array to be sorted
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, arrSize);

    // Perform Merge Sort
    merge(arr, 0, arrSize - 1);

    cout << "Sorted array: ";
    printArray(arr, arrSize);

    return 0;
}
