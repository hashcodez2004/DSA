#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int helper(int idx, int amt, const vector<int>& coins, vector<vector<int>>& dp){
        if(idx==0){
            if(amt%coins[0]==0) return 1;
            else return 0;
        }

        if(dp[idx][amt] != -1) return dp[idx][amt];

        int notTake = helper(idx-1,amt,coins,dp);
        int take = 0;
        if(coins[idx]<=amt) take = helper(idx,amt-coins[idx],coins,dp);

        return dp[idx][amt] = take + notTake;
    }

public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return helper(n-1,amount,coins,dp);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, amount;
        cin >> n >> amount;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];

        Solution ob;
        int s = ob.change(amount, nums);
        cout << s << endl;
    }
    return 0;
}


/*
Time Complexity: O(n x amount)
Space Complexity: O(n x amount) [for DP table] + O(amount) [ASS]
*/