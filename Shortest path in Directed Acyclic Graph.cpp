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
  
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<int> topo=topoSort(V,edges);
        
        vector<vector<pair<int,int>>> adj(V);
        for(auto &it: edges){
            int u=it[0];
            int v=it[1];
            int d=it[2];
            adj[u].push_back({v,d});
        }
        
        vector<int> dis(V,INT_MAX);
        dis[0]=0;
        
        //Relaxation acc to topo sort order
        for(auto &node: topo){
            if(dis[node] == INT_MAX){
                continue;
            }
            
            for(auto &it: adj[node]){
                int currNode=it.first;
                int wt=it.second;
                
                int newDis=dis[node]+wt;
                
                if(newDis<dis[currNode]) dis[currNode]=newDis;
            }
        }
        
        for(auto &it: dis){
            if(it==INT_MAX) it=-1;
        }
        
        return dis;
    }
};


/*
Algorithm:
1. Build an adjacency list (without weights) for Topological Sort.
2. Perform Topological Sort using DFS.
3. Build a weighted adjacency list for shortest path calculation.
4. Initialize the source (0) distance as 0.
5. Traverse the nodes in Topological Order.
6. Relax all outgoing edges of every reachable node.
7. Replace unreachable distances (INT_MAX) with -1.

Why Topological Sort?
In a DAG, every node appears before all the
nodes reachable from it in Topological Order.
Hence, when processing a node, its shortest
distance has already been finalized, so each
edge needs to be relaxed only once.

Time Complexity:
O(V + E)

- Building adjacency list (Topo Sort)     : O(E)
- DFS Topological Sort                    : O(V + E)
- Building weighted adjacency list        : O(E)
- Edge Relaxation                         : O(E)

Overall : O(V + E)

Space Complexity:
O(V + E)

- Adjacency List (Topo Sort)              : O(V + E)
- Weighted Adjacency List                 : O(V + E)
- Visited Array                           : O(V)
- Distance Array                          : O(V)
- DFS Stack                               : O(V)
- Topological Stack                       : O(V)
*/