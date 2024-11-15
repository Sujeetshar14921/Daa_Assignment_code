#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<int> dp(W + 1, 0);
    
    for (int i = 0; i < n; i++) {
        for (int w = W; w >= wt[i]; w--) {
            dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
        }
    }
    
    return dp[W];
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    
    vector<int> wt(n), val(n);
    cout << "Enter weight and value of each item: \n";
    for (int i = 0; i < n; i++) {
        cin >> wt[i] >> val[i];
    }
    
    cout << "Enter capacity of the knapsack: ";
    cin >> W;
    
    int result = knapsack(W, wt, val, n);
    cout << "Maximum value in Integer Knapsack = " << result << endl;
    
    return 0;
}
