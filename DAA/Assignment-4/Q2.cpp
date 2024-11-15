#include <iostream>
#include <vector>
using namespace std;

class HamiltonianCircuit {
public:
    int V;  // Number of vertices
    vector<vector<int>> graph;

    HamiltonianCircuit(int V) : V(V), graph(V, vector<int>(V, 0)) {}

    bool isSafe(int v, vector<int>& path, int pos) {
        if (graph[path[pos - 1]][v] == 0) // Check if there is an edge
            return false;

        for (int i = 0; i < pos; i++) {
            if (path[i] == v)  // Check if vertex is already in the path
                return false;
        }

        return true;
    }

    bool solveHamiltonianUtil(vector<int>& path, int pos) {
        if (pos == V) {
            // Check if there is an edge from last to first vertex to complete the cycle
            if (graph[path[pos - 1]][path[0]] == 1)
                return true;
            return false;
        }

        for (int v = 1; v < V; v++) {
            if (isSafe(v, path, pos)) {
                path[pos] = v;
                if (solveHamiltonianUtil(path, pos + 1)) {
                    return true;
                }
                path[pos] = -1;  // Backtrack
            }
        }

        return false;
    }

    void solve() {
        vector<int> path(V, -1);
        path[0] = 0; // Start at vertex 0

        if (solveHamiltonianUtil(path, 1)) {
            cout << "Hamiltonian Circuit: ";
            for (int i = 0; i < V; i++) {
                cout << path[i] << " ";
            }
            cout << path[0] << endl;  // Complete the cycle
        } else {
            cout << "No Hamiltonian Circuit found." << endl;
        }
    }

    void addEdge(int u, int v) {
        graph[u][v] = 1;
        graph[v][u] = 1; // Undirected graph
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    HamiltonianCircuit hc(V);

    cout << "Enter number of edges: ";
    cin >> E;
    cout << "Enter edges (u v): \n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        hc.addEdge(u, v);
    }

    hc.solve();
    return 0;
}
