#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n, 0), traversal;
        queue<int> q;

        vis[0] = 1;
        q.push(0);

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            traversal.push_back(node);

            for(auto it : adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
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
        vector<int> res = ob.bfs(adj);
        for(int x : res) cout << x << " ";
        cout << endl;
    }
    return 0;
}

/*
Time Complexity: O(V + 2E) for undirected graph ----- O(V + E) for directed graph
Space Complexity: O(V) for visited + O(V) for queue + O(V) output
*/
