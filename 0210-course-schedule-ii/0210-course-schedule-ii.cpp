class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& pre) {
        vector<vector<int>> adj(V);
        vector<int> degree(V,0);
        for(auto &it: pre){
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
            degree[u]++;
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
        
        if(ans.size()==V) return ans;
        return {};
    }
};