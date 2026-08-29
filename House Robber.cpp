// ============================================================
// Approach 1: Recursion (Brute Force)
// TC: O(2^n)
// SC: O(n) - Recursion stack
// ============================================================

class Solution {
private:
    int helper(int idx, vector<int> &nums) {
        if(idx == 0)
            return nums[idx];

        if(idx < 0)
            return 0;

        // Take
        int take = helper(idx - 2, nums) + nums[idx];

        // Not Take
        int notTake = helper(idx - 1, nums);

        return max(take, notTake);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        return helper(n - 1, nums);
    }
};



// ============================================================
// Approach 2: Memoization (Top-Down DP)
// TC: O(n)
// SC: O(n) - DP array + Recursion stack
// ============================================================

class Solution {
private:
    int helper(int idx, vector<int> &nums, vector<int> &dp) {
        if(idx == 0)
            return nums[idx];

        if(idx < 0)
            return 0;

        if(dp[idx] != -1)
            return dp[idx];

        // Take
        int take = helper(idx - 2, nums, dp) + nums[idx];

        // Not Take
        int notTake = helper(idx - 1, nums, dp);

        return dp[idx] = max(take, notTake);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        return helper(n - 1, nums, dp);
    }
};



// ============================================================
// Approach 3: Tabulation (Bottom-Up DP)
// TC: O(n)
// SC: O(n) - DP array
//
// Index Direction:
// Memoization:
// dp[idx] depends on dp[idx - 1] and dp[idx - 2]
//
// Therefore, in Tabulation:
// We move forward from idx = 0 to n - 1
// ============================================================

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);

        dp[0] = nums[0];

        for(int idx = 1; idx < n; idx++) {

            // Take
            int take = nums[idx];
            if(idx > 1)
                take += dp[idx - 2];

            // Not Take
            int notTake = dp[idx - 1];

            dp[idx] = max(take, notTake);
        }

        return dp[n - 1];
    }
};



// ============================================================
// Approach 4: Space Optimized DP
// TC: O(n)
// SC: O(1)
// ============================================================

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        int prev = nums[0];
        int prev2 = 0;

        for(int idx = 1; idx < n; idx++) {

            // Take
            int take = nums[idx];
            if(idx > 1)
                take += prev2;

            // Not Take
            int notTake = prev;

            int curr = max(take, notTake);

            prev2 = prev;
            prev = curr;
        }

        return prev;
    }
};
