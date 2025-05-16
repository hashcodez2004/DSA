#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        int maxii = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
            maxii = max(maxii, dp[i]);
        }
        return maxii;
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
        int s = ob.lengthOfLIS(nums);
        cout << s << endl;
    }
    return 0;
}


/*
Time Complexity: O(n * n)
Space Complexity: O(n)
*/