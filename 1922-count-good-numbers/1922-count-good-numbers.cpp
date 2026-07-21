const int mod = 1e9 + 7;
using ll = long long;

class Solution {
private:
    ll helper(ll x, ll n) {
        if(n == 0) return 1.0;
        ll half = helper(x, n / 2);
        if(n % 2 == 0) 
            return (half * half) % mod;
        else 
            return (((half * half) %mod) * x) % mod;
    }

    ll myPow(ll x, ll n) {
        ll expo = n; // to handle INT_MIN safely
        if(expo < 0) {
            return 1.0 / helper(x, -expo);
        }
        return helper(x, expo);
    }

public:
    int countGoodNumbers(long long n) {
        ll odd = n/2;
        ll even = n/2 + n%2;
        return (int)((myPow(5,even) * myPow(4,odd) % mod ));
    }
};