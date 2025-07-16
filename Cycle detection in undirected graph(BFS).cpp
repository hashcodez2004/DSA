#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool check(int node, vector<int>& vis, vector<vector<int>>& adj, queue<pair<int, int>>& q) {
        q.push({node, -1});
        vis[node] = 1;

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int curr = it.first;
            int parent = it.second;

            for (auto neighbor : adj[curr]) {
                if (!vis[neighbor]) {
                    vis[neighbor] = 1;
                    q.push({neighbor, curr});
                }
                else if (neighbor != parent) {
                    return true;
                }
            }
        }

        return false;
    }

public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(V, 0);
        queue<pair<int, int>> q;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (check(i, vis, adj, q))
                    return true;
            }
        }

        return false;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        Solution ob;
        bool ans = ob.isCycle(V, edges);
        cout << (ans ? "1" : "0") << endl;
    }
    return 0;
}

/*
Time Complexity: O(E) to build the adjacency list +
                 O(V + 2E) for BFS traversal
               = O(V + 3E)
               = O(V + E) [in Big-O notation]

Space Complexity: O(V + 2E) for adjacency list +
                  O(V) for visited array +
                  O(V) for BFS queue
               = O(V + 2E)
*/
