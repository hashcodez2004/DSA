class Solution {
public:
    void markZeroes(int i, int j, vector<vector<char>>& grid, int m, int n){
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j]='0';

        int r[]={1,0,-1,0};
        int c[]={0,1,0,-1};

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow=row+r[i];
                int ncol=col+c[i];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]=='1'){
                    q.push({nrow,ncol});
                    grid[nrow][ncol]='0';
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    markZeroes(i,j,grid,m,n);
                }
            }
        }

        return cnt;
    }
};