#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, wt;
    bool operator<(Edge const& other) {
        return wt < other.wt;  // Sort by weight in ascending order
    }
};

int find(vector<int>& parent, int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent, parent[x]);
}

void unite(vector<int>& parent, vector<int>& rank, int u, int v) {
    int pu = find(parent, u);
    int pv = find(parent, v);
    if (pu != pv) {
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
}

void Kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());  // Sort edges by weight
    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; i++) parent[i] = i;

    vector<Edge> mst;
    int totalWeight = 0;

    // Iterate through sorted edges
    for (auto& e : edges) {
        if (find(parent, e.u) != find(parent, e.v)) {  // If they belong to different components
            unite(parent, rank, e.u, e.v);  // Unite the components
            mst.push_back(e);               // Add to MST
            totalWeight += e.wt;            // Add weight to total weight
        }
    }

    // Print the MST
    cout << "Edges in MST:\n";
    for (auto& e : mst) {
        cout << e.u << " - " << e.v << " : " << e.wt << "\n";
    }
    cout << "Total weight: " << totalWeight << "\n";
}

int main() {
    int n, m;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;

    vector<Edge> edges(m);
    cout << "Enter edges (u v wt):\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].wt;
    }

    Kruskal(n, edges);
    return 0;
}
