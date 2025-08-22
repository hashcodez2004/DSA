class Solution {
private:
    void helper(int idx, int sum, int k, vector<int>& v, vector<vector<int>>& ans){
        if(k==0){
            if(sum==0) ans.push_back(v);
            return;
        }
        if(sum<0 || idx>9) return;

        // notTake
        helper(idx+1,sum,k,v,ans);

        // take
        v.push_back(idx);
        helper(idx+1,sum-idx,k-1,v,ans);
        v.pop_back();
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(1,n,k,v,ans);
        return ans;
    }
};
