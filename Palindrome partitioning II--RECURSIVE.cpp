#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPalindrome(int i, int j, string& temp){
        while(i <= j){
            if(temp[i] != temp[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int helper(int i, string& s){
        if(i==s.size()) return 0;

        int minCost = 1e9;
        for(int j=i; j<s.size(); j++){
            if(isPalindrome(i,j,s)){
                int cost = 1 + helper(j+1,s);
                minCost = min(minCost, cost);
            }
        }
        return minCost;
    }

public:
    int minCut(string s) {
        return helper(0,s)-1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        int res = ob.minCut(s);
        cout << res << endl;
    }
    return 0;
}

/*
Time Complexity: O(2^n * n)  — Exponential in worst case with O(n) for checking palindrome each time
Space Complexity: O(n) for recursion stack
*/
