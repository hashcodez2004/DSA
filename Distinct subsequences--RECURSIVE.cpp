#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int helper(int i, int j, string& s, string& t){
        if(j<0) return 1;
        if(i<0) return 0;

        if(s[i]==t[j]) return helper(i-1,j,s,t) + helper(i-1,j-1,s,t);
        else return helper(i-1,j,s,t);
    }

public:
    int numDistinct(string& s, string& t) {
        int i = s.size();
        int j = t.size();
        return helper(i-1,j-1,s,t);
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