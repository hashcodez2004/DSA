class Solution {
    void helper(int idx, vector<int>& v, vector<int>& nums, vector<vector<int>>& ans){
        if(idx==nums.size()){
            ans.push_back(v);
            return;
        }
        //notTake
        helper(idx+1,v,nums,ans);
        //take
        v.push_back(nums[idx]);
        helper(idx+1,v,nums,ans);
        v.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> v;
        helper(0,v,nums,ans);
        return ans;
    }
};