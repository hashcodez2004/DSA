class Solution {
private:
    void helper(int idx, int sum, int k, vector<int>& v, int n, vector<vector<int>>& ans, vector<int>& nums){
        if(k==0){
            if(sum==n)
            ans.push_back(v);
            return;
        }
        if(sum>n || idx==nums.size()) return;
        //notTake
        helper(idx+1,sum,k,v,n,ans,nums);
        //Take
        v.push_back(nums[idx]);
        helper(idx+1,sum+nums[idx],k-1,v,n,ans,nums);
        v.pop_back();
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums(9);
        for(int i=0;i<9;i++) nums[i]=i+1;
        vector<vector<int>> ans;
        vector<int> v;
        helper(0,0,k,v,n,ans,nums);
        return ans;
    }
};