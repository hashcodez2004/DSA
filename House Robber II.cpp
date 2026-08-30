// ============================================================
// Approach 1: Recursion (Brute Force)
// TC: O(2^n)
// SC: O(n) - Recursion stack
// ============================================================

class Solution {
private:
    int helper(int idx, int start, vector<int> &nums) {
        if(idx == start)
            return nums[idx];

        if(idx < start)
            return 0;

        // Take
        int take = helper(idx - 2, start, nums) + nums[idx];

        // Not Take
        int notTake = helper(idx - 1, start, nums);

        return max(take, notTake);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        // Exclude last house
        int first = helper(n - 2, 0, nums);

        // Exclude first house
        int second = helper(n - 1, 1, nums);

        return max(first, second);
    }
};



// ============================================================
// Approach 2: Memoization (Top-Down DP)
// TC: O(n)
// SC: O(n) - DP array + Recursion stack
// ============================================================

class Solution {
private:
    int helper(int idx, int start, vector<int> &nums, vector<int> &dp) {
        if(idx == start)
            return nums[idx];

        if(idx < start)
            return 0;

        if(dp[idx] != -1)
            return dp[idx];

        // Take
        int take = helper(idx - 2, start, nums, dp) + nums[idx];

        // Not Take
        int notTake = helper(idx - 1, start, nums, dp);

        return dp[idx] = max(take, notTake);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        // Exclude last house
        vector<int> dp1(n, -1);
        int first = helper(n - 2, 0, nums, dp1);

        // Exclude first house
        vector<int> dp2(n, -1);
        int second = helper(n - 1, 1, nums, dp2);

        return max(first, second);
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
// We move forward from start to end
// ============================================================

class Solution {
private:
    int houseRobber(int start, int end, vector<int> &nums) {
        vector<int> dp(end - start + 1, 0);

        dp[0] = nums[start];

        for(int idx = start + 1; idx <= end; idx++) {
            int dpIdx = idx - start;

            // Take
            int take = nums[idx];
            if(dpIdx > 1)
                take += dp[dpIdx - 2];

            // Not Take
            int notTake = dp[dpIdx - 1];

            dp[dpIdx] = max(take, notTake);
        }

        return dp[end - start];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        // Exclude last house
        int first = houseRobber(0, n - 2, nums);

        // Exclude first house
        int second = houseRobber(1, n - 1, nums);

        return max(first, second);
    }
};



// ============================================================
// Approach 4: Space Optimized DP
// TC: O(n)
// SC: O(1)
// ============================================================

class Solution {
private:
    int houseRobber(int start, int end, vector<int> &nums) {
        int prev = nums[start];
        int prev2 = 0;

        for(int idx = start + 1; idx <= end; idx++) {

            // Take
            int take = nums[idx];
            if(idx > start + 1)
                take += prev2;

            // Not Take
            int notTake = prev;

            int curr = max(take, notTake);

            prev2 = prev;
            prev = curr;
        }

        return prev;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        // Exclude last house
        int first = houseRobber(0, n - 2, nums);

        // Exclude first house
        int second = houseRobber(1, n - 1, nums);

        return max(first, second);
    }
};
