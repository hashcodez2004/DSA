class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
    vector<string> ans;

    void dfs(string node){
        while(!adj[node].empty()){
            string next=adj[node].top();
            adj[node].pop();
            dfs(next);
        }

        ans.push_back(node);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {

        for(auto &it: tickets){
            adj[it[0]].push(it[1]);
        }

        dfs("JFK");

        reverse(ans.begin(),ans.end());

        return ans;
    }
};