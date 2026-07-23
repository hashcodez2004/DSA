class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> adj[n+1];
        for(auto &it: times){
            int u=it[0];
            int v=it[1];
            int t=it[2];
            adj[u].push_back({v,t});
        }

        vector<int> time(n+1,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        pq.push({0,k});
        time[k]=0;

        while(!pq.empty()){
            int node=pq.top().second;
            int currTime=pq.top().first;
            pq.pop();

            if(currTime > time[node]){
                continue;
            }

            for(auto &it: adj[node]){
                int neighbourNode=it[0];
                int neighbourTime=currTime+it[1];

                if(neighbourTime<time[neighbourNode]){
                    time[neighbourNode]=neighbourTime;
                    pq.push({neighbourTime,neighbourNode});
                }
            }
        }

        int ans=INT_MIN;
        for(int i=1;i<n+1;i++){
            if(time[i]==INT_MAX) return -1;
            ans=max(ans,time[i]);
        }

        return ans;
    }
};