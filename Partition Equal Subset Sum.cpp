/*
   Core idea:

        Total sum = S

        If S is odd:
            return false

        Otherwise:
            target = S / 2

        Now the problem becomes:

            "Can I form target using a subset of nums?"

        This is the Subset Sum problem.


    ================================================================
                         COMPLEXITY
    ================================================================

    1. Recursion / Brute Force
        Time  : O(2^n)
        Space : O(n) recursion stack

    2. Memoization
        Time  : O(n * target)
        Space : O(n * target) DP + O(n) recursion stack

    3. Tabulation
        Time  : O(n * target)
        Space : O(n * target)

    4. Space Optimized Tabulation
        Time  : O(n * target)
        Space : O(target)

    where:
        target = totalSum / 2


    ================================================================
                    INDEX SHIFTING - SHORT NOTE
    ================================================================

    Recursive base case:

        if(idx < 0)
            return target == 0;

    Since idx can become -1, there are two ways to represent the
    states in tabulation.

    ---------------------------------------------------------------
    WITH INDEX SHIFTING
    ---------------------------------------------------------------

        recursive idx       DP row

             -1       ->      0
              0       ->      1
              1       ->      2
             ...
             n-1       ->      n

        Therefore:
            DP has n + 1 rows.

        Base:
            dp[0][0] = 1;

        Current element:
            nums[idx - 1]

        Answer:
            dp[n][target]


    ---------------------------------------------------------------
    WITHOUT INDEX SHIFTING
    ---------------------------------------------------------------

        DP row idx directly represents elements 0...idx.

        Since idx = -1 cannot be represented, handle the first
        element separately:

            dp[0][0] = 1;

            if(nums[0] <= target)
                dp[0][nums[0]] = 1;

        Start transition from idx = 1.

        Current element:
            nums[idx]

        Answer:
            dp[n-1][target]
*/


// =================================================================
//                  A. WITH INDEX SHIFTING
// =================================================================


// =================================================================
// 1. RECURSION / BRUTE FORCE
// =================================================================
//
// Time  : O(2^n)
// Space : O(n) recursion stack
// =================================================================

class RecursiveShiftedSolution {
private:
    bool helper(int idx, int target, vector<int>& nums){
        if(idx < 0)
            return target == 0;

        bool take = false;

        if(nums[idx] <= target)
            take = helper(idx-1, target-nums[idx], nums);

        bool notTake = helper(idx-1, target, nums);

        return take || notTake;
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int target = 0;
        for(int i = 0; i < n; i++)
            target += nums[i];

        if(target % 2 == 1)
            return false;

        return helper(n-1, target/2, nums);
    }
};


// =================================================================
// 2. MEMOIZATION
// =================================================================
//
// Time  : O(n * target)
// Space : O(n * target) DP + O(n) recursion stack
// =================================================================

class MemoShiftedSolution {
private:
    bool helper(int idx, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(idx < 0)
            return target == 0;

        if(dp[idx + 1][target] != -1)
            return dp[idx + 1][target];

        bool take = false;

        if(nums[idx] <= target)
            take = helper(idx-1, target-nums[idx], nums, dp);

        bool notTake = helper(idx-1, target, nums, dp);

        return dp[idx + 1][target] = take || notTake;
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int target = 0;
        for(int i = 0; i < n; i++)
            target += nums[i];

        if(target % 2 == 1)
            return false;

        target /= 2;

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

        return helper(n-1, target, nums, dp);
    }
};


// =================================================================
// 3. TABULATION
// =================================================================
//
// Time  : O(n * target)
// Space : O(n * target)
// =================================================================

class TabulationShiftedSolution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int target = 0;
        for(int i = 0; i < n; i++)
            target += nums[i];

        if(target % 2 == 1)
            return false;

        target /= 2;

        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        dp[0][0] = 1;

        for(int idx = 1; idx <= n; idx++){
            for(int tar = 0; tar <= target; tar++){

                bool take = false;

                if(nums[idx-1] <= tar)
                    take = dp[idx-1][tar-nums[idx-1]];

                bool notTake = dp[idx-1][tar];

                dp[idx][tar] = take || notTake;
            }
        }

        return dp[n][target];
    }
};


