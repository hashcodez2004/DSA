class Solution {
  public:
    void DFS(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node]=1;

        for(auto &it: adj[node]){
            if(!visited[it])
                DFS(it, adj, visited);
        }
    }
  
  
    int isEulerCircuit(int V, vector<vector<int>>& adj) {
        // code here
        
        // Euler Circuit : 2
        // Calculate the Degree of Each node
        // All node should have even degree
        // All non-zero degree node should be connected

        // Euler path : 1
        // Calculate the Degree of Each node
        // zero or two node can have odd degree and remaining have even degree
        // All non-zero degree node should be connected

        vector<int> deg(V,0);
        int odd_Deg=0;   // number of nodes having odd degree

        for(int i=0;i<V;i++){
            deg[i]=adj[i].size();
            if(deg[i]%2) odd_Deg++;
        }

        if(odd_Deg != 2 && odd_Deg != 0) return 0;

        vector<bool> visited(V, 0);
        for(int i = 0; i < V; i++){
            //starting dfs from first non-zero degree node so that can check whether all edges in one component
            if(deg[i])
            {
                DFS(i, adj, visited);
                break;
            }
        }
        
        // If non zero degree node is still not visited, return 0
        // Degree zero hai, usko ignore (Koi edge nahi hai)
        for(int i = 0; i < V; i++){
            if(deg[i] && !visited[i]) return 0;
        }

        // Eulerian circuit: 2
        // Eulerian Path: 1;
        if(odd_Deg == 0) return 2;
        else return 1;
    }
};