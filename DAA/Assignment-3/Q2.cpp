#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    int V;  // Number of vertices
    vector<vector<int>> adj;  // Adjacency list

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void DFS(int start, vector<bool>& visited) {
        visited[start] = true;
        cout << start << " ";

        for (int neighbor : adj[start]) {
            if (!visited[neighbor]) {
                DFS(neighbor, visited);
            }
        }
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    Graph g(V);

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter the edges (u v): \n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int start;
    cout << "Enter the starting vertex: ";
    cin >> start;

    vector<bool> visited(V, false);
    cout << "DFS traversal starting from vertex " << start << ": ";
    g.DFS(start, visited);

    return 0;
}
