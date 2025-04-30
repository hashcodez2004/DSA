#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isAllStar(int j, const string& s2) {
        for (int i = 0; i <= j; i++)
            if (s2[i] != '*') return false;
        return true;
    }

    bool helper(int i, int j, const string& s1, const string& s2, vector<vector<int>>& dp) {
        if (i < 0 && j < 0) return true;
        if (i < 0) return isAllStar(j, s2);
        if (j < 0) return false;

        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j] || s2[j] == '?') {
            return dp[i][j] = helper(i - 1, j - 1, s1, s2, dp);
        } else if (s2[j] == '*') {
            return dp[i][j] = helper(i - 1, j, s1, s2, dp) || helper(i, j - 1, s1, s2, dp);
        }

        return dp[i][j] = false;
    }

public:
    bool isMatch(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(n - 1, m - 1, s1, s2, dp);
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
Space Complexity: O(n * m) + O(n + m)
*/