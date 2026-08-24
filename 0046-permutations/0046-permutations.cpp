class Solution {
private:
    void helper(int idx, vector<int> &curr, vector<int> &vis, vector<vector<int>> &ans, vector<int>& nums){
        if(idx==nums.size()){
            if(curr.size()==nums.size()) ans.push_back(curr);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(vis[i]) continue;

            vis[i] = 1;
            curr.push_back(nums[i]);

            helper(idx+1,curr,vis,ans,nums);

            curr.pop_back();
            vis[i] = 0;
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<int> vis(nums.size(),0);
        helper(0,curr,vis,ans,nums);
        return ans;
    }
};