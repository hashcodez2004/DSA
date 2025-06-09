#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int helper(int i, int j, bool isTrue, string &s, vector<vector<vector<int>>>& dp){
        if(i > j) return 0;

        if(i == j){
            if(isTrue) return (s[i] == 'T');
            else return (s[i] == 'F');
        }

        if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

        int ways = 0;
        for(int ind = i + 1; ind <= j - 1; ind += 2){
            int lT = helper(i, ind - 1, 1, s, dp);
            int lF = helper(i, ind - 1, 0, s, dp);
            int rT = helper(ind + 1, j, 1, s, dp);
            int rF = helper(ind + 1, j, 0, s, dp);

            if (s[ind] == '&') {
                if (isTrue) ways += (lT * rT);
                else ways += (lF * rT + lT * rF + lF * rF);
            }
            else if (s[ind] == '|') {
                if (isTrue) ways += (lT * rT + lT * rF + lF * rT);
                else ways += (lF * rF);
            }
            else {  // XOR operator
                if (isTrue) ways += (lT * rF + lF * rT);
                else ways += (lT * rT + lF * rF);
            }
        }

        return dp[i][j][isTrue] = ways;
    }

public:
    int countWays(string &s) {
        int n = s.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return helper(0, n - 1, 1, s, dp);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        int res = ob.countWays(s);
        cout << res << endl;
    }
    return 0;
}

/*
Time Complexity: O(n^3)
- 3D DP: i, j, and isTrue = O(n^2 * 2)
- Each partition at ind takes O(n), so total = O(n^3)

Space Complexity: O(n^2 * 2) + O(n) recursion stack
*/