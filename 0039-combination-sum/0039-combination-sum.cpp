class Solution {
private:
    void helper(int idx, int target, vector<int>& v, vector<vector<int>>& ans, vector<int>& candidates){
        if(target<0) return;
        if(idx==candidates.size()){
            if(target==0) ans.push_back(v);
            return;
        }

        //notTake
        helper(idx+1,target,v,ans,candidates);
        //take
        v.push_back(candidates[idx]);
        helper(idx,target-candidates[idx],v,ans,candidates);
        v.pop_back();
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(0,target,v,ans,candidates);
        return ans;
    }
};