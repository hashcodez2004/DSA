class Solution {
public:
    int threeSumClosest(vector<int>& arr, int target) {
        int n = arr.size();
        int ans = arr[0] + arr[1] + arr[2];
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n-2; i++) {
            //moving ahead to remove duplicates:
            if (i != 0 && arr[i] == arr[i - 1]) continue;
            // moving 2 pointers:
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = arr[i] + arr[j] + arr[k];
                if (abs(sum - target) < abs(ans - target)) ans = sum;
                if (sum < target) j++;
                else if (sum > target) k--;
                else return sum;
            }
        }
        return ans;
    }
};