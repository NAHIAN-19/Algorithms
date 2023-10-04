#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;

void floydWarshall(vector<vector<int>>& graph, int V) {
    vector<vector<int>> dist(V, vector<int>(V, INF));

    // Initialize the distance matrix with the given graph
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> dist[i][j];
            if (i == j) {
                dist[i][j] = 0; // Distance to itself is always 0
            }
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the resulting shortest distances
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int V;
    cin >> V; // Number of vertices

    vector<vector<int>> graph(V, vector<int>(V));

    floydWarshall(graph, V);

    return 0;
}
