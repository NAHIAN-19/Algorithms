#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int dest;
    int weight;
};

// Function to perform Dijkstra's algorithm
void dijkstra(vector<vector<Edge>>& graph, int start) {
    int V = graph.size();
    vector<int> distance(V, INT_MAX);
    distance[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const Edge& edge : graph[u]) {
            int v = edge.dest;
            int w = edge.weight;

            if (distance[v] > distance[u] + w) {
                distance[v] = distance[u] + w;
                pq.push({distance[v], v});
            }
        }
    }

    // Print the distances
    for (int i = 0; i < V; ++i) {
        if (i == start)
            continue;

        if (distance[i] == INT_MAX)
            cout << "INF ";
        else
            cout << distance[i] << " ";
    }
    cout << endl;
}

int main() {
    int V, E;
    cin >> V >> E; // Number of vertices and edges

    vector<vector<Edge>> graph(V);

    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w; // Edge (u, v) with weight w
        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); // For undirected graph
    }

    int start;
    cin >> start; // Starting vertex

    dijkstra(graph, start);

    return 0;
}
