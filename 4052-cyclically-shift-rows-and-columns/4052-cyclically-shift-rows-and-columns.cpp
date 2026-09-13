class Solution {
private:
    void rowShifting(vector<int> &row, int n){
        n = n % row.size();
        reverse(row.begin(),row.begin()+n);
        reverse(row.begin()+n,row.end());
        reverse(row.begin(),row.end());
    }
    
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {

        for(int i=0;i<n;i++){
            rowShifting(grid[i], rowShift[i]);
        }

        for(int j=0;j<n;j++){

            vector<int> col;
            for(int i=0;i<n;i++){
                col.push_back(grid[i][j]);
            }

            rowShifting(col, colShift[j]);

            for(int i=0;i<n;i++){
                grid[i][j] = col[i];
            }
        }

        return grid;
    }
};