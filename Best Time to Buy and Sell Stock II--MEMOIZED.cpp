#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int helper(int idx, int buy, vector<int>& prices, vector<vector<int>>& dp){
        if(idx == prices.size()) return 0;

        if(dp[idx][buy] != -1) return dp[idx][buy];

        int profit = 0;
        if(buy){
            profit = max(-prices[idx] + helper(idx+1,0,prices,dp),
                          0 + helper(idx+1,1,prices,dp));
        }
        else{
            profit = max(prices[idx] + helper(idx+1,1,prices,dp),
                          0 + helper(idx+1,0,prices,dp));
        }
        return dp[idx][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return helper(0, 1, prices, dp);
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
        int s = ob.maxProfit(nums);
        cout << s << endl;
    }
    return 0;
}


/*
Time Complexity: O(n * 2)
Space Complexity: O(n * 2) + O(n)
*/