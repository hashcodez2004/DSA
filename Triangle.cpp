// ============================================================
// Approach 1: Recursion (Brute Force)
// TC: O(2^n)
// SC: O(n) - Recursion stack
// ============================================================

class Solution {
private:
    int helper(int row, int col, vector<vector<int>>& triangle){
        if(row == triangle.size()-1) return triangle[row][col];

        int down = helper(row+1,col,triangle);
        int diagonal = helper(row+1,col+1,triangle);

        return triangle[row][col] + min(down,diagonal);
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return helper(0,0,triangle);
    }
};



// ============================================================
// Approach 2: Memoization (Top-Down DP)
// TC: O(n^2)
// SC: O(n^2) - DP array + O(n) - Recursion stack
// ============================================================

class Solution {
private:
    int helper(int row, int col, vector<vector<int>>& triangle, vector<vector<int>> &dp){
        if(row == triangle.size()-1) return triangle[row][col];

        if(dp[row][col] != 1e9) return dp[row][col];

        int down = helper(row+1,col,triangle,dp);
        int diagonal = helper(row+1,col+1,triangle,dp);

        return dp[row][col] = triangle[row][col] + min(down,diagonal);
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,1e9));

        return helper(0,0,triangle,dp);
    }
};



// ============================================================
// Approach 3: Tabulation (Bottom-Up DP)
// TC: O(n^2)
// SC: O(n^2)
//
// Index Direction:
// Memoization:
// dp[row][col] depends on
// dp[row + 1][col] and dp[row + 1][col + 1]
//
// Therefore, in Tabulation:
// We move from the second-last row to the top.
// ============================================================

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,1e9));

        dp[n-1] = triangle[n-1];

        for(int row=n-2;row>=0;row--){
            for(int col=row;col>=0;col--){
                int down = dp[row+1][col];
                int diagonal = dp[row+1][col+1];

                dp[row][col] = triangle[row][col] + min(down,diagonal);
            }
        }

        return dp[0][0];
    }
};



// ============================================================
// Approach 4: Space Optimized DP
// TC: O(n^2)
// SC: O(2n) = O(n)
//
// Each cell depends only on:
// - The cell directly below
// - The cell diagonally below
//
// Therefore, we only store:
// - next -> The next row
// - curr -> The current row
// ============================================================

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==1) return triangle[0][0];

        int n = triangle.size();
        vector<int> next = triangle[n-1];

        for(int row=n-2;row>=0;row--){

            vector<int> curr(row+1,0);
            for(int col=row;col>=0;col--){
                int down = next[col];
                int diagonal = next[col+1];

                curr[col] = triangle[row][col] + min(down,diagonal);
            }

            next=curr;
        }

        return next[0];
    }
};
