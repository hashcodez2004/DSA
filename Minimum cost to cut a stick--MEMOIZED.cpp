#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int helper(int i, int j, vector<int>& cuts, vector<vector<int>>& dp){
        if(i>j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int mini = 1e9;
        for(int ind=i; ind<=j; ind++){
            int cost = (cuts[j+1]-cuts[i-1]) + helper(i,ind-1,cuts,dp) + helper(ind+1,j,cuts,dp);
            mini = min(mini,cost);
        }
        return dp[i][j] = mini;
    }

public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        int c = cuts.size();
        vector<vector<int>> dp(c, vector<int>(c,-1)); //c-1 will also work since going till c-2 max
        return helper(1,cuts.size()-2,cuts,dp);
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
        int s = ob.minCost(n,nums);
        cout << s << endl;
    }
    return 0;
}


/*
Time Complexity: O(c*c*c)
Space Complexity: O(c*c)
*/