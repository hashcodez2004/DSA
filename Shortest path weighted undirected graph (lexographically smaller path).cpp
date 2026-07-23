class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        // Code here
        vector<vector<pair<int,int>>> adj(V+1);
        for(auto &it: edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        vector<int> dis(V+1, INT_MAX);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        dis[dest] = 0;
        pq.push({0, dest});

        while(!pq.empty()){

            int currDis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Ignore outdated entries
            if(currDis > dis[node]){
                continue;
            }

            for(auto &it : adj[node]){

                int neighbourNode = it.first;
                int edgeWeight = it.second;

                int newDis = currDis + edgeWeight;

                if(newDis < dis[neighbourNode]){

                    dis[neighbourNode] = newDis;

                    pq.push({newDis, neighbourNode});
                }
            }
        }
        
        if(dis[src]==INT_MAX) return {-1};
        
        vector<int> path;

        int node = src;
        path.push_back(node);
    
        while (node != dest) {
    
            int nextNode = -1;
    
            for (auto &it : adj[node]) {
    
                int adjNode = it.first;
                int wt = it.second;
    
                // Check if this edge belongs to any shortest path.
                if (dis[node] == dis[adjNode] + wt) {
    
                    if (nextNode == -1 || adjNode < nextNode)
                        nextNode = adjNode;
                }
            }
    
            node = nextNode;
            path.push_back(node);
        }
    
        return path;
    }
};