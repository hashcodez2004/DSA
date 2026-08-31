// ============================================================
// Approach 1: Recursion (Brute Force)
// TC: O(3^n)
// SC: O(n) - Recursion stack
//
// State:
// helper(day, last)
//
// last:
// 0, 1, 2 -> Cannot perform this activity today
// 3       -> No activity restriction
// ============================================================

class Solution {
private:
    int helper(int day, int last, vector<vector<int>> &points) {
        // Base Case
        if(day == 0) {
            int maxi = 0;
            for(int task = 0; task < 3; task++) {
                if(task != last) maxi = max(maxi, points[0][task]);
            }

            return maxi;
        }

        int maxi = 0;
        for(int task = 0; task < 3; task++) {
            if(task != last) {
                int activity = points[day][task] + helper(day - 1, task, points);
                maxi = max(maxi, activity);
            }
        }

        return maxi;
    }

public:
    int ninjaTraining(int n, vector<vector<int>> &points) {
        return helper(n - 1, 3, points);
    }
};



// ============================================================
// Approach 2: Memoization (Top-Down DP)
// TC: O(n * 4 * 3) = O(12n)
// SC: O(4n + n) = O(5n)
//     DP array + Recursion stack
//
// dp[day][last] stores the maximum points from day 0 to day,
// where activity 'last' cannot be performed on the current day.
// ============================================================

class Solution {
private:
    int helper(int day, int last, vector<vector<int>> &points,
               vector<vector<int>> &dp) {

        // Already Computed
        if(dp[day][last] != -1)
            return dp[day][last];

        // Base Case
        if(day == 0) {
            int maxi = 0;

            for(int task = 0; task < 3; task++) {
                if(task != last)
                    maxi = max(maxi, points[0][task]);
            }

            return dp[day][last] = maxi;
        }

        int maxi = 0;
        for(int task = 0; task < 3; task++) {
            if(task != last) {
                int activity = points[day][task] +
                               helper(day - 1, task, points, dp);

                maxi = max(maxi, activity);
            }
        }

        return dp[day][last] = maxi;
    }

public:
    int ninjaTraining(int n, vector<vector<int>> &points) {
        vector<vector<int>> dp(n, vector<int>(4, -1));

        return helper(n - 1, 3, points, dp);
    }
};



// ============================================================
// Approach 3: Tabulation (Bottom-Up DP)
// TC: O(n * 4 * 3) = O(12n)
// SC: O(4n)
//
// No Index Shifting:
//
// Memoization:
// helper(day, last) -> dp[day][last]
//
// Therefore:
// helper(0, last) -> dp[0][last]
//
// The first day is initialized directly, then we move forward
// from day = 1 to n - 1.
// ============================================================

class Solution {
public:
    int ninjaTraining(int n, vector<vector<int>> &points) {
        vector<vector<int>> dp(n, vector<int>(4, 0));

        // Base Case Initialization

        // Activity 0 cannot be performed
        dp[0][0] = max(points[0][1], points[0][2]);

        // Activity 1 cannot be performed
        dp[0][1] = max(points[0][0], points[0][2]);

        // Activity 2 cannot be performed
        dp[0][2] = max(points[0][0], points[0][1]);

        // No activity restriction
        dp[0][3] = max(points[0][0],
                       max(points[0][1], points[0][2]));


        for(int day = 1; day < n; day++) {
            for(int last = 0; last < 4; last++) {
                dp[day][last] = 0;

                for(int task = 0; task < 3; task++) {
                    if(task != last) {
                        int activity = points[day][task] +
                                       dp[day - 1][task];

                        dp[day][last] =
                            max(dp[day][last], activity);
                    }
                }
            }
        }

        return dp[n - 1][3];
    }
};



// ============================================================
// Approach 4: Space Optimized DP
// TC: O(n * 4 * 3) = O(12n)
// SC: O(4 + 4) = O(8) = O(1)
//
// Each state depends only on the previous day's DP states.
// Therefore, we only need:
// - prev: Previous day
// - temp: Current day
// ============================================================

class Solution {
public:
    int ninjaTraining(int n, vector<vector<int>> &points) {
        vector<int> prev(4, 0);

        // Base Case Initialization

        // Activity 0 cannot be performed
        prev[0] = max(points[0][1], points[0][2]);

        // Activity 1 cannot be performed
        prev[1] = max(points[0][0], points[0][2]);

        // Activity 2 cannot be performed
        prev[2] = max(points[0][0], points[0][1]);

        // No activity restriction
        prev[3] = max(points[0][0],
                      max(points[0][1], points[0][2]));


        for(int day = 1; day < n; day++) {
            vector<int> temp(4, 0);

            for(int last = 0; last < 4; last++) {

                for(int task = 0; task < 3; task++) {
                    if(task != last) {
                        int activity = points[day][task] +
                                       prev[task];

                        temp[last] =
                            max(temp[last], activity);
                    }
                }
            }

            prev = temp;
        }

        return prev[3];
    }
};
