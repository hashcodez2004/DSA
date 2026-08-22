class Solution {
private:
    void helper(int idx, int target, int k, vector<int> &curr, vector<int> &nums, vector<vector<int>> &ans){
        if(curr.size()==k && target==0){
            ans.push_back(curr);
            return;
        }

        if(curr.size()==k || idx==9 || nums[idx]>target) return;

        //Not Take
        helper(idx+1,target,k,curr,nums,ans);

        //Take
        curr.push_back(nums[idx]);
        helper(idx+1,target-nums[idx],k,curr,nums,ans);
        curr.pop_back();
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> curr;
        helper(0,n,k,curr,nums,ans);
        return ans;
    }
};