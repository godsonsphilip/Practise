#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii; // (weight, node)

vector<pii> prims(int V, vector<vector<pii>>& adj) {
    vector<int> key(V, INT_MAX);       // Min weight to connect to MST
    vector<bool> inMST(V, false);      // MST inclusion flag
    vector<int> parent(V, -1);         // To store MST edges

    priority_queue<pii, vector<pii>, greater<pii>> pq; // Min-heap
    pq.push({0, 0});
    key[0] = 0;

    while (!pq.empty()) {
        int u = pq.top().second; // Get min key node not in MST
        pq.pop();
        inMST[u] = true;

        for (auto& [wt, v] : adj[u]) {
            if (!inMST[v] && wt < key[v]) {
                key[v] = wt;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    vector<pii> mstEdges;
    for (int i = 1; i < V; ++i) {
        mstEdges.push_back({parent[i], i});
    }
    return mstEdges;
}

int main() {
    int V = 5;
    vector<vector<pii>> adj(V);
    
    // (u, v, w) edges
    adj[0].push_back({2, 1});
    adj[1].push_back({2, 0});
    
    adj[0].push_back({3, 3});
    adj[3].push_back({3, 0});
    
    adj[1].push_back({4, 2});
    adj[2].push_back({4, 1});
    
    adj[1].push_back({1, 3});
    adj[3].push_back({1, 1});
    
    adj[2].push_back({5, 4});
    adj[4].push_back({5, 2});

    vector<pii> mst = prims(V, adj);
    cout << "Edges in MST:\n";
    for (auto& [u, v] : mst) {
        cout << u << " - " << v << endl;
    }

    return 0;
}
