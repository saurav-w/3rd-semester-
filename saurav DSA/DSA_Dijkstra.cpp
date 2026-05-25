#include <iostream>
#include <climits>
using namespace std;

#define MAX 10  // Maximum number of vertices

void Dijkstra(int graph[MAX][MAX], int n, int start) {
    int dist[MAX];      // Shortest distances
    bool visited[MAX];  // Visited vertices

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        // Pick the minimum distance vertex not yet visited
        int u = -1, minDist = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1) break; // Remaining vertices unreachable
        visited[u] = true;

        // Update distances of adjacent vertices
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && !visited[v] &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print shortest distances
    cout << "\nShortest distances from vertex " << start << ":\n";
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            cout << "Vertex " << i << " : Unreachable\n";
        else
            cout << "Vertex " << i << " : " << dist[i] << "\n";
    }
}

int main() {
    int n, start;
    int graph[MAX][MAX];

    cout << "Enter number of vertices (max " << MAX << "): ";
    cin >> n;

    cout << "Enter adjacency matrix (0 if no edge):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    cout << "Enter starting vertex: ";
    cin >> start;

    if (start < 0 || start >= n) {
        cout << "Invalid starting vertex.\n";
        return 0;
    }

    Dijkstra(graph, n, start);

    return 0;
}

