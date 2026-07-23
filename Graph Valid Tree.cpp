class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &vis){
        vis[node]=1;
        for(auto &it: adj[node]){
            if(it==parent) continue;
            if(vis[it]) return false;
            else if(dfs(it,node,adj,vis)==false) return false;
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        // CYCLE DETECTION IN UNDIRECTED GRAPH
        //    DFS Approach

        vector<vector<int>> adj(n);
        for(auto &it: edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n,0);

        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(cnt==1) return false;
                cnt++;
                if(dfs(i,-1,adj,vis)==false)
                    return false;
            }
        }

        return true;
    }
};
