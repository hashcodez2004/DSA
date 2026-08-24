// Approach 1: Backtracking using Visited Array
// TC: O(n * n!) — n! permutations, O(n) to copy each permutation
// SC: O(3 * n) — visited array + recursion stack + current permutation

class Solution {
private:
    void helper(int idx, vector<int> &curr, vector<int> &vis, vector<vector<int>> &ans, vector<int>& nums){
        if(idx==nums.size()){
            ans.push_back(curr);
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



// Approach 2: Backtracking using In-place Swapping
// TC: O(n * n!) — n! permutations, O(n) to copy each permutation
// SC: O(n) — recursion stack (excluding output space)

class Solution {
private:
    void helper(int idx, vector<vector<int>> &ans, vector<int>& nums){
        if(idx==nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i = idx; i < nums.size(); i++) {   
            swap(nums[idx],nums[i]);
            helper(idx+1,ans,nums);
            swap(nums[idx],nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(0,ans,nums);
        return ans;
    }
};
