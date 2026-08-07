class Solution {
  public:
    bool dfs(int node, vector<int> &vis, vector<vector<int>> &adj, int &count, int V){
        vis[node]=1;
        count++;
        
        if(count==V) return true;
        
        for(auto &it: adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,adj,count,V)) return true;
            }
        }
        
        count--;
        vis[node]=0;
        return false;
    }
  
    bool check(int n, int m, vector<vector<int>> edges) {
        // code here
        if(m<n-1) return false;
        
        vector<vector<int>> adj(n+1);
        for(auto &it: edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(n+1,0);
        
        int count=0;
        for(int i=1;i<=n;i++){
            if(dfs(i,vis,adj,count,n)) return true;
        }
        
        return false;
    }
};
