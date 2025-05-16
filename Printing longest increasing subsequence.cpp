#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> printLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> hash(n);
        for(int i=0;i<n;i++) hash[i]=i;

        int maxii = 1;
        int max_idx = 0;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(dp[j]+1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        hash[i] = j;
                    }
                }
            }
            if(dp[i] > maxii){
                maxii=dp[i];
                max_idx=i;
            }
        }
        
        vector<int> res;
        int idx=max_idx;
        while(hash[idx]!=idx){
            res.push_back(nums[idx]);
            idx=hash[idx];
        }
        res.push_back(nums[idx]);

        reverse(res.begin(),res.end());

        return res;
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
        vector<int> s = ob.printLIS(nums);
        for(int i=0;i<s.size();i++) cout<<s[i]<<" ";
        cout<<endl;
    }
    return 0;
}


/*
Time Complexity: O(n * n)
Space Complexity: O(n) + O(n)
*/