// ============================================================
// Approach 1: Recursion (Brute Force)
// TC: O(k^n)
// SC: O(n) - Recursion stack
// ============================================================

class Solution {
private:
    int helper(int idx, vector<int> &heights, int k) {
        if(idx == 0)
            return 0;

        int minCost = INT_MAX;

        for(int j = 1; j <= k; j++) {
            if(idx - j >= 0) {
                int jump = helper(idx - j, heights, k)
                         + abs(heights[idx] - heights[idx - j]);

                minCost = min(minCost, jump);
            }
        }

        return minCost;
    }

public:
    int frogJump(int n, vector<int>& heights, int k) {
        return helper(n - 1, heights, k);
    }
};



// ============================================================
// Approach 2: Memoization (Top-Down DP)
// TC: O(n * k)
// SC: O(n) - DP array + Recursion stack
// ============================================================

class Solution {
private:
    int helper(int idx, vector<int> &heights, int k, vector<int> &dp) {
        if(idx == 0)
            return 0;

        if(dp[idx] != -1)
            return dp[idx];

        int minCost = INT_MAX;

        for(int j = 1; j <= k; j++) {
            if(idx - j >= 0) {
                int jump = helper(idx - j, heights, k, dp)
                         + abs(heights[idx] - heights[idx - j]);

                minCost = min(minCost, jump);
            }
        }

        return dp[idx] = minCost;
    }

public:
    int frogJump(int n, vector<int>& heights, int k) {
        vector<int> dp(n, -1);

        return helper(n - 1, heights, k, dp);
    }
};



// ============================================================
// Approach 3: Tabulation (Bottom-Up DP)
// TC: O(n * k)
// SC: O(n) - DP array
// ============================================================

class Solution {
public:
    int frogJump(int n, vector<int>& heights, int k) {
        vector<int> dp(n, 0);

        // Base case
        dp[0] = 0;

        // Calculate minimum cost for each index
        for(int idx = 1; idx < n; idx++) {
            int minCost = INT_MAX;

            // Try all possible jumps from 1 to k
            for(int j = 1; j <= k; j++) {
                if(idx - j >= 0) {
                    int jump = dp[idx - j]
                             + abs(heights[idx] - heights[idx - j]);

                    minCost = min(minCost, jump);
                }
            }

            dp[idx] = minCost;
        }

        return dp[n - 1];
    }
};



// ============================================================
// Space Optimization
//
// Space optimization is NOT needed here.
//
// Unlike Frog Jump with only 1 or 2 possible jumps, the current
// state dp[idx] can depend on the previous k states:
//
// dp[idx] depends on:
// dp[idx-1], dp[idx-2], ..., dp[idx-k]
//
// Therefore, we need to retain up to k previous DP states.
// Since k can vary, reducing the DP array to O(1) is not possible
// in the general case without changing the approach.
//
// Tabulation: O(n) space
// ============================================================
