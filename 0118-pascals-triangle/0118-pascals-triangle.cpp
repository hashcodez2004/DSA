class Solution {
private:
    vector<int> getRow(int row) {
        vector<int> ans;
        ans.push_back(1);
        long long temp=1;
        for(int col=1;col<row;col++){
            temp=temp*(row-col);
            temp=temp/col;
            ans.push_back(temp);
        }
        return ans;
    }

public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(getRow(i));
        }    
        return ans;
    }
};