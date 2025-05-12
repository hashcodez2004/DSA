#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int helper(int idx, int prev_idx, vector<int>& nums, vector<vector<int>>& dp){
        if(idx==nums.size()) return 0;

        if(dp[idx][prev_idx+1] != -1) return dp[idx][prev_idx+1];

        int notTake = helper(idx+1,prev_idx,nums,dp);
        int take = 0;
        if(prev_idx == -1 || nums[idx]>nums[prev_idx]) take = 1 + helper(idx+1,idx,nums,dp);

        return  dp[idx][prev_idx+1] = max(take,notTake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return helper(0,-1,nums,dp);
    }
};




int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i=0; i<n; i++) cin >> nums[i];
        Solution ob;
        int s = ob.lengthOfLIS(nums);
        cout << s << endl;
    }
    return 0;
}


/*
Time Complexity: O(n * n)
Space Complexity: O(n * n) + O(n)
*/