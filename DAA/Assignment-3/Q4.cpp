#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <utility> // for pair
using namespace std;

class Graph {
public:
    int V; // Number of vertices
    vector<vector<pair<int, int>>> adj; // Adjacency list to store (neighbor, weight)

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight}); // For undirected graph
    }

    // Function to implement Prim's Algorithm
    void primMST() {
        vector<int> key(V, INT_MAX); // Initialize all keys as infinity
        vector<int> parent(V, -1);   // To store the MST
        vector<bool> inMST(V, false); // To track vertices included in MST

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap priority queue

        key[0] = 0; // Start from vertex 0
        pq.push({0, 0}); // {weight, vertex}

        while (!pq.empty()) {
            int u = pq.top().second; // Extract the vertex with the smallest key
            pq.pop();

            // If vertex is already included in MST, skip it
            if (inMST[u]) continue;

            // Include vertex u in MST
            inMST[u] = true;

            // Update the key and parent for the adjacent vertices
            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                // If v is not in MST and the edge weight is smaller than the current key of v
                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    pq.push({key[v], v});
                    parent[v] = u;
                }
            }
        }

        // Print the MST edges
        cout << "Minimum Spanning Tree (MST) edges:\n";
        int totalWeight = 0;
        for (int i = 1; i < V; i++) {
            cout << parent[i] << " - " << i << " : " << key[i] << endl;
            totalWeight += key[i];
        }
        cout << "Total weight of MST: " << totalWeight << endl;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    Graph g(V);

    cout << "Enter the edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        g.addEdge(u, v, weight);
    }

    g.primMST();

    return 0;
}
