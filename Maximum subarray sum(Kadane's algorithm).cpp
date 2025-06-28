#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSubarraySum(vector<int>& arr) {
        int n = arr.size();
        int maxSum = arr[0];
        int currSum = arr[0];
    
        for (int i = 1; i < n; i++) {
            currSum = max(arr[i], currSum + arr[i]);
            maxSum = max(maxSum, currSum);
        }
    
        return maxSum;
    }

};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        Solution obj;
        int res = obj.maxSubarraySum(v);
        cout<<res<<endl;
    }
    return 0;
}


/*
Time Complexity: O(n)
 - We traverse the array only once.

Space Complexity: O(1)
 - No extra space is used except variables for sum tracking.
*/
