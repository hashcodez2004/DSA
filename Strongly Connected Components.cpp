class Solution {
private:

    // DFS on the original graph.
    // Stores nodes according to their finishing time.
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj, stack<int>& st) {
        vis[node] = 1;
        for(auto &it : adj[node]) {
            if(!vis[it]) dfs(it, vis, adj, st);
        }
        st.push(node);
    }

    // DFS on the reversed graph.
    // Every DFS traversal here represents one SCC.
    void componentsCnt(int node, vector<int>& vis, vector<vector<int>>& adj) {
        vis[node] = 1;
        for(auto &it : adj[node]) {
            if(!vis[it]) componentsCnt(it, vis, adj);
        }
    }

public:

    int kosaraju(int V, vector<vector<int>>& edges) {

        // Step 1: Build the original graph.
        vector<vector<int>> adj(V);
        for(auto &it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }

        // Step 2: DFS on original graph
        // and store nodes by finishing time.
        stack<int> st;
        vector<int> vis(V, 0);
        for(int i = 0; i < V; i++) {
            if(!vis[i])
                dfs(i, vis, adj, st);
        }

        // Step 3: Create the reversed graph.
        vector<vector<int>> rev(V);
        for(auto &it : edges) {
            int u = it[0];
            int v = it[1];
            rev[v].push_back(u);
        }

        // Step 4: Reset visited array.
        fill(vis.begin(), vis.end(), 0);

        // Step 5: Process vertices in decreasing
        // order of finishing time.
        int cnt = 0;
        while(!st.empty()) {
            int node = st.top();
            st.pop();

            if(!vis[node]) {
                cnt++;
                componentsCnt(node, vis, rev);
            }
        }

        return cnt;
    }
};
