class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        // BFS + Map
        int n=friends.size();
        queue<int> q;
        vector<int> vis(n,0);
        unordered_map<string,int> mpp;

        q.push(id);
        vis[id]=1;

        while(!q.empty()){
            int size=q.size();

            if(level==0){
                while(size--){
                    int node=q.front();
                    q.pop();

                    for(auto &it: watchedVideos[node]){
                        mpp[it]++;
                    }
                }
            }

            else{
                while(size--){
                    int node=q.front();
                    q.pop();

                    for(auto &it: friends[node]){
                        if(!vis[it]){
                            q.push(it);
                            vis[it]=1;
                        }
                    }
                }
                level--;
            }
        }

        set<pair<int,string>> st;
        for(auto &it: mpp){
            st.insert(make_pair(it.second,it.first));
        }

        vector<string> ans;
        for(auto &it: st){
            ans.push_back(it.second);
        }

        return ans;
    }
};