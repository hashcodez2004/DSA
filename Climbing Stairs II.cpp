// ============================================================
// Approach 1: Recursion (Brute Force)
// TC: O(3^n)
// SC: O(n) - Recursion stack
// ============================================================

class Solution {
private:
    int helper(int idx, vector<int> &costs) {
        // Base case: before the first stair costs nothing
        if(idx == -1)
            return 0;

        int one = helper(idx - 1, costs) + costs[idx] + 1;

        int two = 1e9;
        if(idx > 0)
            two = helper(idx - 2, costs) + costs[idx] + 4;

        int three = 1e9;
        if(idx > 1)
            three = helper(idx - 3, costs) + costs[idx] + 9;

        return min({one, two, three});
    }

public:
    int climbStairs(int n, vector<int>& costs) {
        return helper(n - 1, costs);
    }
};



// ============================================================
// Approach 2: Memoization (Top-Down DP)
// TC: O(n)
// SC: O(n) - DP array + Recursion stack
// ============================================================

class Solution {
private:
    int helper(int idx, vector<int> &costs, vector<int> &dp) {
        // Base case: before the first stair costs nothing
        if(idx == -1)
            return 0;

        // Shift idx by 1 because idx can be -1
        if(dp[idx + 1] != -1)
            return dp[idx + 1];

        int one = helper(idx - 1, costs, dp) + costs[idx] + 1;

        int two = 1e9;
        if(idx > 0)
            two = helper(idx - 2, costs, dp) + costs[idx] + 4;

        int three = 1e9;
        if(idx > 1)
            three = helper(idx - 3, costs, dp) + costs[idx] + 9;

        return dp[idx + 1] = min({one, two, three});
    }

public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, -1);

        return helper(n - 1, costs, dp);
    }
};



// ============================================================
// Approach 3: Tabulation (Bottom-Up DP)
// TC: O(n)
// SC: O(n) - DP array
//
// Index Shifting:
// Memoization state: helper(idx)
// Tabulation state:  dp[idx + 1]
//
// Therefore:
// helper(-1)  -> dp[0]
// helper(0)   -> dp[1]
// helper(1)   -> dp[2]
// ...
// helper(n-1) -> dp[n]
//
// Since tabulation idx is shifted by 1:
// costs[idx]  -> costs[idx - 1]
// idx > 0     -> idx > 1
// idx > 1     -> idx > 2
// ============================================================

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, 0);

        for(int idx = 1; idx < n + 1; idx++) {

            // 1-step jump
            int one = dp[idx - 1] + costs[idx - 1] + 1;

            // 2-step jump
            int two = 1e9;
            if(idx > 1)
                two = dp[idx - 2] + costs[idx - 1] + 4;

            // 3-step jump
            int three = 1e9;
            if(idx > 2)
                three = dp[idx - 3] + costs[idx - 1] + 9;

            dp[idx] = min({one, two, three});
        }

        return dp[n];
    }
};


// ============================================================
// Approach 4: Space Optimization
// TC: O(n)
// SC: O(1)
// ============================================================

class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int prev=0, prev1=0, prev2=0;
        for(int idx=1; idx<n+1; idx++){
            int one = prev + costs[idx-1] + 1;

            int two = 1e9;
            if(idx > 1) two = prev1 + costs[idx-1] + 4;

            int three = 1e9;
            if(idx > 2) three = prev2 + costs[idx-1] + 9;

            int curr = min({one,two,three});

            prev2=prev1;
            prev1=prev;
            prev=curr;
        }
        return prev;
    }
};
