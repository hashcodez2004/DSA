#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=1;buy>=0;buy--){
                for(int cnt=2;cnt>0;cnt--){
                    int profit = 0;
                    if(buy){
                        profit = max(-prices[idx] + dp[idx+1][0][cnt], 
                                        0 + dp[idx+1][1][cnt]);
                    }
                    else{
                        profit = max(prices[idx] + dp[idx+1][1][cnt-1],
                                        0 + dp[idx+1][0][cnt]);
                    }
                    dp[idx][buy][cnt] = profit;
                }
            }
        }
        return dp[0][1][2];
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
        int s = ob.maxProfit(nums);
        cout << s << endl;
    }
    return 0;
}


/*
Time Complexity: O(n * 2 * 3)
Space Complexity: O(n * 2 * 3)
*/