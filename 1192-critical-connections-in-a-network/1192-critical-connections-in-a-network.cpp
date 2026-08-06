class Solution {
    int timer=1;

private:
    void dfs(int node, int par, vector<bool> &vis, vector<int> &tin, vector<int> &low, vector<vector<int>> &adj, vector<vector<int>> &bridges){
        vis[node]=true;
        tin[node]=low[node]=timer++;

        for(auto &it: adj[node]){
            if(it==par) continue;
            if(!vis[it]){
                dfs(it,node,vis,tin,low,adj,bridges);
                low[node]=min(low[it],low[node]);
                if(low[it] > tin[node]) bridges.push_back({node,it});
            }
            else low[node]=min(low[it],low[node]);
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto &it: connections){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> tin(n);
        vector<int> low(n);
        vector<bool> vis(n,0);
        vector<vector<int>> bridges;

        dfs(0,-1,vis,tin,low,adj,bridges);

        return bridges;
    }
};