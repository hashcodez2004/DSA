class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        const int MOD = 1e9 + 7;
        long long totSwaps = 0;
        int n = nums.size();

            // FIRST PART

        int nextLowPos = 0; // Position where next Low element should be placed
        for(int currIdx = 0; currIdx < n; currIdx++){
            if(nums[currIdx] < a){
                totSwaps += currIdx - nextLowPos;
                nextLowPos++;
            }
        }

                // SECOND PART

        int nextHighPosition = n - 1; // Position where next High element should be placed
        int lowElemSeen = 0; // Number of Low elements seen while traversing from right to left
        for(int currIdx = n - 1; currIdx >= 0; currIdx--){
            if(nums[currIdx] < a){
                lowElemSeen++;
            }
            else if(nums[currIdx] > b){
                totSwaps += nextHighPosition - currIdx - lowElemSeen;
                nextHighPosition--;
            }
        }

        return totSwaps % MOD;
    }
};

/*
Minimum adjacent swaps = Total distance travelled by elements.
Instead of actually swapping elements, we directly count how many positions each element needs to move.
Relative order of elements belonging to the same group never changes.
A stable partition always gives the minimum number of adjacent swaps.

First pass: Move all elements < a to the front.
For every Low element, (current index - target index) gives its swap contribution.

Second pass: Move all elements > b to the end.
Subtract Low elements already crossed, since those swaps were counted in the first pass.


Time Complexity: O(2n)
Space Complexity: O(1)
*/