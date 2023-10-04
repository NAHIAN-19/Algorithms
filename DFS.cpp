#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, vector<int>> graph;

void dfs(int vertex, unordered_map<int, bool>& visited) {
    visited[vertex] = true;

    for (int neighbor : graph[vertex]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited);
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
        graph[v].push_back(u);  // For an undirected
    }

    unordered_map<int, bool> visited;
    for (auto node : graph) {
        visited[node.first] = false;
    }

    int startNode;
    cin >> startNode; // Starting node for DFS

    dfs(startNode, visited);

    return 0;
}  
