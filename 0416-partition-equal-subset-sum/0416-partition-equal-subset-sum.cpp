class Solution {
private:
    bool helper(int idx, int target, vector<int>& nums, vector<vector<int>> &dp){
        if(idx<0) return target==0;

        if(dp[idx][target] != -1) return dp[idx][target];

        bool take = false;
        if(nums[idx]<=target) take = helper(idx-1,target-nums[idx],nums,dp);

        bool notTake = helper(idx-1,target,nums,dp);

        return dp[idx][target] = take || notTake;
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int target = 0;
        for(int i=0;i<n;i++) target+=nums[i];

        if(target%2 == 1) return false;

        vector<vector<int>> dp(n, vector<int>(target/2+1, -1));

        return helper(n-1,target/2,nums,dp);
    }
};