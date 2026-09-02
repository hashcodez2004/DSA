// ============================================================
// Approach 1: Recursion (Brute Force)
// TC: O(2^(m+n))
// SC: O(m+n) - Recursion stack
// ============================================================

class Solution {
private:
    int helper(int i, int j, vector<vector<int>>& obstacleGrid){
        if(i<0 || j<0) return 0;
        if(obstacleGrid[i][j]==1) return 0;
        if(i==0 && j==0) return 1;

        int up = helper(i-1,j,obstacleGrid);
        int left = helper(i,j-1,obstacleGrid);

        return up + left;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        return helper(m-1,n-1,obstacleGrid);
    }
};



// ============================================================
// Approach 2: Memoization (Top-Down DP)
// TC: O(m * n)
// SC: O(m * n + m + n) - DP array + Recursion stack
// ============================================================

class Solution {
private:
    int helper(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;
        if(obstacleGrid[i][j]==1) return 0;
        if(i==0 && j==0) return 1;

        if(dp[i][j]!=-1) return dp[i][j];

        int up = helper(i-1,j,obstacleGrid,dp);
        int left = helper(i,j-1,obstacleGrid,dp);

        return dp[i][j] = up + left;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n,-1));

        return helper(m-1,n-1,obstacleGrid,dp);
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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1) return 0;

        vector<vector<int>> dp(m, vector<int>(n,0));
        dp[0][0] = 1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;

                if(obstacleGrid[i][j]==1) {
                    dp[i][j] = 0;
                    continue;
                }

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
// Each cell depends only on:
// - dp[i-1][j] -> Previous row
// - dp[i][j-1] -> Current row
//
// Therefore, we only store:
// - prev -> Previous row
// - curr -> Current row
// ============================================================

class Solution {
    public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1) return 0;

        vector<int> prev(n,0);

        for(int i=0;i<m;i++){
            vector<int> curr(n,0);

            for(int j=0;j<n;j++){
                if(i==0 && j==0) curr[j]=1;
                else if(obstacleGrid[i][j]==1) continue;
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
