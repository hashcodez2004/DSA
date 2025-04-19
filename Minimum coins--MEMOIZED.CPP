#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    int helper(int idx, int target, const vector<int>& nums, vector<vector<int>>& dp){
        if(idx==0){
            if(target%nums[0]==0) return target/nums[0];
            else return INT_MAX;
        }

        if(dp[idx][target] != -1) return dp[idx][target];

        int notTake = 0 + helper(idx-1,target,nums,dp);
        int take = INT_MAX;
        if(target>=nums[idx]) take = 1 + helper(idx,target-nums[idx],nums,dp);

        return dp[idx][target] = min(take,notTake);
    }

public:

    int minCoins(vector<int>& nums, int k) {
        vector<vector<int>> dp(nums.size(), vector<int>(k+1,-1));
        int ans = helper(nums.size()-1,k,nums,dp);
        if(ans==INT_MAX) return -1;
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];

        Solution ob;
        int s = ob.minCoins(nums, k);
        cout << s << endl;
    }
    return 0;
}


/*
Time Complexity: O(n x amount)
Space Complexity: O(n x amount) + O(amount)
*/