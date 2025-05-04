#include <iostream>
#include <vector>
#include <climits>  // For INT_MAX
using namespace std;

void floydWarshall(vector<vector<int>>& graph, int n) {
    // Initialize the distance matrix with the given graph
    vector<vector<int>> dist = graph;

    // Apply the Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {  // k is the intermediate vertex
        for (int i = 0; i < n; i++) {  // i is the source vertex
            for (int j = 0; j < n; j++) {  // j is the destination vertex
                // If the path through vertex k is shorter, update the distance
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distance matrix
    cout << "Shortest distances between every pair of vertices:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INT_MAX) {
                cout << "INF" << " ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int>> graph(n, vector<int>(n, INT_MAX));

    // Distance from each vertex to itself is 0
    for (int i = 0; i < n; i++) {
        graph[i][i] = 0;
    }

    cout << "Enter the edges (source, destination, weight):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;  // As the graph is directed
    }

    floydWarshall(graph, n);

    return 0;
}
