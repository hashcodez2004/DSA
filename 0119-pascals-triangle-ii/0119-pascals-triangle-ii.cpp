class Solution {
public:
    vector<int> getRow(int row) {
        row=row+1; //did this because of 0 indexed row
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
};