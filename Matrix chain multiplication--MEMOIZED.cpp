#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int helper(int i, int j, vector<int> &nums, vector<vector<int>>& dp){
        if(i==j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int mini = 1e9;
        for(int k=i; k<=j-1; k++){
            int ans = nums[i-1]*nums[k]*nums[j] + helper(i,k,nums,dp) + helper(k+1,j,nums,dp);
            mini = min(mini,ans);
        }
        return dp[i][j] = mini;
    }
    
  public:
    int matrixMultiplication(vector<int> &nums) {
        // code here
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return helper(1,n-1,nums,dp);
    }
};




int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i=0; i<n; i++) cin >> nums[i];
        Solution ob;
        int s = ob.matrixMultiplication(nums);
        cout << s << endl;
    }
    return 0;
}


/*
Time Complexity: O(n*n*n)
Space Complexity: O(n*n) + O(n)
*/