#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for(int idx = n - 1; idx >= 0; idx--) {
            for(int prev_idx = idx - 1; prev_idx >= -1; prev_idx--) {
                int notTake = dp[idx + 1][prev_idx + 1];
                int take = 0;
                if(prev_idx == -1 || nums[idx] > nums[prev_idx]) {
                    take = 1 + dp[idx + 1][idx + 1];
                }
                dp[idx][prev_idx + 1] = max(take, notTake);
            }
        }

        return dp[0][0];  // corresponds to helper(0, -1)
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
        int s = ob.lengthOfLIS(nums);
        cout << s << endl;
    }
    return 0;
}


/*
Time Complexity: O(n * n)
Space Complexity: O(n * n)
*/