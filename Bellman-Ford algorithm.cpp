#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Function to perform Bellman-Ford algorithm
void bellmanFord(vector<Edge>& edges, int V, int E, int start) {
    vector<int> distance(V, INT_MAX);
    distance[start] = 0;

    // Relaxation step
    for (int i = 0; i < V - 1; ++i) {
        for (int j = 0; j < E; ++j) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;
            if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    // Check for negative-weight cycles
    for (int i = 0; i < E; ++i) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int w = edges[i].weight;
        if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
            cout << "Negative-weight cycle found!" << endl;
            return;
        }
    }

    // Print the distances
    for (int i = 0; i < V; ++i) {
        if (distance[i] == INT_MAX) {
            cout << "INF ";
        } else {
            cout << distance[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int V, E;
    cin >> V >> E; // Number of vertices and edges

    vector<Edge> edges(E);

    for (int i = 0; i < E; ++i) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight; // Edge (src, dest) with weight
    }

    int start;
    cin >> start; // Starting vertex

    bellmanFord(edges, V, E, start);

    return 0;
}
