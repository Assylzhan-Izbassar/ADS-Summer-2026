#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(int start, vector<vector<int>> adj) {
    int V = adj.size();

    vector<bool> visited(V, false);
    queue<int> q;

    vector<int> result;

    vector<int> dist(V, 0);

    visited[start] = true;
    q.push(start);
    result.push_back(start);


    while (!q.empty()) {
        int u = q.front();
        q.pop();
    
        for (int i=0; i < adj[u].size(); ++i) {
            int v = adj[u][i];
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
                result.push_back(v);
                dist[v] = dist[u] + 1;
            }
        }
    }
    return dist;
}

int main() {
    vector<vector<int>> adj = {
        {1, 2},
        {0, 2, 3},
        {0, 1, 4},
        {1, 4},
        {2, 3},
    };

    vector<int> result = bfs(4, adj);

    for (int x: result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}