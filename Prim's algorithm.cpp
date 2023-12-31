#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int findMinKey(vector<int>& key, vector<bool>& mstSet) {
    int minKey = INF, minIndex = -1;
    for (int v = 0; v < key.size(); ++v) {
        if (!mstSet[v] && key[v] < minKey) {
            minKey = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void primMST(vector<vector<int>>& graph, int V) {
    vector<int> parent(V, -1);
    vector<int> key(V, INF);
    vector<bool> mstSet(V, false);

    key[0] = 0;

    for (int count = 0; count < V - 1; ++count) {
        int u = findMinKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the edges of the Minimum Spanning Tree (MST)
    for (int i = 1; i < V; ++i) {
        cout << parent[i] << " - " << i << " Weight: " << graph[i][parent[i]] << endl;
    }
}

int main() {
    int V;
    cin >> V; // Number of vertices

    vector<vector<int>> graph(V, vector<int>(V));

    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> graph[i][j];
        }
    }

    primMST(graph, V);

    return 0;
}
