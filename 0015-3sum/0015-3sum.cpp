class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n-2; i++) {
            if(arr[i]>0) break;  //early breaking
            //moving ahead to remove duplicates:
            if (i != 0 && arr[i] == arr[i - 1]) continue;
            // moving 2 pointers:
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum < 0) j++;
                else if (sum > 0) k--;
                else {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    // skip the duplicates:
                    while (j < k && arr[j] == arr[j - 1]) j++;
                    while (j < k && arr[k] == arr[k + 1]) k--;
                }
            }
        }
        return ans;
    }
};


// Time Complexity: 
//  - Sorting: O(n log n)
//  - Outer loop (i): O(n)
//  - Inner two-pointer scan: near about O(n) per i
//  => Overall: O(n^2)
//
// Space Complexity:
//  - O(1) auxiliary (sorting done in-place)
//  - O(k) for storing output triplets (k = number of valid triplets, worst O(n^2))
