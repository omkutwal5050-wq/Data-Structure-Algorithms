#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to store each connection
struct Edge {
    int source, destination, cost;
};

// Disjoint Set Union (DSU)
class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) {
            return false;
        }

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        }
        else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        }
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }

        return true;
    }
};

int main() {
    int vertices, edges;

    cout << "Enter number of substations: ";
    cin >> vertices;

    cout << "Enter number of connections: ";
    cin >> edges;

    vector<Edge> graph(edges);

    cout << "Enter source destination cost for each connection:\n";

    for (int i = 0; i < edges; i++) {
        cin >> graph[i].source
            >> graph[i].destination
            >> graph[i].cost;
    }

    // Sort connections by cost
    sort(graph.begin(), graph.end(), [](Edge a, Edge b) {
        return a.cost < b.cost;
    });

    DSU dsu(vertices);

    int totalCost = 0;
    int selectedEdges = 0;
    cout << "om kutwal Sy-12 roll no 70"<<endl;
    cout << "\nMinimum Spanning Tree (MST):\n";
    cout << "Substation 1   Substation 2   Cost\n";

    for (const Edge &e : graph) {
        if (e.source < 0 || e.source >= vertices ||
            e.destination < 0 || e.destination >= vertices) {
            cout << "Invalid substation number.\n";
            return 1;
        }

        if (dsu.unite(e.source, e.destination)) {
            cout << e.source << "   " << e.destination << "   " << e.cost << "\n";
            totalCost += e.cost;
            selectedEdges++;
        }

        if (selectedEdges == vertices - 1) {
            break;
        }
    }

    if (selectedEdges != vertices - 1) {
        cout << "\nNetwork is disconnected. MST cannot be formed.\n";
    }
    else {
        cout << "\nMinimum total wiring cost = " << totalCost << "\n";
    }

    return 0;
}