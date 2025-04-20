#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    int helper(int idx, int W, const vector<int>& wt, const vector<int>& val, vector<vector<int>>& dp){
         if(idx==0){
            if(wt[idx]<=W) return val[idx];
            return 0;
         }

         if(dp[idx][W]!=-1) return dp[idx][W];

         int notTake = helper(idx-1,W,wt,val,dp);
         int take = 0;
         if(wt[idx]<=W) take = val[idx] + helper(idx-1,W-wt[idx],wt,val,dp);

         return dp[idx][W] = max(take,notTake);
    }

public:
    int knapsack(int W, const vector<int>& wt, const vector<int>& val) {
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(W+1,-1));
        return helper(n-1,W,wt,val,dp);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, W;
        cin >> n >> W;
        vector<int> val (n);
        for (int i = 0; i < n; i++) cin >> val[i];
        vector<int> wt(n);
        for (int i = 0; i < n; i++) cin >> wt[i];

        Solution ob;
        int s = ob.knapsack(W, wt, val);
        cout << s << endl;
    }
    return 0;
}


/*
Time Complexity: O(n x W)
Space Complexity: O(n x W) [for DP table] + O(n) [stack space]
*/