#include <iostream>
#include <vector>

using namespace std;

struct Edge {
    int u, v;

    Edge(int u, int v) {
        this->u = u;
        this->v = v;
    }
};

int main() {
    int V = 5;
    int E = 6;
    // Matrix rep:
    vector<vector<bool>> g(V, vector<bool>(V, 0));

    // Adj rep:
    vector<vector<int>> adj(V);

    // Edge rep:
    vector<Edge> edges;

    int u, v;
    for (int i=0; i < E; ++i) {
        cin >> u >> v;

        // Matrix rep:
        g[u][v] = 1;
        g[v][u] = 1;

        // Adj rep:
        adj[u].push_back(v);
        adj[v].push_back(u);

        // Edge rep:
        edges.push_back(Edge(u, v));
    }

    // Matrix rep:
    for (int i=0; i < V; ++i) {
        for (int j=0; j < V; ++j) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }

    // Adj rep:
    for (int i=0; i < V; ++i) {
        cout << i << ": ";
        for (int j=0; j < adj[i].size(); ++j) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    // Edge rep:
    for (int i=0; i < edges.size(); ++i) {
        cout << edges[i].u << ", " << edges[i].v << endl;
    }

    return 0;
}