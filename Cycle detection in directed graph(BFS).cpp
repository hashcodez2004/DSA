class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        vector<int> degree(V,0);
        for(auto &it: edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            degree[v]++;
        }
        
        queue<int> q;
        for(int i=0;i<V;i++)
            if(degree[i]==0)
                q.push(i);
        
        vector<int> ans;        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto &it: adj[node]){
                degree[it]--;
                if(degree[it]==0)
                    q.push(it);
            }
        }
        
        return ans;
    }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int> ans=topoSort(V,edges);
        if(ans.size()==V) return false;
        return true;
    }
};