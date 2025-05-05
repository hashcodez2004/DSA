#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int helper(int idx, int buy, vector<int>& prices){
        if(idx == prices.size()) return 0;

        int profit = 0;
        if(buy){
            profit = max(-prices[idx] + helper(idx+1,0,prices),
                          0 + helper(idx+1,1,prices));
        }
        else{
            profit = max(prices[idx] + helper(idx+1,1,prices),
                          0 + helper(idx+1,0,prices));
        }
        return profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return helper(0, 1, prices);
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
Time Complexity: O(2^n)
Space Complexity: O(n)
*/