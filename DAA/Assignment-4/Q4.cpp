#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class TSP {
public:
    int n;
    vector<vector<int>> dist;
    vector<int> bestPath;
    int minCost = INT_MAX;

    TSP(int n, vector<vector<int>>& d) : n(n), dist(d) {}

    void findTSP(int city, vector<bool>& visited, vector<int>& path, int cost, int count) {
        if (count == n) {
            if (dist[city][0] != 0) {  // Return to the starting city
                cost += dist[city][0];
                if (cost < minCost) {
                    minCost = cost;
                    bestPath = path;
                    bestPath.push_back(0);  // Complete the cycle
                }
            }
            return;
        }

        for (int nextCity = 0; nextCity < n; nextCity++) {
            if (!visited[nextCity] && dist[city][nextCity] != 0) {
                visited[nextCity] = true;
                path.push_back(nextCity);
                findTSP(nextCity, visited, path, cost + dist[city][nextCity], count + 1);
                visited[nextCity] = false;
                path.pop_back();
            }
        }
    }

    void solve() {
        vector<bool> visited(n, false);
        vector<int> path;
        visited[0] = true;
        path.push_back(0);
        findTSP(0, visited, path, 0, 1);

        cout << "TSP Path: ";
        for (int city : bestPath) {
            cout << city << " ";
        }
        cout << endl;
        cout << "Minimum Cost: " << minCost << endl;
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

    TSP tsp(n, dist);
    tsp.solve();

    return 0;
}
