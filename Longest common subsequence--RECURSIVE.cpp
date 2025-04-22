#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int helper(int i, int j, const string& s1, const string& s2){
        if(i<0 || j<0) return 0;

        if(s1[i]==s2[j]) return 1 + helper(i-1,j-1,s1,s2);
        else return max(helper(i-1,j,s1,s2), helper(i,j-1,s1,s2));
    }

  public:
    int longestCommonSubsequence(const string& s1, const string& s2) {
        // code here
        int size1 = s1.size();
        int size2 = s2.size();
        return helper(size1-1,size2-1,s1,s2);
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
Time Complexity: O(2^(n + m))
Space Complexity: O(n + m)
*/