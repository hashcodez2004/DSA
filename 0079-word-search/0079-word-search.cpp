class Solution {
private:
    bool helper(int idx, int i, int j, string& word, vector<vector<char>>& board, vector<vector<int>>& vis, int row[], int col[], int& m, int& n){
        if(idx==word.size()) return true;

        for(int x=0;x<4;x++){
            int nrow = i+row[x];
            int ncol = j+col[x];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && board[nrow][ncol]==word[idx]){
                vis[nrow][ncol] = 1;
                if(helper(idx+1,nrow,ncol,word,board,vis,row,col,m,n)) return true;
                vis[nrow][ncol] = 0;
            }
        }
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        //visited matrix
        vector<vector<int>> vis(m, vector<int>(n, 0));

        //neighbour arrays
        int row[] = {1,0,-1,0};
        int col[] = {0,1,0,-1};

        //start recursive call from every cell having first letter same
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                if(board[i][j]==word[0]){
                    vis[i][j]=1;
                    if(helper(1,i,j,word,board,vis,row,col,m,n)) return true;
                    vis[i][j]=0;
                }
        }
        return false;
    }
};