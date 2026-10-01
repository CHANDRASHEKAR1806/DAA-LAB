#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int V;

    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    vector<int> key(V, INT_MAX);
    vector<bool> visited(V, false);
    vector<int> parent(V, -1);

    key[0] = 0;

    for (int count = 0; count < V - 1; count++) {

        int u = -1;

        for (int i = 0; i < V; i++) {
            if (!visited[i] && (u == -1 || key[i] < key[u]))
                u = i;
        }

        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 &&
                !visited[v] &&
                graph[u][v] < key[v]) {

                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int totalCost = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i
             << " : " << graph[i][parent[i]] << endl;

        totalCost += graph[i][parent[i]];
    }

    cout << "\nMinimum Cost = " << totalCost << endl;

    return 0;
}