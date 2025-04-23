#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int helper(int idx, int W, const vector<int>& wt, const vector<int>& val) {
        if (idx == 0) {
            if (wt[0] <= W) return val[0];
            return 0;
        }

        int notTake = helper(idx - 1, W, wt, val);
        int take = 0;
        if (wt[idx] <= W)
            take = val[idx] + helper(idx - 1, W - wt[idx], wt, val);

        return max(take, notTake);
    }

public:
    int knapsack(int W, const vector<int>& wt, const vector<int>& val) {
        int n = wt.size();
        return helper(n - 1, W, wt, val);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, W;
        cin >> n >> W;
        vector<int> val(n);
        for (int i = 0; i < n; i++) cin >> val[i];
        vector<int> wt(n);
        for (int i = 0; i < n; i++) cin >> wt[i];

        Solution ob;
        int s = ob.knapsack(W, wt, val);
        cout << s << endl;
    }
    return 0;
}
