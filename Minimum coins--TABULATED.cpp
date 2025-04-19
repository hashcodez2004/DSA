#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

    int minCoins(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k+1,1e9));
        for(int target=0;target<=k;target++) if(target%nums[0]==0) dp[0][target] = target/nums[0];

        for(int idx=1;idx<n;idx++){
            for(int target=0;target<=k;target++){
                int notTake = 0 + dp[idx-1][target];
                int take = 1e9;
                if(target>=nums[idx]) take = 1 + dp[idx][target-nums[idx]];

                dp[idx][target] = min(take,notTake);
            }
        }

        if(dp[n-1][k]==1e9) return -1;
        return dp[n-1][k];
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
Space Complexity: O(n x amount)
*/