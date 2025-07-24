#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++) {
            if(board[0][i] == 'O') q.push({0, i});
            if(board[m-1][i] == 'O') q.push({m-1, i});
        }

        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O') q.push({i, 0});
            if(board[i][n-1] == 'O') q.push({i, n-1});
        }

        int delRow[] = {0, 0, 1, -1};
        int delCol[] = {1, -1, 0, 0};

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            vis[row][col] = 1;

            for(int i = 0; i < 4; i++) {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n 
                   && board[nRow][nCol] == 'O' && vis[nRow][nCol] == 0) {
                    vis[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(vis[i][j] == 0 && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int m, n;
        cin >> m >> n;
        vector<vector<char>> board(m, vector<char>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cin >> board[i][j];
            }
        }

        Solution ob;
        ob.solve(board);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}



/*
Time Complexity: O(N*M)
  - O(N + M) for pushing boundary 'O's
  - O(N*M) for BFS traversal
  - O(N*M) for final grid scan

Space Complexity: O(N*M)
  - O(N*M) for visited matrix
  - O(N*M) for queue
*/