#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class TSP_DP {
public:
    int n;
    vector<vector<int>> dist;

    TSP_DP(int n, vector<vector<int>>& d) : n(n), dist(d) {}

    int tsp() {
        vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX));
        dp[1][0] = 0;  // Starting from city 0

        for (int mask = 1; mask < (1 << n); mask++) {
            for (int u = 0; u < n; u++) {
                if (mask & (1 << u)) {
                    for (int v = 0; v < n; v++) {
                        if (mask & (1 << v)) continue;
                        dp[mask | (1 << v)][v] = min(dp[mask | (1 << v)][v], dp[mask][u] + dist[u][v]);
                    }
                }
            }
        }

        int minCost = INT_MAX;
        for (int i = 1; i < n; i++) {
            minCost = min(minCost, dp[(1 << n) - 1][i] + dist[i][0]);
        }
        return minCost;
    }
};

int main() {
    int n = 4;
    vector<vector<int>> dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    TSP_DP tsp(n, dist);
    cout << "Minimum Cost using Dynamic Programming: " << tsp.tsp() << endl;

    return 0;
}
