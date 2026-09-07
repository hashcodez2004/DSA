class Solution {
private:
    int helper(int row, int col, vector<vector<int>>& matrix, vector<vector<int>> &dp){
        if(col<0 || col==matrix.size()) return 1e9;
        if(row==0) return matrix[0][col];

        if(dp[row][col] != 1e9) return dp[row][col];

        int upLeft = matrix[row][col] + helper(row-1,col-1,matrix,dp);
        int up = matrix[row][col] + helper(row-1,col,matrix,dp);
        int upRight = matrix[row][col] + helper(row-1,col+1,matrix,dp);
        
        return dp[row][col] = min({upLeft,up,upRight});
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n,1e9));

        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            ans = min(ans, helper(n-1, i, matrix, dp));
        }

        return ans;
    }
};