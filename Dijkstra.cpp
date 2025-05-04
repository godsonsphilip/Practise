#include <iostream>
#include <vector>
#include <queue>
#include <climits> // For INT_MAX
using namespace std;

// Dijkstra's Algorithm to find the shortest path from a source vertex
void dijkstra(vector<vector<pair<int, int>>>& graph, int n, int source) {
    vector<int> dist(n, INT_MAX);  // Initialize distances to all vertices as INF
    dist[source] = 0;  // Distance from source to itself is 0

    // Min-heap priority queue to get the vertex with the minimum distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});  // Push the source vertex with a distance of 0

    while (!pq.empty()) {
        // Get the vertex with the minimum distance
        int u = pq.top().second; 
        int d = pq.top().first;
        pq.pop();

        // If the distance is already greater, skip the processing
        if (d > dist[u]) continue;

        // Explore the neighbors of vertex u
        for (auto& edge : graph[u]) {
            int v = edge.first;  // Neighbor vertex
            int weight = edge.second;  // Edge weight

            // Relax the edge if a shorter path to v is found
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});  // Push the updated distance to the priority queue
            }
        }
    }

    // Print the shortest distances from the source
    cout << "Shortest distances from source vertex " << source << ":" << endl;
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) {
            cout << "INF ";
        } else {
            cout << dist[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    // Adjacency list representation of the graph
    vector<vector<pair<int, int>>> graph(n);

    cout << "Enter the edges (source, destination, weight):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});  // For directed graph
        graph[v].push_back({u, w});  // Uncomment this line for undirected graph
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    dijkstra(graph, n, source);

    return 0;
}
