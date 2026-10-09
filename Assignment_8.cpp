#include <iostream>
#include <vector>
#include <queue>
// Author: Om Kutwal Sy-12 roll no 70
using namespace std;

int main()
{
    int n, e;

    cout << "Enter number of users: ";
    cin >> n;

    cout << "Enter number of friendships: ";
    cin >> e;

    // Adjacency list
    vector<vector<int>> adj(n);

    cout << "\nEnter friendships (user1 user2):\n";
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        // Since friendship is mutual
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Display adjacency list
    cout << "\nAdjacency List:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "User " << i << " -> ";
        for (int j : adj[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }

    // Starting user
    int start;
    cout << "\nEnter starting user for BFS: ";
    cin >> start;

    // Visited array
    vector<bool> visited(n, false);

    // Queue for BFS
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "\nBFS Traversal (level by level):\n";

    int level = 0;

    while (!q.empty())
    {
        int size = q.size();

        cout << "Level " << level << ": ";

        // Process all users at the current level
        for (int i = 0; i < size; i++)
        {
            int current = q.front();
            q.pop();

            cout << current << " ";

            // Visit all friends
            for (int friendUser : adj[current])
            {
                if (!visited[friendUser])
                {
                    visited[friendUser] = true;
                    q.push(friendUser);
                }
            }
        }
        cout << endl;
        level++;
    }

    return 0;
}
