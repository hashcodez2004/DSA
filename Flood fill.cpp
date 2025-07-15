#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int initialColor = image[sr][sc];

        vector<vector<int>> res = image;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        res[sr][sc] = color;

        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, -1, 1};

        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                   res[nrow][ncol] == initialColor && res[nrow][ncol] != color) {
                    res[nrow][ncol] = color;
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
        vector<vector<int>> image(m, vector<int>(n));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                cin >> image[i][j];

        int sr, sc, color;
        cin >> sr >> sc >> color;

        Solution ob;
        vector<vector<int>> ans = ob.floodFill(image, sr, sc, color);

        for(auto row : ans) {
            for(auto val : row)
                cout << val << " ";
            cout << endl;
        }
    }
    return 0;
}

/*
Time Complexity: O(N * M), where N = number of rows, M = number of columns.
We might visit every cell in the worst case if all connected pixels have the same color.

Space Complexity: O(N * M), for the queue used in BFS. In worst case, the queue can store all the cells.
*/
