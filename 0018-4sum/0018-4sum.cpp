class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());

        for (int a = 0; a < n - 3; a++) {
            if (a > 0 && arr[a] == arr[a - 1]) continue;  // skip duplicates

            for (int b = a + 1; b < n - 2; b++) {
                if (b > a + 1 && arr[b] == arr[b - 1]) continue;  // skip duplicates

                int c = b + 1, d = n - 1;
                while (c < d) {
                    long long sum = 1LL * arr[a] + arr[b] + arr[c] + arr[d];  // cast to long long
                    
                    if (sum < target) c++;
                    else if (sum > target) d--;
                    else {
                        ans.push_back({arr[a], arr[b], arr[c], arr[d]});
                        c++, d--;
                        while (c < d && arr[c] == arr[c - 1]) c++;
                        while (c < d && arr[d] == arr[d + 1]) d--;
                    }
                }
            }
        }
        return ans;
    }
};
