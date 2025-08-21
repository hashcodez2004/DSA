class Solution {
private:
    void helper(int idx, int target, vector<int>& v, vector<vector<int>>& ans, vector<int>& candidates){
        if(target==0){
            ans.push_back(v);
            return;
        }
        if(target<0 || idx==candidates.size()) return;

        for(int i=idx;i<candidates.size();i++){
            if(candidates[i]>target) break;
            else if(i>idx && candidates[i]==candidates[i-1]) continue;
            v.push_back(candidates[i]);
            helper(i+1,target-candidates[i],v,ans,candidates);
            v.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        helper(0,target,v,ans,candidates);
        return ans;
    }
};