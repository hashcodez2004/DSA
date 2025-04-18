#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    int findWaysHelper(const vector<int>& nums, int target){
        int n = nums.size();
        const int MOD = 1000000007;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0)); // Index shifting so that [0,0,3] case is handled
        
        dp[0][0] = 1;  // Base case: if(idx<0){
                       //              if(sum==0) return 1;
                       //              else return 0;
                       //            }
        
        for (int idx = 1; idx <= n; idx++) {
            for (int t = 0; t <= target; t++) {
                int notTake = dp[idx - 1][t];  // Exclude the current element
                int take = 0;
                if (nums[idx - 1] <= t) {
                    take = dp[idx - 1][t - nums[idx - 1]];  // Include the current element
                }
                dp[idx][t] = (take + notTake) % MOD;
            }
        }

        return dp[n][target];  // Return the answer for the full array and target sum
    }

public:
    int countPartitions(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if ((sum + k) % 2 != 0 || sum < k) return 0;
        sum = (sum+k)/2;
        return findWaysHelper(nums, sum);
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
        int s = ob.countPartitions(nums, k);
        cout << s << endl;
    }
    return 0;
}
