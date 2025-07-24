#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> res(m, vector<int>(n, -1));  // -1 indicates unvisited
        queue<pair<int, int>> q;

        // Initialize all water cells with height 0 and push to queue
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(isWater[i][j] == 1) {
                    res[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, -1, 1};

        // Multi-source BFS from all water cells
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int row = it.first;
            int col = it.second;

            for(int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && res[nrow][ncol] == -1) {
                    res[nrow][ncol] = res[row][col] + 1;
                    q.push({nrow, ncol});
                }
            }
        }

        return res;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> isWater(m, vector<int>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cin >> isWater[i][j];
            }
        }

        Solution ob;
        vector<vector<int>> ans = ob.highestPeak(isWater);
        for(auto row : ans) {
            for(auto val : row) cout << val << " ";
            cout << endl;
        }
    }
    return 0;
}

/*
Time Complexity: O(4 * m * n) 
Each cell is pushed and popped from the queue once, and we try all 4 directions per cell (constant time per cell).

Space Complexity: O(m * n)
For the result matrix + queue in the worst case.
*/
