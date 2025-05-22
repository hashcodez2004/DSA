#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> cnt(n,1);

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        cnt[i]=cnt[j];
                    }
                    else if(dp[j]+1==dp[i]) cnt[i]+=cnt[j];
                }
            }
        }

        int maxLen = *max_element(dp.begin(), dp.end());
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(dp[i] == maxLen) ans += cnt[i];
        }

        return ans;
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
        int s = ob.findNumberOfLIS(nums);
        cout << s << endl;
    }
    return 0;
}


/*
Time Complexity: O(n * n)
Space Complexity: O(n) + O(n)
*/