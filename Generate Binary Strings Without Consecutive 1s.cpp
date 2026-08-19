// ============================================================
// Approach 1: Recursion (Brute Force)
// Time Complexity: O(2^n) [tighter bound: O(phi^n)]
// Space Complexity: O(n) - recursion stack
// ============================================================

class Solution {
  private:
    int helper(int len, bool curr, int n) {
        if(len == n) return 1;
        
        if(curr)
            return helper(len + 1, 0, n);
        else
            return helper(len + 1, 0, n) + helper(len + 1, 1, n);
    }
    
  public:
    int countStrings(int n) {
        // Take - Not Take approach
        // 0 -> both 0 and 1
        // 1 -> only 0
        return helper(0, 0, n);
    }
};



// ============================================================
// Approach 2: Memoization (Top-Down DP)
// Time Complexity: O(n)
// Space Complexity: O(n) - DP table + O(n) recursion stack
// ============================================================

class Solution {
  private:
    int helper(int len, bool curr, int n, vector<vector<int>> &dp) {
        if(len == n) return 1;
        
        if(dp[len][curr] != -1)
            return dp[len][curr];
        
        if(curr)
            return dp[len][curr] = helper(len + 1, 0, n, dp);
        else
            return dp[len][curr] =
                helper(len + 1, 0, n, dp) +
                helper(len + 1, 1, n, dp);
    }
    
  public:
    int countStrings(int n) {
        // Take - Not Take approach
        // 0 -> both 0 and 1
        // 1 -> only 0
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        
        return helper(0, 0, n, dp);
    }
};



// ============================================================
// Approach 3: Tabulation (Bottom-Up DP)
// Time Complexity: O(n)
// Space Complexity: O(n) - DP table
// ============================================================

class Solution {
  public:
    int countStrings(int n) {
        // Take - Not Take approach
        // 0 -> both 0 and 1
        // 1 -> only 0
        
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        
        // Base case initialization
        dp[n][0] = 1;
        dp[n][1] = 1;
        
        // len depends on len + 1, so we fill backwards
        for(int len = n - 1; len >= 0; len--) {
            dp[len][1] = dp[len + 1][0];
            dp[len][0] = dp[len + 1][0] + dp[len + 1][1];
        }
        
        return dp[0][0];
    }
};
