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