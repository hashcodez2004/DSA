#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDistinct(string& s, string& t) {
        int i = s.size();
        int j = t.size();
        vector<vector<double>> dp(i+1,vector<double>(j+1,0)); //due to integer overflow
        for(int x = 0; x<=i; x++) dp[x][0] = 1;
        
        for(int m=1;m<=i;m++){
            for(int n=1;n<=j;n++){
                if(s[m-1]==t[n-1]) dp[m][n] = dp[m-1][n] + dp[m-1][n-1];
                else dp[m][n] = dp[m-1][n];
            }
        }
        return (int)dp[i][j];
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
Space Complexity: O(n * m)
*/