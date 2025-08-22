class Solution {
private:
    void helper(int idx, vector<int>& v, vector<vector<int>>& ans, vector<int>& nums){
        ans.push_back(v);

        for(int i=idx; i<nums.size(); i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            v.push_back(nums[i]);
            helper(i+1,v,ans,nums);
            v.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> v;
        helper(0,v,ans,nums);
        return ans;
    }
};