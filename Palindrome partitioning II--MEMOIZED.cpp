#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPalindrome(int i, int j, string& temp){
        while(i <= j){
            if(temp[i] != temp[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int helper(int i, string& s, vector<int>& dp){
        if(i==s.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int minCost = 1e9;
        for(int j=i; j<s.size(); j++){
            if(isPalindrome(i,j,s)){
                int cost = 1 + helper(j+1,s,dp);
                minCost = min(minCost, cost);
            }
        }
        return dp[i] = minCost;
    }

public:
    int minCut(string s) {
        vector<int> dp(s.size(),-1);
        return helper(0,s,dp)-1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        int res = ob.minCut(s);
        cout << res << endl;
    }
    return 0;
}

/*
Time Complexity: O(n^2) — Each index is computed once, and for each index we check palindromes in O(n)
Space Complexity: O(n) for dp + O(n) recursion stack
*/
