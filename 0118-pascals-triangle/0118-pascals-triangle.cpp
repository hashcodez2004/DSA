class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        while(ans.size()<n){
            int x=ans.size();
            vector<int> v;
            v.push_back(1);
            for(int i=1;i<x;i++) v.push_back(ans.back()[i] + ans.back()[i-1]);
            if(x>0) v.push_back(1);
            ans.push_back(v);
        }
        return ans;
    }
};