// 1. Recursion
// TC: O(3^m x 3^m)
//     m = number of rows
//     3 choices for robot 1 × 3 choices for robot 2
// SC: O(m)
//     Recursion Stack = O(m)

class Solution {
private:
    int helper(int row, int col1, int col2, vector<vector<int>>& grid){
        if(col1<0 || col1>grid[0].size()-1 || col2<0 || col2>grid[0].size()-1) return -1e9;

        if(row==grid.size()-1){
            if(col1==col2) return grid[row][col1];
            else return grid[row][col1] + grid[row][col2];
        }

        int maxi=INT_MIN;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(col1==col2) maxi = max(maxi, grid[row][col1] + helper(row+1,col1+i,col2+j,grid));
                else maxi = max(maxi, grid[row][col1] + grid[row][col2] + helper(row+1,col1+i,col2+j,grid));
            }
        }

        return maxi;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        return helper(0,0,n-1,grid);
    }
};


// 2. Memoization
// TC: O(m × n × n x 9)
//     m = number of rows
//     n = number of columns for col1
//     n = number of columns for col2
//     9 transitions per state = constant
// SC: O(m × n × n)
//     DP Space = O(m × n × n)
//     Recursion Stack = O(m)
//     Total = O(m × n × n)

class Solution {
private:
    int helper(int row, int col1, int col2, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp){
        if(col1<0 || col1>grid[0].size()-1 || col2<0 || col2>grid[0].size()-1) return -1e9;

        if(row==grid.size()-1){
            if(col1==col2) return grid[row][col1];
            else return grid[row][col1] + grid[row][col2];
        }

        if(dp[row][col1][col2] != -1) return dp[row][col1][col2];

        int maxi=INT_MIN;
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                if(col1==col2) maxi = max(maxi, grid[row][col1] + helper(row+1,col1+i,col2+j,grid,dp));
                else maxi = max(maxi, grid[row][col1] + grid[row][col2] + helper(row+1,col1+i,col2+j,grid,dp));
            }
        }

        return dp[row][col1][col2] = maxi;
    }

public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));

        return helper(0,0,n-1,grid,dp);
    }
};


// 3. Tabulation
// TC: O(m × n × n x 9)
//     m = number of rows
//     n = number of columns for col1
//     n = number of columns for col2
//     9 transitions per state = constant
// SC: O(m × n × n)
//     DP Space = O(m × n × n)
//     Stack Space = O(1)
//     Total = O(m × n × n)

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));

        //Base Case
        for(int col1=0;col1<n;col1++){
            for(int col2=0;col2<n;col2++){
                if(col1==col2) dp[m-1][col1][col2] = grid[m-1][col1];
                else dp[m-1][col1][col2] = grid[m-1][col1] + grid[m-1][col2];
            }
        }
        
        for(int row=m-2;row>=0;row--){
            for(int col1=0;col1<n;col1++){
                for(int col2=0;col2<n;col2++){

                    int maxi=INT_MIN;
                    for(int i=-1;i<=1;i++){
                        for(int j=-1;j<=1;j++){
                            if(col1+i<0 || col1+i>grid[0].size()-1 || col2+j<0 || col2+j>grid[0].size()-1) continue;

                            if(col1==col2) maxi = max(maxi, grid[row][col1] + dp[row+1][col1+i][col2+j]);
                            else maxi = max(maxi, grid[row][col1] + grid[row][col2] + dp[row+1][col1+i][col2+j]);
                        }
                    }

                    dp[row][col1][col2] = maxi;
                }
            }
        }

        return dp[0][0][n-1];
    }
};


// 4. Space Optimization
// TC: O(m × n × n x 9)
//     m = number of rows
//     n = number of columns for col1
//     n = number of columns for col2
//     9 transitions per state = constant
// SC: O(n × n)
//     next Space = O(n × n)
//     curr Space = O(n × n)
//     Stack Space = O(1)
//     Total = O(n × n)

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> next(n, vector<int>(n, -1));

        //Base Case
        for(int col1=0;col1<n;col1++){
            for(int col2=0;col2<n;col2++){
                if(col1==col2) next[col1][col2] = grid[m-1][col1];
                else next[col1][col2] = grid[m-1][col1] + grid[m-1][col2];
            }
        }
        
        for(int row=m-2;row>=0;row--){
            vector<vector<int>> curr(n, vector<int>(n));

            for(int col1=0;col1<n;col1++){
                for(int col2=0;col2<n;col2++){

                    int maxi=INT_MIN;
                    for(int i=-1;i<=1;i++){
                        for(int j=-1;j<=1;j++){
                            if(col1+i<0 || col1+i>grid[0].size()-1 || col2+j<0 || col2+j>grid[0].size()-1) continue;

                            if(col1==col2) maxi = max(maxi, grid[row][col1] + next[col1+i][col2+j]);
                            else maxi = max(maxi, grid[row][col1] + grid[row][col2] + next[col1+i][col2+j]);
                        }
                    }

                    curr[col1][col2] = maxi;
                }
            }

            next = curr;
        }

        return next[0][n-1];
    }
};
