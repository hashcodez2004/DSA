#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool check(int node, int parent, vector<int>& vis, vector<vector<int>>& adj) {
        vis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (check(it, node, vis, adj)) return true;
            }
            else if (it != parent) {
                return true;
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

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (check(i, -1, vis, adj)) return true;
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
        vector<vector<int>> edges(E, vector<int>(2));
        for (int i = 0; i < E; i++) {
            cin >> edges[i][0] >> edges[i][1];
        }

        Solution ob;
        bool ans = ob.isCycle(V, edges);
        cout << (ans ? "1" : "0") << endl;
    }
    return 0;
}


/*
Time Complexity:
- O(E) for building the adjacency list (each undirected edge is stored twice)
- O(V + 2E) for DFS traversal:
  - Each node is visited once → O(V)
  - Each undirected edge is checked twice → O(2E)

Total: O(V + 3E) → Simplified: O(V + E)

Space Complexity:
- O(V + 2E) for adjacency list
- O(V) for visited array
- O(V) for recursion stack (in worst case, depth = V)

Total: O(V + 2E)
*/
