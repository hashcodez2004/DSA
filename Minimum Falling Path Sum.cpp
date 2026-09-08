// 1. Recursion
// TC: O(n * 3^n)
// SC: O(n)

class Solution {
private:
    int helper(int row, int col, vector<vector<int>>& matrix){
        if(col<0 || col==matrix.size()) return 1e9;
        if(row==0) return matrix[0][col];

        int upLeft = matrix[row][col] + helper(row-1,col-1,matrix);
        int up = matrix[row][col] + helper(row-1,col,matrix);
        int upRight = matrix[row][col] + helper(row-1,col+1,matrix);
        
        return min({upLeft,up,upRight});
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            ans = min(ans,helper(n-1,i,matrix));
        }

        return ans;
    }
};


// 2. Memoization
// TC: O(n^2)
// SC: O(n^2 + n)

class Solution {
private:
    int helper(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp){
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
            ans = min(ans,helper(n-1,i,matrix,dp));
        }

        return ans;
    }
};


// 3. Tabulation
// TC: O(n^2)
// SC: O(n^2)

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n,1e9));
        dp[0] = matrix[0];

        for(int row=1;row<n;row++){
            for(int col=0;col<n;col++){
                int upLeft = 1e9;
                if(col!=0) upLeft = matrix[row][col] + dp[row-1][col-1];

                int up = matrix[row][col] + dp[row-1][col];

                int upRight = 1e9;
                if(col!=n-1) upRight = matrix[row][col] + dp[row-1][col+1];
                
                dp[row][col] = min({upLeft,up,upRight});
            }
        }

        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            ans = min(ans,dp[n-1][i]);
        }

        return ans;
    }
};


// 4. Space Optimization
// TC: O(n^2)
// SC: O(n)

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<int> prev = matrix[0];

        for(int row=1;row<n;row++){
            vector<int> curr(n);

            for(int col=0;col<n;col++){
                int upLeft = 1e9;
                if(col!=0) upLeft = matrix[row][col] + prev[col-1];

                int up = matrix[row][col] + prev[col];

                int upRight = 1e9;
                if(col!=n-1) upRight = matrix[row][col] + prev[col+1];
                
                curr[col] = min({upLeft,up,upRight});
            }

            prev = curr;
        }

        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            ans = min(ans,prev[i]);
        }

        return ans;
    }
};
