#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int maximum(int i, int j, vector<int>& arr){
        int maxii = -1e9;
        for(int k=i; k<=j; k++){
            maxii = max(maxii, arr[k]);
        }
        return maxii;
    }

    int helper(int i, vector<int>& arr, int k, vector<int>& dp){
        if(i==arr.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int maxii=-1e9;
        for(int j=i;j<arr.size();j++){
            if(j-i+1 <= k){
                int cost = maximum(i,j,arr)*(j-i+1) + helper(j+1,arr,k,dp);
                maxii = max(maxii,cost);
            }
        }

        return dp[i] = maxii;
    }

public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        return helper(0,arr,k,dp);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        vector<int> nums(n);
        for(int i=0;i<n;i++) cin>>nums[i];
        Solution ob;
        int res = ob.maxSumAfterPartitioning(nums,k);
        cout << res << endl;
    }
    return 0;
}


/*
Time Complexity: O(n^2)*n — Each index is computed once, and for each index we check largest in O(n)
Space Complexity: O(n) for dp + O(n) recursion stack
*/