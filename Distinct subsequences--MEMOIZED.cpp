#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int helper(int i, int j, string& s, string& t, vector<vector<int>>& dp){
        if(j<0) return 1;
        if(i<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==t[j]) return dp[i][j] = helper(i-1,j,s,t,dp) + helper(i-1,j-1,s,t,dp);
        else return dp[i][j] = helper(i-1,j,s,t,dp);
    }

public:
    int numDistinct(string& s, string& t) {
        int i = s.size();
        int j = t.size();
        vector<vector<int>> dp(i,vector<int>(j,-1));
        return helper(i-1,j-1,s,t,dp);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;

        Solution ob;
        int s = ob.numDistinct(s1,s2);
        cout << s << endl;
    }
    return 0;
}


/*
Time Complexity: O(n * m)
Space Complexity: O(n * m) + O(n + m)
*/