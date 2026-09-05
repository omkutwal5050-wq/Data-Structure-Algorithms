/*Title: A city road network is represented as a graph where intersections are
and roads are edges. Represent the graph using an adjacency matrix and implement
Depth First Search (DFS) to explore all connected locations.*/

#include <iostream>
using namespace std;

#define MAX 100

// DFS function
void DFS(int vertex, int n, int adj[MAX][MAX], bool visited[MAX])
{
    // Mark the current vertex as visited
    visited[vertex] = true;

    cout << vertex << " ";

    // Check all vertices connected to current vertex
    for (int i = 0; i < n; i++)
    {
        if (adj[vertex][i] == 1 && visited[i] == false)
        {
            DFS(i, n, adj, visited);
        }
    }
}

int main()
{
    int n, edges;

    int adj[MAX][MAX] = {0};
    bool visited[MAX] = {false};

    // Input number of intersections
    cout << "Enter number of intersections: ";
    cin >> n;

    // Input number of roads
    cout << "Enter number of roads: ";
    cin >> edges;

    // Input roads
    cout << "\nEnter the roads (two intersection numbers):\n";

    for (int i = 0; i < edges; i++)
    {
        int u, v;

        cout << "Road " << i + 1 << ": ";
        cin >> u >> v;

        // Since the road is bidirectional
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // Display adjacency matrix
    // Om kutwal SY-12 Roll No. 70
    cout << "\n===== ADJACENCY MATRIX =====\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adj[i][j] << " ";
        }

        cout << endl;
    }

    // Starting vertex for DFS
    int start;

    cout << "\nEnter starting intersection for DFS: ";
    cin >> start;

    // Perform DFS
    cout << "\n===== DFS TRAVERSAL =====\n";
    cout << "DFS starting from intersection "
         << start << ": ";

    DFS(start, n, adj, visited);

    cout << endl;

    return 0;
}