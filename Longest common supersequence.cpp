#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
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
        
        //Printing SCS
        string ans;

        int i = size1;
        int j = size2;
        while(i>0 and j>0){
            if(s1[i-1]==s2[j-1]){
                ans.push_back(s1[i-1]);
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                ans.push_back(s1[i-1]);
                i--;
            }
            else{
                ans.push_back(s2[j-1]);
                j--;
            }
        }

        reverse(ans.begin(),ans.end());
        if(i>0) ans=s1.substr(0,i)+ans;
        if(j>0) ans=s2.substr(0,j)+ans;
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
        string s = ob.shortestCommonSupersequence(s1,s2);
        cout << s << endl;
    }
    return 0;
}


/*
Time Complexity: O(n * m)
Space Complexity: O(n * m)
*/