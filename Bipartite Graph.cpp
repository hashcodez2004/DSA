//                                  BFS
class Solution {
private:
    bool bfs(int i, vector<vector<int>>& graph, vector<int>& color){
        queue<int> q;
        q.push(i);
        color[i]=0;

        while(!q.empty()){
            int node = q.front();
            int col = color[node];
            q.pop();

            for(auto it: graph[node]){
                if(color[it]==-1){
                    color[it]=!col;
                    q.push(it);
                }
                else if(color[it]==col) return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        //bfs while keeping track of which color each node has been given
        int n = graph.size();
        vector<int> color(n,-1);  //will work both as visited matrix and also telling which color it holds
        
        //checking all components
        for(int i=0;i<n;i++){
            if(color[i]==-1)
                if(!bfs(i,graph,color)) return false;
        }

        return true;
    }
};



//                                DFS
class Solution {
  public:
    bool dfs(int node, vector<int> &col, vector<vector<int>> &adj){
        int color=col[node];
        
        for(auto &it: adj[node]){
            if(col[it]==-1){
                col[it]=!color;
                if(dfs(it,col,adj)==false) return false;
            }
            else if(col[it]==color) return false;
        }
        
        return true;
    }
  
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto &it: edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        //color array => -1(nothing), 1(R), 0(G)
        vector<int> col(V,-1);
        
        //checking all components
        for(int i=0;i<V;i++){
            if(col[i]==-1){
                col[i]=0;
                if(dfs(i,col,adj)==false) return false;
            }
        }
        
        return true;
    }
};

/*
TC: O(V+2E)
SC: O(V) + O(V) (queue and color array)
*/
