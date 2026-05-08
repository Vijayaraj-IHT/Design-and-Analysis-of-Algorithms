#include <iostream>
#include <climits>
using namespace std;

const int INF = INT_MAX;

// Print the distance matrix
void printDistanceMatrix(int **dist, int V) {
    cout << "\nShortest Distance Matrix:\n";
    cout << "    ";
    for (int i = 0; i < V; i++)
        cout << i << "     ";
    cout << endl;

    for (int i = 0; i < V; i++) {
        cout << i << "  ";
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF   ";
            else
                cout << dist[i][j] << "     ";
        }
        cout << endl;
    }
}

// Print the path between two vertices
void printPath(int **next, int u, int v) {
    if (next[u][v] == -1) {
        cout << "No path exists\n";
        return;
    }

    cout << "Path from " << u << " to " << v << ": ";
    int current = u;
    cout << current;

    while (current != v) {
        current = next[current][v];
        cout << " -> " << current;
    }
    cout << endl;
}

// Floyd-Warshall Algorithm
void floydWarshall(int **graph, int V) {
    int **dist = new int*[V];
    int **next = new int*[V];

    // Initialize distance and next matrices
    for (int i = 0; i < V; i++) {
        dist[i] = new int[V];
        next[i] = new int[V];

        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];

            if (i == j)
                next[i][j] = -1;
            else if (graph[i][j] != INF && graph[i][j] != 0)
                next[i][j] = j;
            else
                next[i][j] = -1;
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // Avoid overflow
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        next[i][j] = next[i][k];
                    }
                }
            }
        }
    }

    // Check for negative cycles
    bool hasNegativeCycle = false;
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            hasNegativeCycle = true;
            cout << "Negative cycle detected at vertex " << i << endl;
        }
    }

    // Print results
    printDistanceMatrix(dist, V);

    // Print all shortest paths (optional)
    cout << "\nShortest Paths:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i != j) {
                if (dist[i][j] == INF) {
                    cout << "From " << i << " to " << j << ": No path (INF)\n";
                } else {
                    cout << "From " << i << " to " << j << ": Distance = " << dist[i][j] << " | ";
                    printPath(next, i, j);
                }
            }
        }
    }

    // Free memory
    for (int i = 0; i < V; i++) {
        delete[] dist[i];
        delete[] next[i];
    }
    delete[] dist;
    delete[] next;
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    int **graph = new int*[V];
    for (int i = 0; i < V; i++)
        graph[i] = new int[V];

    cout << "Enter adjacency matrix (use " << INF << " for no edge):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    floydWarshall(graph, V);

    // Free memory
    for (int i = 0; i < V; i++)
        delete[] graph[i];
    delete[] graph;

    return 0;
}