#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int helper(int i, int j, string& s1, string& s2, vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s1[i] == s2[j]) return dp[i][j] = 1 + helper(i - 1, j - 1, s1, s2, dp);
        else return dp[i][j] = max(helper(i - 1, j, s1, s2, dp), helper(i, j - 1, s1, s2, dp));

    }
public:
    int longestCommonSubsequence(string s1, string s2) {
        int i = s1.size();
        int j = s2.size();
        vector<vector<int>> dp(i,vector<int>(j,-1));
        return helper(i-1,j-1,s1,s2,dp);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;

        Solution ob;
        int s = ob.longestCommonSubsequence(s1,s2);
        cout << s << endl;
    }
    return 0;
}


/*
Time Complexity: O(n * m)
Space Complexity: O(n * m) + O(n + m)
*/