#include<bits/stdc++.h>
using namespace std;

void makeSet(vector<int>& parent, int n, vector<int>& rank) {
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int>& parent, int node) {
    if (parent[node] != node)
        parent[node] = findParent(parent, parent[node]);
    return parent[node];
}

void makeUnion(int u, int v, vector<int>& parent, vector<int>& rank) {
    int rootU = findParent(parent, u);
    int rootV = findParent(parent, v);

    if (rootU != rootV) {
        if (rank[rootU] < rank[rootV])
            parent[rootU] = rootV;
        else if (rank[rootU] > rank[rootV])
            parent[rootV] = rootU;
        else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

vector<int> primMST(vector<vector<int>>& graph) {
    int vertices = graph.size();
    vector<int> mst;
    vector<int> parent(vertices);
    vector<int> rank(vertices, 0);

    // Initialize parent and rank arrays
    makeSet(parent, vertices, rank);

    // Initialize MST with the first vertex
    mst.push_back(0);

    while (mst.size() < vertices) {
        int minEdge = INT_MAX;
        int u = -1, v = -1;

        for (int i : mst) {
            for (int j = 0; j < vertices; ++j) {
                if (find(mst.begin(), mst.end(), j) == mst.end() && graph[i][j] < minEdge) {
                    minEdge = graph[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        if (u != -1 && v != -1) {
            mst.push_back(v);
            makeUnion(u, v, parent, rank);
        }
    }

    return mst;
}

int main() {
    // Example usage
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    vector<int> result = primMST(graph);

    cout << "Minimum Weight Spanning Tree (MST) edges:\n";
    for (int i = 1; i < result.size(); ++i)
        cout << result[i - 1] << " - " << result[i] << "\n";

    return 0;
}
