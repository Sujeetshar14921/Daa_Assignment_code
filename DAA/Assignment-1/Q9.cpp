#include <iostream>
#include <vector>
using namespace std;

// Function to perform Counting Sort
void countingSort(int arr[], int n) {
    int maxVal = *max_element(arr, arr + n);  // Find the maximum element in the array
    int minVal = *min_element(arr, arr + n);  // Find the minimum element in the array
    
    int range = maxVal - minVal + 1;
    vector<int> count(range, 0);
    vector<int> output(n);
    
    // Step 1: Count the occurrences of each element
    for (int i = 0; i < n; i++) {
        count[arr[i] - minVal]++;
    }
    
    // Step 2: Modify the count array by adding previous counts
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }
    
    // Step 3: Place the elements in the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
    }
    
    // Step 4: Copy the sorted elements into the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Original Array: ";
    printArray(arr, n);
    
    countingSort(arr, n);
    
    cout << "Sorted Array: ";
    printArray(arr, n);
    
    return 0;
}
