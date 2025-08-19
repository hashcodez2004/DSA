class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        //Making the adjacency list and also adding the reversal edges
        vector<vector<pair<int,int>>> adj(n);
        for(auto it: edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,2*w});
        }

        //Performing the Diajkstra algorithm
        vector<int> dist(n,1e9);
        dist[0]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;  //{cost,node}
        pq.push({0,0});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            int wt=it.first;
            for(auto it: adj[node]){
                int newNode=it.first;
                int currWt=it.second;
                //Relaxation
                if(dist[node]+currWt<dist[newNode]){
                    dist[newNode]=dist[node]+currWt;
                    pq.push({currWt+dist[node],newNode});
                }
            }
        }
        if(dist[n-1]==1e9) return -1;
        return dist[n-1];
    }
};