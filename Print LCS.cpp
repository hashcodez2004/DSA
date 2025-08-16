#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string printLongestCommonSubsequence(string s1, string s2) {
        //Filling the DP table
        int size1 = s1.size();
        int size2 = s2.size();
        vector<vector<int>> dp(size1+1,vector<int>(size2+1,0));
        for(int i=1;i<=size1;i++){
            for(int j=1;j<=size2;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        //Printing LCS
        int len = dp[size1][size2];
        string ans(len, '$'); // initializes ans with 'len' number of '$'
        int idx = len - 1;

        int i = size1;
        int j = size2;
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                ans[idx--] = s1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]) i--;
            else j--;
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;

        Solution ob;
        string s = ob.printLongestCommonSubsequence(s1,s2);
        cout << s << endl;
    }
    return 0;
}


/*
Time Complexity: O(n * m)
Space Complexity: O(n * m)
*/
