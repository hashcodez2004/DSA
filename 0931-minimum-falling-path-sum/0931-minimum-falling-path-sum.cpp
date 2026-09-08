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
            ans = min(ans, prev[i]);
        }

        return ans;
    }
};