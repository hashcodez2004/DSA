// ============================================================
// Approach 1: Recursion (Brute Force)
// TC: O(n^m) - n choices for each of the m days
// SC: O(m) - Recursion stack
// ============================================================

class Solution {
private:
    int helper(int idx, int last, vector<vector<int>> &mat) {
        if(idx < 0)
            return 0;

        int maxi = 0;
        for(int i = 0; i < mat[0].size(); i++) {
            if(i == last) continue;

            int points = mat[idx][i] + helper(idx - 1, i, mat);
            maxi = max(maxi, points);
        }

        return maxi;
    }

public:
    int maximumPoints(vector<vector<int>>& mat) {
        int m = mat.size();
        return helper(m - 1, -1, mat);
    }
};



// ============================================================
// Approach 2: Memoization (Top-Down DP)
// TC: O(m * n^2)
// SC: O(m * n) - DP array + Recursion stack
//
// Note:
// last = -1 is not stored in DP because it is used only for
// the initial call.
// ============================================================

class Solution {
private:
    int helper(int idx, int last, vector<vector<int>> &mat,
               vector<vector<int>> &dp) {
        if(idx < 0)
            return 0;

        if(last != -1 && dp[idx][last] != -1)
            return dp[idx][last];

        int maxi = 0;
        for(int i = 0; i < mat[0].size(); i++) {
            if(i == last) continue;

            int points = mat[idx][i] + helper(idx - 1, i, mat, dp);
            maxi = max(maxi, points);
        }

        if(last == -1)
            return maxi;

        return dp[idx][last] = maxi;
    }

public:
    int maximumPoints(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m - 1, -1, mat, dp);
    }
};



// ============================================================
// Approach 3: Tabulation (Bottom-Up DP)
// TC: O(m * n^2)
// SC: O(m * n) - DP array
//
// Index Shifting:
// dp[idx][last] represents helper(idx - 1, last)
//
// helper(-1, last) -> dp[0][last]
// helper(0, last)  -> dp[1][last]
// helper(1, last)  -> dp[2][last]
// ...
//
// Since helper(-1, last) = 0:
// dp[0][last] = 0
//
// last = -1 is handled separately at the end because the DP
// table stores only actual activity indices from 0 to n - 1.
// ============================================================

class Solution {
public:
    int maximumPoints(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dp(m + 1, vector<int>(n, 0));

        for(int idx = 1; idx <= m; idx++) {
            for(int last = 0; last < n; last++) {

                int maxi = 0;

                for(int i = 0; i < n; i++) {
                    if(i == last) continue;

                    int points = mat[idx - 1][i] + dp[idx - 1][i];
                    maxi = max(maxi, points);
                }

                dp[idx][last] = maxi;
            }
        }

        // Equivalent to helper(m - 1, -1)
        int maxi = 0;
        for(int i = 0; i < n; i++)
            maxi = max(maxi, dp[m][i]);

        return maxi;
    }
};



// ============================================================
// Approach 4: Space Optimized DP
// TC: O(m * n^2)
// SC: O(n)
//
// curr[last] depends only on prev[i], so instead of storing
// all m DP rows, we only need the previous and current row.
// ============================================================

class Solution {
public:
    int maximumPoints(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<int> prev(n, 0);

        for(int idx = 1; idx <= m; idx++) {
            vector<int> curr(n, 0);

            for(int last = 0; last < n; last++) {
                int maxi = 0;

                for(int i = 0; i < n; i++) {
                    if(i == last) continue;

                    int points = mat[idx - 1][i] + prev[i];
                    maxi = max(maxi, points);
                }

                curr[last] = maxi;
            }

            prev = curr;
        }

        // Equivalent to helper(m - 1, -1)
        int maxi = 0;
        for(int i = 0; i < n; i++)
            maxi = max(maxi, prev[i]);

        return maxi;
    }
};
