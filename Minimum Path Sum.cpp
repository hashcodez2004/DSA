// ============================================================
// Approach 1: Recursion (Brute Force)
// TC: O(2^(m+n))
// SC: O(m+n) - Recursion stack
// ============================================================

class Solution {
private:
    int helper(int i, int j, vector<vector<int>>& grid){
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return 1e9;

        int up = grid[i][j] + helper(i-1,j,grid);
        int left = grid[i][j] + helper(i,j-1,grid);

        return min(up,left);
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        return helper(m-1,n-1,grid);
    }
};



// ============================================================
// Approach 2: Memoization (Top-Down DP)
// TC: O(m * n)
// SC: O(m * n + m + n) - DP array + Recursion stack
// ============================================================

class Solution {
private:
    int helper(int i, int j, vector<vector<int>>& grid, vector<vector<int>> &dp){
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return 1e9;

        if(dp[i][j]!=-1) return dp[i][j];

        int up = grid[i][j] + helper(i-1,j,grid,dp);
        int left = grid[i][j] + helper(i,j-1,grid,dp);

        return dp[i][j] = min(up,left);
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n,-1));

        return helper(m-1,n-1,grid,dp);
    }
};



// ============================================================
// Approach 3: Tabulation (Bottom-Up DP)
// TC: O(m * n)
// SC: O(m * n)
//
// Index Shifting:
// grid[i-1][j-1] ↔ dp[i][j]
//
// Artificial Boundaries:
// dp[i][0] = INF
// dp[0][j] = INF
//
// Since we are finding a minimum, invalid paths must have
// a very large value so they are never chosen.
// ============================================================

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m+1, vector<int>(n+1,0));

        for(int i=0;i<=m;i++) dp[i][0]=1e9;
        for(int i=0;i<=n;i++) dp[0][i]=1e9;

        dp[1][1]=grid[0][0];

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(i==1 && j==1) continue;

                int up = grid[i-1][j-1] + dp[i-1][j];
                int left = grid[i-1][j-1] + dp[i][j-1];

                dp[i][j] = min(up,left);
            }
        }

        return dp[m][n];
    }
};



// ============================================================
// Approach 4: Space Optimized DP
// TC: O(m * n)
// SC: O(2 * n) = O(n)
//
// Each cell depends only on:
// - dp[i-1][j] -> Previous row
// - dp[i][j-1] -> Current row
//
// Therefore, we only store:
// - prev -> Previous row
// - curr -> Current row
//
// Index Shifting:
// grid[i-1][j-1] ↔ curr[j]
//
// Artificial Boundaries:
// prev[j] = INF
// curr[0] = INF
// ============================================================

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> prev(n+1,1e9);

        for(int i=1;i<=m;i++){

            vector<int> curr(n+1,1e9);
            for(int j=1;j<=n;j++){
                if(i==1 && j==1){
                    curr[1]=grid[0][0];
                    continue;
                }

                int up = grid[i-1][j-1] + prev[j];
                int left = grid[i-1][j-1] + curr[j-1];

                curr[j] = min(up,left);
            }

            prev=curr;
        }

        return prev[n];
    }
};
