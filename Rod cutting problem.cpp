#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int len = price.size();
        vector<vector<int>> dp(len, vector<int>(len+1,-0));
        for(int i=1;i<=len;i++) dp[0][i] = price[0]*i;
        
        for(int idx=1;idx<len;idx++){
            for(int length=1;length<=len;length++){
                int notTake = dp[idx-1][length];
                int take = 0;
                if(idx+1<=length) take = price[idx] + dp[idx][length-idx-1];
                dp[idx][length] = max(take,notTake);
            }
        }
        return dp[len-1][len];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> price(n);
        for (int i = 0; i < n; i++) cin >> price[i];

        Solution ob;
        int s = ob.cutRod(price);
        cout << s << endl;
    }
    return 0;
}


/*
Time Complexity: O(n x n)
Space Complexity: O(n x n) [for DP table]
*/