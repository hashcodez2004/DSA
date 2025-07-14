#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfsHelper(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& traversal) {
        traversal.push_back(node);
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) dfsHelper(it, adj, vis, traversal);
        }
    }

public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n, 0), traversal;
        dfsHelper(0, adj, vis, traversal);
        return traversal;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n);
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution ob;
        vector<int> res = ob.dfs(adj);
        for(int x : res) cout << x << " ";
        cout << endl;
    }
    return 0;
}

/*
Time Complexity: O(V + 2E) for undirected graph ----- O(V + E) for directed graph
Space Complexity: O(V) for visited + O(V) for recursion stack + O(V) output
*/
