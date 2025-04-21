#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int helper(int idx, int amt, const vector<int>& coins){
        if(idx==0){
            if(amt%coins[0]==0) return 1;
            else return 0;
        }
        int notTake = helper(idx-1,amt,coins);
        int take = 0;
        if(coins[idx]<=amt) take = helper(idx,amt-coins[idx],coins);

        return take + notTake;
    }

public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        return helper(n-1,amount,coins);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, amount;
        cin >> n >> amount;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];

        Solution ob;
        int s = ob.change(amount, nums);
        cout << s << endl;
    }
    return 0;
}


/*
Time Complexity: O(2^(amount + n)) // exponential due to branching
Space Complexity: O(amount) // recursion depth
*/
