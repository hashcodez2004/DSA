class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0) return {};
        
        vector<vector<int>> ans;
        ans.push_back({1});
        
        for(int i = 2; i <= numRows; i++){
            vector<int> curr(i);
            curr[0] = curr[i-1] = 1;
            
            for(int j = 1; j < i-1; j++){
                curr[j] = ans[i-2][j-1] + ans[i-2][j];
            }
            
            ans.push_back(curr);
        }
        
        return ans;
    }
};