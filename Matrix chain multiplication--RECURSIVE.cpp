#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int helper(int i, int j, vector<int> &nums){
        if(i==j) return 0;
        int mini = 1e9;
        for(int k=i; k<=j-1; k++){
            int ans = nums[i-1]*nums[k]*nums[j] + helper(i,k,nums) + helper(k+1,j,nums);
            mini = min(mini,ans);
        }
        return mini;
    }
    
  public:
    int matrixMultiplication(vector<int> &nums) {
        // code here
        int n = nums.size();
        return helper(1,n-1,nums);
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
Time Complexity: exponential
Space Complexity: O(n)
*/