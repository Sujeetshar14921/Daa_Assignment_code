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

    // Dijkstra's Algorithm to find the shortest path from the source
    void dijkstra(int source) {
        vector<int> dist(V, INT_MAX); // Distance from source to each vertex
        vector<bool> visited(V, false); // Track visited vertices
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap to select the vertex with the smallest distance

        // Initialize the source node with distance 0
        dist[source] = 0;
        pq.push({0, source}); // {distance, vertex}

        while (!pq.empty()) {
            int u = pq.top().second; // Get the vertex with the minimum distance
            pq.pop();

            // If the vertex is already visited, skip it
            if (visited[u]) continue;

            // Mark the vertex as visited
            visited[u] = true;

            // Update the distances of the neighboring vertices
            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                // If the new distance is shorter, update it and push it into the priority queue
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        // Print the shortest distance from source to all vertices
        cout << "Vertex\tDistance from Source (" << source << ")\n";
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) {
                cout << i << "\t" << "INF" << endl;
            } else {
                cout << i << "\t" << dist[i] << endl;
            }
        }
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    Graph g(V);

    cout << "Enter the edges (u v weight): \n";
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        g.addEdge(u, v, weight);
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    g.dijkstra(source);

    return 0;
}
