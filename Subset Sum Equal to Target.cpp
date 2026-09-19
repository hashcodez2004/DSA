/*
============================================================
                    SUBSET SUM
============================================================

Problem:
Given an array and a target, determine whether there exists
a subset whose sum is equal to target.

Example:
nums = {2, 3, 7, 8, 10}
target = 11

Answer = true
because 3 + 8 = 11.


============================================================
1. RECURSION
============================================================

Idea:
For every element, we have two choices:

1. Take the current element
2. Don't take the current element

State:
helper(idx, target)

Meaning:
Can we form `target` using elements from index 0 to idx?

Time Complexity:
O(2^n)

Space Complexity:
O(n)
-> Recursion stack


------------------------------------------------------------
CODE
------------------------------------------------------------
*/

class SolutionRecursion {
private:
    bool helper(int idx, int target, vector<int>& nums) {
        if(idx < 0)
            return target == 0;

        bool take = false;

        if(nums[idx] <= target)
            take = helper(idx - 1, target - nums[idx], nums);

        bool notTake = helper(idx - 1, target, nums);

        return take || notTake;
    }

public:
    bool isSubsetSum(vector<int>& nums, int target) {
        int n = nums.size();

        return helper(n - 1, target, nums);
    }
};


/*
============================================================
2. MEMOIZATION / TOP-DOWN DP
============================================================

Problem with recursion:
The same states are calculated multiple times.

State:
dp[idx][target]

dp[idx][target] means:
Can we form `target` using elements from 0 to idx?

Time Complexity:
O(n * target)

Space Complexity:
O(n * target)
-> DP table

O(n)
-> Recursion stack

Overall Space:
O(n * target)


------------------------------------------------------------
CODE
------------------------------------------------------------
*/

class SolutionMemoization {
private:
    bool helper(int idx, int target, vector<int>& nums,
                vector<vector<int>>& dp) {

        if(idx < 0)
            return target == 0;

        if(dp[idx][target] != -1)
            return dp[idx][target];

        bool take = false;

        if(nums[idx] <= target)
            take = helper(idx - 1, target - nums[idx], nums, dp);

        bool notTake = helper(idx - 1, target, nums, dp);

        return dp[idx][target] = (take || notTake);
    }

public:
    bool isSubsetSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return helper(n - 1, target, nums, dp);
    }
};


/*
============================================================
3. TABULATION / BOTTOM-UP DP
============================================================

Convert the recursive states into a DP table.

State:
dp[idx][tar]

Meaning:
Can we form sum `tar` using elements from 0 to idx?

Base Cases:

dp[0][0] = true

If nums[0] <= target:

dp[0][nums[0]] = true

Transition:

take:
    dp[idx - 1][tar - nums[idx]]

notTake:
    dp[idx - 1][tar]

Therefore:

dp[idx][tar] = take || notTake


Time Complexity:
O(n * target)

Space Complexity:
O(n * target)


------------------------------------------------------------
CODE
------------------------------------------------------------
*/

class SolutionTabulation {
public:
    bool isSubsetSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        dp[0][0] = 1;

        if(nums[0] <= target)
            dp[0][nums[0]] = 1;

        for(int idx = 1; idx < n; idx++) {

            for(int tar = 0; tar <= target; tar++) {

                int take = 0;

                if(nums[idx] <= tar)
                    take = dp[idx - 1][tar - nums[idx]];

                int notTake = dp[idx - 1][tar];

                dp[idx][tar] = (take || notTake);
            }
        }

        return dp[n - 1][target];
    }
};


/*
============================================================
4. SPACE-OPTIMIZED TABULATION
============================================================

Observation:

To calculate:

    dp[idx][tar]

we only need:

    dp[idx - 1][...]

Therefore, we don't need the entire 2D table.

Maintain:

    prev -> previous row
    curr -> current row

After calculating curr:

    prev = curr


Time Complexity:
O(n * target)

Space Complexity:
O(target)


------------------------------------------------------------
CODE
------------------------------------------------------------
*/

class SolutionSpaceOptimized {
public:
    bool isSubsetSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> prev(target + 1, 0);

        prev[0] = 1;

        if(nums[0] <= target)
            prev[nums[0]] = 1;

        for(int idx = 1; idx < n; idx++) {

            vector<int> curr(target + 1, 0);

            for(int tar = 0; tar <= target; tar++) {

                int take = 0;

                if(nums[idx] <= tar)
                    take = prev[tar - nums[idx]];

                int notTake = prev[tar];

                curr[tar] = (take || notTake);
            }

            prev = curr;
        }

        return prev[target];
    }
};


/*
============================================================
                 COMPLEXITY SUMMARY
============================================================

Approach                  Time              Space
------------------------------------------------------------
Recursion                 O(2^n)            O(n)

Memoization               O(n * target)     O(n * target)

Tabulation                O(n * target)     O(n * target)

Space Optimized           O(n * target)     O(target)
------------------------------------------------------------


DP PATTERN TO REMEMBER:

                helper(idx, target)
                       |
                ----------------
                |              |
              TAKE          NOT TAKE
                |              |
       idx-1, target-x    idx-1, target


For BOOLEAN DP:
    take || notTake

For COUNT DP:
    take + notTake

For MIN/MAX DP:
    min(take, notTake)
    or
    max(take, notTake)


Progression:

Recursion
    ↓
Memoization
    ↓
Tabulation
    ↓
Space Optimization


Most optimized version:
    O(n * target) Time
    O(target) Space
============================================================
*/
