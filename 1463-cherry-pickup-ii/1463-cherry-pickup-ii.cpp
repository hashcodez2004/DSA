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