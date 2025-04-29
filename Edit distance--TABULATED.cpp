#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<=m;i++) dp[i][0] = i;
        for(int j=1;j<=n;j++) dp[0][j] = j;

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1];
                else{
                    int insertChar = 1 + dp[i][j-1];
                    int deleteChar = 1 + dp[i-1][j];
                    int replaceChar = 1 + dp[i-1][j-1];
                    dp[i][j] = min({insertChar,deleteChar,replaceChar});
                }
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
        int s = ob.minDistance(s1,s2);
        cout << s << endl;
    }
    return 0;
}


/*
Time Complexity: O(n * m)
Space Complexity: O(n + m)
*/