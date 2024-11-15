#include <iostream>
using namespace std;

// Function to perform Linear Search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Return the index where the element is found
        }
    }
    return -1;  // Return -1 if the element is not found
}

int main() {
    // Example array
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);  // Calculate the size of the array
    int target;

    // Asking user for input
    cout << "Enter the element to search for: ";
    cin >> target;

    // Perform linear search
    int result = linearSearch(arr, size, target);

    // Output result
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
