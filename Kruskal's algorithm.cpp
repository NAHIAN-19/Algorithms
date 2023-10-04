#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

class Graph {
public:
    int V;
    vector<Edge> edges;

    Graph(int V) : V(V) {}

    void addEdge(int src, int dest, int weight) {
        Edge edge;
        edge.src = src;
        edge.dest = dest;
        edge.weight = weight;
        edges.push_back(edge);
    }

    vector<Edge> kruskalMST() {
        vector<Edge> result;
        sort(edges.begin(), edges.end(), compareEdges);

        vector<int> parent(V);
        for (int i = 0; i < V; ++i) {
            parent[i] = i;
        }

        for (const Edge& edge : edges) {
            int srcParent = findParent(parent, edge.src);
            int destParent = findParent(parent, edge.dest);

            if (srcParent != destParent) {
                result.push_back(edge);
                parent[srcParent] = destParent;
            }
        }

        return result;
    }

    int findParent(vector<int>& parent, int node) {
        if (parent[node] == node) {
            return node;
        }
        return findParent(parent, parent[node]);
    }
};

int main() {
    int V, E;
    cin >> V >> E; // Number of vertices and edges

    Graph graph(V);

    for (int i = 0; i < E; ++i) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        graph.addEdge(src, dest, weight);
    }

    vector<Edge> MST = graph.kruskalMST();

    // The MST edges are in MST vector

    return 0;
}
