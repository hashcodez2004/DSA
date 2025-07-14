#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<vector<int>> q;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == 2)
                    q.push({i, j, 0});

        int row[] = {-1, 0, 1, 0};
        int col[] = {0, 1, 0, -1};
        int time = 0;

        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int r = it[0];
            int c = it[1];
            int t = it[2];
            time = max(time, t);

            for(int i = 0; i < 4; i++) {
                int nr = r + row[i];
                int nc = c + col[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 1) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc, t + 1});
                }
            }
        }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == 1 && vis[i][j] == 0)
                    return -1;

        return time;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> grid[i][j];
        Solution ob;
        cout << ob.orangesRotting(grid) << endl;
    }
    return 0;
}

/*
Time Complexity: O ( n x n ) x 4    

Reason: Worst-case - We will be making each fresh orange rotten in the grid and for each rotten orange will check in 4 directions

Space Complexity: O ( n x n )

Reason: worst-case -  If all oranges are Rotten, we will end up pushing all rotten oranges into the Queue data structure
*/
