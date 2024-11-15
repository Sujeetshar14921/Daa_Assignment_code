#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to represent an item
struct Item {
    int weight;
    int value;
    double ratio;  // value-to-weight ratio
};

// Comparison function to sort items based on value/weight ratio
bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

double fractionalKnapsack(int W, vector<Item>& items) {
    // Sort items by ratio
    for (auto& item : items) {
        item.ratio = (double)item.value / item.weight;
    }
    sort(items.begin(), items.end(), compare);
    
    double totalValue = 0.0;
    
    // Take items based on sorted ratio
    for (auto& item : items) {
        if (W >= item.weight) {
            // Take the whole item
            W -= item.weight;
            totalValue += item.value;
        } else {
            // Take the fractional part of the item
            totalValue += item.value * ((double)W / item.weight);
            break;
        }
    }
    
    return totalValue;
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    
    vector<Item> items(n);
    cout << "Enter weight and value of each item: \n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].value;
    }
    
    cout << "Enter capacity of the knapsack: ";
    cin >> W;
    
    double result = fractionalKnapsack(W, items);
    cout << "Maximum value in Fractional Knapsack = " << result << endl;
    
    return 0;
}
