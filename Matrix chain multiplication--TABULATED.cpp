#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        
        int N = arr.size();
        vector<vector<int>> dp(N, vector<int>(N, 0));
    
        for (int i = N - 1; i >= 1; i--) {
            for (int j = i + 1; j < N; j++) {
                int mini = 1e9;
    
                for (int k = i; k < j; k++) {
                    int steps = arr[i - 1] * arr[k] * arr[j]
                              + dp[i][k]
                              + dp[k + 1][j];
    
                    if (steps < mini)
                        mini = steps;
                }
    
                dp[i][j] = mini;
            }
        }
    
        return dp[1][N - 1];
    }

};




int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i=0; i<n; i++) cin >> nums[i];
        Solution ob;
        int s = ob.matrixMultiplication(nums);
        cout << s << endl;
    }
    return 0;
}


/*
Time Complexity: O(n*n*n)
Space Complexity: O(n*n)
*/