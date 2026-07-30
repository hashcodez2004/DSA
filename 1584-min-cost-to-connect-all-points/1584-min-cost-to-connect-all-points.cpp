class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        //    MST(Prim's Algorithm)

        int n=points.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // {distance,index in points}
        vector<int> vis(n,0);

        pq.push({0,0});

        int cost=0;
        while(!pq.empty()){
            int dis=pq.top().first;
            int idx=pq.top().second;
            pq.pop();

            if(vis[idx]) continue;
            
            vis[idx]=1;
            cost+=dis;

            for(int i=0;i<n;i++){
                if(!vis[i]){
                    int newDis = abs(points[idx][0]-points[i][0]) + abs(points[idx][1]-points[i][1]);
                    pq.push({newDis,i});
                }
            }
        }

        return cost;
    }
};