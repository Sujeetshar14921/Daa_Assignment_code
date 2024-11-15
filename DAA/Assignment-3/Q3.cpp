#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, rank;
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);  // Path compression
        return parent[u];
    }

    void unionSets(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        if (root_u != root_v) {
            // Union by rank
            if (rank[root_u] > rank[root_v])
                parent[root_v] = root_u;
            else if (rank[root_u] < rank[root_v])
                parent[root_u] = root_v;
            else {
                parent[root_v] = root_u;
                rank[root_u]++;
            }
        }
    }
};

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) {
        return weight < other.weight;
    }
};

class Graph {
public:
    int V, E;
    vector<Edge> edges;
    
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }

    void addEdge(int u, int v, int weight) {
        edges.push_back({u, v, weight});
    }

    void kruskalMST() {
        sort(edges.begin(), edges.end());

        DisjointSet ds(V);
        vector<Edge> mst;

        for (auto& edge : edges) {
            int u = edge.u;
            int v = edge.v;

            if (ds.find(u) != ds.find(v)) {
                ds.unionSets(u, v);
                mst.push_back(edge);
            }
        }

        cout << "Minimum Spanning Tree edges:\n";
        int totalWeight = 0;
        for (auto& edge : mst) {
            cout << edge.u << " - " << edge.v << " : " << edge.weight << endl;
            totalWeight += edge.weight;
        }
        cout << "Total weight of MST: " << totalWeight << endl;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    Graph g(V, E);

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        g.addEdge(u, v, weight);
    }

    g.kruskalMST();
    
    return 0;
}
