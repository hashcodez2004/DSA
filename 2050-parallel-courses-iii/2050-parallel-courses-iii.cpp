class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n+1);
        vector<int> indegree(n+1,0);
        for(auto &it: relations){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for(int i=1;i<=n;i++){
            if(indegree[i]==0)
                q.push(i);
        }

        int totTime=0;
        while(!q.empty()){
            int size=q.size();
            
            int maxi=0;
            for(int i=0;i<size;i++){
                int node=q.front();
                q.pop();

                maxi=max(maxi,time[node-1]);

                for(auto &it: adj[node]){
                    indegree[it]--;
                    if(indegree[it]==0) q.push(it);
                }
            }

            totTime+=maxi;
        }

        return totTime;
    }
};