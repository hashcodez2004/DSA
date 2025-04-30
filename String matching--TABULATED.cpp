#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isAllStar(int j, const string& s2) {
        for (int i = 0; i < j; i++)
            if (s2[i] != '*') return false;
        return true;
    }

public:
    bool isMatch(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

/*      BASE CASES
        if (i == 0 && j == 0) return true;
        if (i == 0) return isAllStar(j, s2);  // j>0
        if (j == 0) return false;             // i>0    */

        dp[0][0] = true;
        for(int i=1;i<=m;i++) dp[i][0] = false;
        for(int j=1;j<=n;j++) dp[0][j] = isAllStar(j,s2);

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if (s1[i-1] == s2[j-1] || s2[j-1] == '?') dp[i][j] = dp[i-1][j-1];
                else if (s2[j-1] == '*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else dp[i][j] = false;
            }
        }
        return dp[m][n];
    }
};




int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;

        Solution ob;
        bool s = ob.isMatch(s1,s2);
        if(s) cout << "True" << endl;
        else cout << "False" << endl;
    }
    return 0;
}


/*
Time Complexity: O(n * m)
Space Complexity: O(n * m)
*/