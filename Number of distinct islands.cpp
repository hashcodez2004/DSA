class Solution {
  private:
    void bfs(int row, int col, set<vector<pair<int,int>>>& st, vector<vector<int>>& vis, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        
        //queue
        queue<pair<int,int>> q;
        
        q.push({row,col});
        vis[row][col]=1;
        
        //checking neighbours
        int dRow[] = {1,0,-1,0};
        int dCol[] = {0,1,0,-1};
        
        //store island's coordinates
        vector<pair<int,int>> island;
        
        //bfs traversal
        while(!q.empty()){
            auto it = q.front();
            int currRow = it.first;
            int currCol = it.second;
            q.pop();
            
            //put into island
            island.push_back({currRow-row,currCol-col});
            
            //check neighbours
            for(int i=0;i<4;i++){
                int nrow = currRow + dRow[i];
                int ncol = currCol + dCol[i];
                
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
        
        st.insert(island);
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        //MULTISOURCE BFS/DFS
        
        int m = grid.size();
        int n = grid[0].size();
        
        //set ds to store the unique islands
        set<vector<pair<int,int>>> st;
        
        //visited matrix
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        //check all components
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j])
                    //BFS/DFS
                    bfs(i,j,st,vis,grid);
            }
        }
        
        //return all unique islands
        return st.size();
    }
};


/*
TC: O(m*n*4 * log(m*n)) bfs traversal and set insertion

SC: O(m*n) visited matrix
    O(m*n) set to store islands
    O(m*n) queue

                                  DETAILED ANALYSIS
Time Complexity: O(m * n * 4)
→ O(m * n) for traversing the entire grid
→ For each unvisited land cell, we do a BFS that may visit every cell once
→ Each cell has 4 neighbors, but they are bounded and visited only once
→ Inserting a shape into the set takes O(k * log s), where k = shape size (at most m*n), and s = number of unique islands

Simplified Time Complexity: O(m * n * log(m * n))

Space Complexity:
→ O(m * n) for visited matrix
→ O(m * n) for queue in the worst case (entire grid is land)
→ O(m * n) for the set storing shape coordinates (worst case: all land cells are separate 1x1 islands)

Simplified Space Complexity: O(m * n)
*/