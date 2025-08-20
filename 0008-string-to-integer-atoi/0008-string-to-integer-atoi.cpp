class Solution {
public:
    int helper(string &s, int i, int n, long long num, int sign) {
        // base case: end of string or non-digit
        if (i >= n || !isdigit(s[i])) return (int)(num * sign);

        // recursive case: add current digit
        num = num * 10 + (s[i] - '0');

        // overflow handling
        if (num * sign > INT_MAX) return INT_MAX;
        if (num * sign < INT_MIN) return INT_MIN;

        return helper(s, i + 1, n, num, sign);
    }

    int myAtoi(string s) {
        int n = s.size();
        int i = 0;

        // skip spaces
        while (i < n && s[i] == ' ') i++;

        // handle sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // recursion for digits
        return helper(s, i, n, 0, sign);
    }
};
