#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int helper(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int maxi = -1e9;
        for(int ind=i; ind<=j; ind++){
            int cost = (nums[i-1]*nums[ind]*nums[j+1]) + helper(i,ind-1,nums,dp) + helper(ind+1,j,nums,dp);
            maxi = max(maxi,cost);
        }
        return dp[i][j] = maxi;
    }

public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        return helper(1,n,nums,dp);
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
        int s = ob.maxCoins(nums);
        cout << s << endl;
    }
    return 0;
}


/*
Time Complexity: O(c*c*c)
Space Complexity: O(c*c)
*/