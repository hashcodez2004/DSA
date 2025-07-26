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

/*
TC: O(V+2E)
SC: O(V) + O(V) (queue and color array)
*/