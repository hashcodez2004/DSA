#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int helper(int i, int j, bool isTrue, string &s) {
        if (i > j) return 0;
        if (i == j) {
            if (isTrue) return (s[i] == 'T');
            else return (s[i] == 'F');
        }

        int ways = 0;
        for (int ind = i + 1; ind <= j - 1; ind += 2) {
            int lT = helper(i, ind - 1, 1, s);
            int lF = helper(i, ind - 1, 0, s);
            int rT = helper(ind + 1, j, 1, s);
            int rF = helper(ind + 1, j, 0, s);

            if (s[ind] == '&') {
                if (isTrue) ways += (lT * rT);
                else ways += (lF * rT + lT * rF + lF * rF);
            } else if (s[ind] == '|') {
                if (isTrue) ways += (lT * rT + lT * rF + lF * rT);
                else ways += (lF * rF);
            } else { // XOR
                if (isTrue) ways += (lT * rF + lF * rT);
                else ways += (lT * rT + lF * rF);
            }
        }

        return ways;
    }

public:
    int countWays(string &s) {
        int n = s.size();
        return helper(0, n - 1, 1, s);
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
Time Complexity: Exponential -> O(2^n * n)  [Because of multiple partitions and 2 boolean states]
Space Complexity: O(n) recursion stack
*/