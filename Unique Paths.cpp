// ============================================================
// Approach 1: Recursion (Brute Force)
// TC: O(2^(m+n))
// SC: O(m+n) - Recursion stack
// ============================================================

class Solution {
private:
    int helper(int i, int j){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;

        int up = helper(i-1,j);
        int left = helper(i,j-1);

        return up + left;
    }

public:
    int uniquePaths(int m, int n) {
        return helper(m-1,n-1);
    }
};



// ============================================================
// Approach 2: Memoization (Top-Down DP)
// TC: O(m * n)
// SC: O(m*n + m+n) - DP array + Recursion stack
// ============================================================

class Solution {
private:
    int helper(int i, int j, vector<vector<int>> &dp){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int up = helper(i-1,j,dp);
        int left = helper(i,j-1,dp);

        return dp[i][j] = up + left;
    }

public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return helper(m-1,n-1,dp);
    }
};



// ============================================================
// Approach 3: Tabulation (Bottom-Up DP)
// TC: O(m * n)
// SC: O(m * n)
//
// Index Direction:
// Memoization:
// dp[i][j] depends on dp[i-1][j] and dp[i][j-1]
//
// Therefore, in Tabulation:
// We move forward from (0,0) to (m-1,n-1)
// ============================================================

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,0));
        dp[0][0] = 1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;

                int up=0, left=0;
                if(i!=0) up = dp[i-1][j];
                if(j!=0) left = dp[i][j-1];

                dp[i][j] = up + left;
            }
        }

        return dp[m-1][n-1];
    }
};



// ============================================================
// Approach 4: Space Optimized DP
// TC: O(m * n)
// SC: O(2 * n) = O(n)
//
// Each dp[i][j] depends only on:
// - dp[i-1][j] -> Previous row
// - dp[i][j-1] -> Current row
//
// Therefore, we only store:
// - prev -> Previous row
// - curr -> Current row
// ============================================================

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n,0);

        for(int i=0;i<m;i++){
            vector<int> curr(n,0);

            for(int j=0;j<n;j++){
                if(i==0 && j==0) curr[j]=1;
                else{
                    int up = prev[j];
                    int left=0;

                    if(j!=0) left = curr[j-1];

                    curr[j] = up + left;
                }
            }

            prev = curr;
        }

        return prev[n-1];
    }
};
