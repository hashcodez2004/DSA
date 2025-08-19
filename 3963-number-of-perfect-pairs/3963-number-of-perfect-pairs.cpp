class Solution {
public:
    long long perfectPairs(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) arr[i] = abs(arr[i]);
        sort(arr.begin(), arr.end());

        long long cnt = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < n && arr[j] <= 2LL * arr[i]) j++;
            cnt += (j - i - 1); 
        }
        return cnt;
    }
};
