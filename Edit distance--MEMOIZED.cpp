#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int helper(int i, int j, string& s1, string& s2, vector<vector<int>>& dp){
        if(i<0) return j+1;
        if(j<0) return i+1;

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i]==s2[j]) return dp[i][j] = helper(i-1,j-1,s1,s2,dp);
        int insertChar = 1 + helper(i,j-1,s1,s2,dp);
        int deleteChar = 1 + helper(i-1,j,s1,s2,dp);
        int replaceChar = 1 + helper(i-1,j-1,s1,s2,dp);
        return dp[i][j] = min({insertChar,deleteChar,replaceChar});
    }

public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,word1,word2,dp);
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
Space Complexity: O(n * m) + O(n + m)
*/