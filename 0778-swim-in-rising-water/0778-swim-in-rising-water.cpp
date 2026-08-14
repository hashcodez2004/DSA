class Solution {
private:
    bool dfs(int row, int col, int val, int m, int n, int delRow[], int delCol[], vector<vector<bool>> &vis, vector<vector<int>>& grid){
        if(row==m-1 && col==n-1) return true;
        
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]<=val && !vis[nrow][ncol]){
                if(dfs(nrow,ncol,val,m,n,delRow,delCol,vis,grid)) return true;
            }
        }

        return false;
    }

    bool possible(int val, vector<vector<int>>& grid){
        int m=grid.size();
        int n=grid[0].size();

        int delRow[] = {0,1,0,-1};
        int delCol[] = {1,0,-1,0};

        vector<vector<bool>> vis(m, vector<bool>(n,0));
        return dfs(0,0,val,m,n,delRow,delCol,vis,grid);
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int low=grid[0][0];
        int high=grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                high=max(high,grid[i][j]);
            }
        }

        while(low<=high){
            int mid = low + (high-low)/2;

            if(possible(mid,grid)) high=mid-1;
            else low=mid+1;
        }

        return low;     
    }
};


/*

TC: O(4 * n * n * log(n*n)) n*n => maxVal in the grid  ~ O(n^2 * logn)
SC: O(n*n) => vis matrix + O(n*n) => Auxillary space(Recursion stack) ~ O(n*n)

*/