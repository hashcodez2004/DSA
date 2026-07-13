class Solution {
  public:
    void dfs(int node, stack<int> &st, vector<bool> &vis, vector<vector<int>> &adj){
        vis[node]=1;
        
        for(auto &it: adj[node]){
            if(!vis[it])
                dfs(it,st,vis,adj);
        }
        
        st.push(node);
    }
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto &it: edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        
        stack<int> st;
        vector<bool> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i])
                dfs(i,st,vis,adj);
        }
        
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};