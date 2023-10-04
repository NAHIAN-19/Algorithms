#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, vector<int>> graph;

void bfs(int start) {
    unordered_map<int, bool> visited;
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();

        for (int neighbor : graph[vertex]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;  // Number of nodes and edges

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);  // For an undirected graph
    }

    int start;
    cin >> start;  // Starting node for BFS

    bfs(start);

    return 0;
}
