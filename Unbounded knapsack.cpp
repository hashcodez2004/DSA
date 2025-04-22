#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int knapsack(int W, const vector<int>& wt, const vector<int>& val) {
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(W+1,0));
        for(int i=0;i<=W;i++){
            dp[0][i]=(i/wt[0])*val[0];
        }

        for(int idx=1;idx<n;idx++){
            for(int weight=1;weight<=W;weight++){
                int notTake = dp[idx-1][weight];
                int take = 0;
                if(wt[idx]<=weight) take = val[idx] + dp[idx-1][weight-wt[idx]];
                dp[idx][weight] = max(take,notTake);
            }
        }
        return dp[n-1][W];
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
Space Complexity: O(n x W) [for DP table]
*/