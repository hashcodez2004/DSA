// ============================================================
// Approach 1: Recursion (Brute Force)
// TC: O(2^n)
// SC: O(n) - Recursion stack
// ============================================================

class Solution {
private:
    int helper(int idx, vector<int> &height) {
        if(idx == 0) return 0;

        int left = helper(idx - 1, height)
                 + abs(height[idx] - height[idx - 1]);

        int right = 1e9;
        if(idx > 1)
            right = helper(idx - 2, height)
                  + abs(height[idx] - height[idx - 2]);

        return min(left, right);
    }

public:
    int minCost(vector<int>& height) {
        int n = height.size();

        return helper(n - 1, height);
    }
};



// ============================================================
// Approach 2: Memoization (Top-Down DP)
// TC: O(n)
// SC: O(n) - DP array + Recursion stack
// ============================================================

class Solution {
private:
    int helper(int idx, vector<int> &height, vector<int> &dp) {
        if(idx == 0) return 0;

        if(dp[idx] != -1)
            return dp[idx];

        int left = helper(idx - 1, height, dp)
                 + abs(height[idx] - height[idx - 1]);

        int right = 1e9;
        if(idx > 1)
            right = helper(idx - 2, height, dp)
                  + abs(height[idx] - height[idx - 2]);

        return dp[idx] = min(left, right);
    }

public:
    int minCost(vector<int>& height) {
        int n = height.size();

        vector<int> dp(n, -1);

        return helper(n - 1, height, dp);
    }
};



// ============================================================
// Approach 3: Tabulation (Bottom-Up DP)
// TC: O(n)
// SC: O(n) - DP array
// ============================================================

class Solution {
public:
    int minCost(vector<int>& height) {
        int n = height.size();

        vector<int> dp(n, 0);

        for(int i = 1; i < n; i++) {

            int left = dp[i - 1]
                     + abs(height[i] - height[i - 1]);

            int right = 1e9;
            if(i > 1)
                right = dp[i - 2]
                      + abs(height[i] - height[i - 2]);

            dp[i] = min(left, right);
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
    int minCost(vector<int>& height) {
        int n = height.size();

        int prev2 = 0; // dp[i-2]
        int prev1 = 0; // dp[i-1]

        for(int i = 1; i < n; i++) {

            int left = prev1
                     + abs(height[i] - height[i - 1]);

            int right = 1e9;
            if(i > 1)
                right = prev2
                      + abs(height[i] - height[i - 2]);

            int curr = min(left, right);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
