#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int helper(int i, int j, string& s1, string& s2){
        if(i<0) return j+1;
        if(j<0) return i+1;

        if(s1[i]==s2[j]) return helper(i-1,j-1,s1,s2);
        int insertChar = 1 + helper(i,j-1,s1,s2);
        int deleteChar = 1 + helper(i-1,j,s1,s2);
        int replaceChar = 1 + helper(i-1,j-1,s1,s2);
        return min({insertChar,deleteChar,replaceChar});
    }

public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        return helper(m-1,n-1,word1,word2);
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
Time Complexity: Exponential
Space Complexity: O(n + m)
*/