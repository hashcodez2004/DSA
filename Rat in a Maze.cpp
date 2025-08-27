#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void helper(int i, int j, string& s, int n, vector<string>& ans, 
                vector<vector<int>>& maze, vector<int>& row, 
                vector<int>& col, string& dir){
        if(i==n-1 && j==n-1){
            ans.push_back(s);
            return;
        }
        
        for(int x=0;x<4;x++){
            int nrow=i+row[x];
            int ncol=j+col[x];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && maze[nrow][ncol]==1){
                maze[i][j]=0;
                s+=dir[x];
                helper(nrow,ncol,s,n,ans,maze,row,col,dir);
                maze[i][j]=1;
                s.pop_back();
            }
        }
    }
    
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n=maze.size();
        vector<string> ans;
        string s="";
        vector<int> row = {1,0,0,-1};
        vector<int> col = {0,-1,1,0};
        string dir = "DLRU";
        helper(0,0,s,n,ans,maze,row,col,dir);
        return ans;
    }
};


/*
==========================
⏳ TIME COMPLEXITY
==========================
Let N = size of maze (N x N grid)

1. Each recursive call explores at most 4 directions → branching factor = 4.
2. Each cell can be visited only once in a path (marked 0 when visited).
   So maximum path length = N^2 in worst case.
3. In the worst case (all 1's in maze), the recursion explores an exponential
   search tree with branching factor 4 and depth up to N^2.

   -> Worst-case complexity = O(4^(N^2))

4. However, in practice many branches are cut early (walls, visited cells).
5. Copying the path into ans:
   - Path length L <= 2N-2 (minimum moves from (0,0) to (N-1,N-1)).
   - Each push_back costs O(L).
   - Suppose there are S valid paths → total extra cost = O(S * N).

✅ Final TC = O(4^(N^2)) in worst case
              + O(S * N) for storing valid solutions.

==========================
💾 SPACE COMPLEXITY
==========================
1. Recursion depth:
   - At most N^2 (visiting all cells in one path).
   - So recursion stack = O(N^2).

2. Current path string `s`:
   - Max length = 2N-2 (when only Down + Right moves).
   - So O(N) space.

3. Maze is modified in place (no extra visited array).

4. Output storage:
   - ans stores all valid paths.
   - Each path takes O(N).
   - If there are S solutions → O(S * N) output space.

✅ Extra Space = O(N^2) (recursion + path string)
✅ Total Space (including output) = O(N^2 + S * N)
*/
