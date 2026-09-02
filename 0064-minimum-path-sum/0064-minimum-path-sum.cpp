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