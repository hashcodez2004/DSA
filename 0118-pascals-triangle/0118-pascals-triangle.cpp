class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int i=2; i<=numRows; i++){
            int prevIdx=i-2; //ans[i-1]
            //first and last ele of this row will always be 1 i.e 0 and i-1;
            vector<int> curr(i);
            curr[0]=curr[i-1]=1;
            for(int j=1; j<i-1; j++){
                curr[j] = ans[prevIdx][j-1] + ans[prevIdx][j];
            }
            ans.push_back(curr);
        }
        return ans;
    }
};