class Solution {
public:
    double myPow(double x, int n) {
        long long expo = n;   // avoid overflow for INT_MIN
        if(expo < 0) {
            x = 1 / x;
            expo = -expo;
        }
        double ans = 1.0;
        while(expo > 0) {
            if(expo & 1) {      // if current bit is set
                ans *= x;
            }
            x *= x;             // square the base
            expo >>= 1;         // shift exponent right
        }
        return ans;
    }
};


/*
TC: O(logN) for both iterative and recursive
SC: O(logN) for Recursive and O(1) for iterative
*/



/*                          RECURSION
 
class Solution {
private:
    double helper(double x, long long n) {
        if(n == 0) return 1.0;
        double half = helper(x, n / 2);
        if(n % 2 == 0) 
            return half * half;
        else 
            return half * half * x;
    }

public:
    double myPow(double x, int n) {
        long long expo = n; // to handle INT_MIN safely
        if(expo < 0) {
            return 1.0 / helper(x, -expo);
        }
        return helper(x, expo);
    }
};
*/