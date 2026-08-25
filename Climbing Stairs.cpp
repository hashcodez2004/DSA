// ============================================================
// Approach 1: Recursion (Brute Force)
// TC: O(2^n)
// SC: O(n) - Recursion stack
// ============================================================

class Solution {
private:
    int helper(int n) {
        if(n == 0 || n == 1)
            return 1;

        return helper(n - 1) + helper(n - 2);
    }

public:
    int climbStairs(int n) {
        return helper(n);
    }
};



// ============================================================
// Approach 2: Memoization (Top-Down DP)
// TC: O(n)
// SC: O(n) - DP array + Recursion stack
// ============================================================

class Solution {
private:
    int helper(int n, vector<int> &dp) {
        if(n == 0 || n == 1)
            return 1;

        if(dp[n] != -1)
            return dp[n];

        return dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
    }

public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return helper(n, dp);
    }
};



// ============================================================
// Approach 3: Tabulation (Bottom-Up DP)
// TC: O(n)
// SC: O(n) - DP array
// ============================================================

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);

        // Base cases
        dp[0] = 1;
        dp[1] = 1;

        // Build the table from smaller states to larger states
        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};



// ============================================================
// Approach 4: Space Optimized DP
// TC: O(n)
// SC: O(1)
// ============================================================

class Solution {
public:
    int climbStairs(int n) {
        int prev2 = 1; // dp[0]
        int prev1 = 1; // dp[1]

        for(int i = 2; i <= n; i++) {
            int curr = prev1 + prev2;

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
