#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<long long>> dp(n,vector<long long>(amount+1,0));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0) dp[0][i]=1;
        }

        for(int idx=1;idx<n;idx++){
            for(int amt=0;amt<=amount;amt++){
                int notTake = dp[idx-1][amt];
                int take = 0;
                if(coins[idx]<=amt) take = dp[idx][amt-coins[idx]];
                dp[idx][amt] = (long long)take + (long long)notTake;
            }
        }
        return dp[n-1][amount];
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
Space Complexity: O(n x amount) [for DP table]
*/