// =================================================================
// 4. SPACE OPTIMIZED TABULATION
// =================================================================
//
// Time  : O(n * target)
// Space : O(target)
// =================================================================

class SpaceOptimizedShiftedSolution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int target = 0;
        for(int i = 0; i < n; i++)
            target += nums[i];

        if(target % 2 == 1)
            return false;

        target /= 2;

        vector<int> prev(target + 1, 0);

        prev[0] = 1;

        for(int idx = 1; idx <= n; idx++){

            vector<int> curr(target + 1, 0);

            for(int tar = 0; tar <= target; tar++){

                bool take = false;

                if(nums[idx-1] <= tar)
                    take = prev[tar-nums[idx-1]];

                bool notTake = prev[tar];

                curr[tar] = take || notTake;
            }

            prev = curr;
        }

        return prev[target];
    }
};


// =================================================================
//                B. WITHOUT INDEX SHIFTING
// =================================================================


// =================================================================
// 1. RECURSION / BRUTE FORCE
// =================================================================
//
// Time  : O(2^n)
// Space : O(n) recursion stack
// =================================================================

class RecursiveSolution {
private:
    bool helper(int idx, int target, vector<int>& nums){
        if(idx < 0)
            return target == 0;

        bool take = false;

        if(nums[idx] <= target)
            take = helper(idx-1, target-nums[idx], nums);

        bool notTake = helper(idx-1, target, nums);

        return take || notTake;
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int target = 0;
        for(int i = 0; i < n; i++)
            target += nums[i];

        if(target % 2 == 1)
            return false;

        return helper(n-1, target/2, nums);
    }
};


// =================================================================
// 2. MEMOIZATION
// =================================================================
//
// Time  : O(n * target)
// Space : O(n * target) DP + O(n) recursion stack
// =================================================================

class MemoSolution {
private:
    bool helper(int idx, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(idx < 0)
            return target == 0;

        if(dp[idx][target] != -1)
            return dp[idx][target];

        bool take = false;

        if(nums[idx] <= target)
            take = helper(idx-1, target-nums[idx], nums, dp);

        bool notTake = helper(idx-1, target, nums, dp);

        return dp[idx][target] = take || notTake;
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int target = 0;
        for(int i = 0; i < n; i++)
            target += nums[i];

        if(target % 2 == 1)
            return false;

        target /= 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return helper(n-1, target, nums, dp);
    }
};


// =================================================================
// 3. TABULATION
// =================================================================
//
// Time  : O(n * target)
// Space : O(n * target)
// =================================================================

class TabulationSolution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int target = 0;
        for(int i = 0; i < n; i++)
            target += nums[i];

        if(target % 2 == 1)
            return false;

        target /= 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        dp[0][0] = 1;

        if(nums[0] <= target)
            dp[0][nums[0]] = 1;

        for(int idx = 1; idx < n; idx++){
            for(int tar = 0; tar <= target; tar++){

                bool take = false;

                if(nums[idx] <= tar)
                    take = dp[idx-1][tar-nums[idx]];

                bool notTake = dp[idx-1][tar];

                dp[idx][tar] = take || notTake;
            }
        }

        return dp[n-1][target];
    }
};


// =================================================================
// 4. SPACE OPTIMIZED TABULATION
// =================================================================
//
// Time  : O(n * target)
// Space : O(target)
// =================================================================

class SpaceOptimizedSolution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int target = 0;
        for(int i = 0; i < n; i++)
            target += nums[i];

        if(target % 2 == 1)
            return false;

        target /= 2;

        vector<int> prev(target + 1, 0);

        prev[0] = 1;

        if(nums[0] <= target)
            prev[nums[0]] = 1;

        for(int idx = 1; idx < n; idx++){

            vector<int> curr(target + 1, 0);

            for(int tar = 0; tar <= target; tar++){

                bool take = false;

                if(nums[idx] <= tar)
                    take = prev[tar-nums[idx]];

                bool notTake = prev[tar];

                curr[tar] = take || notTake;
            }

            prev = curr;
        }

        return prev[target];
    }
};
