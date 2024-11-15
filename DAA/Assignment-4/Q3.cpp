#include <iostream>
#include <vector>
using namespace std;

class Subset {
public:
    vector<int> set;
    vector<vector<int>> subsets;

    Subset(vector<int> s) : set(s) {}

    void findSubsets(int index, vector<int>& currentSubset) {
        if (index == set.size()) {
            subsets.push_back(currentSubset);  // Add the current subset to the result
            return;
        }

        // Include the current element
        currentSubset.push_back(set[index]);
        findSubsets(index + 1, currentSubset);

        // Exclude the current element (backtrack)
        currentSubset.pop_back();
        findSubsets(index + 1, currentSubset);
    }

    void printSubsets() {
        vector<int> currentSubset;
        findSubsets(0, currentSubset);

        cout << "Subsets:\n";
        for (auto& subset : subsets) {
            for (int num : subset) {
                cout << num << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    vector<int> set = {1, 2, 3};  // Example set
    Subset s(set);
    s.printSubsets();
    return 0;
}
