#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    int helper(int i, int j, vector<int> &nums){
        if(i==j) return 0;
        int mini = 1e9;
        for(int k=i; k<=j-1; k++){
            int ans = nums[i-1]*nums[k]*nums[j] + helper(i,k,nums) + helper(k+1,j,nums);    //nums[i-1]*nums[k]*nums[j] are the no of multiplications required
            mini = min(mini,ans);                                                           //Aur in individual partitions me kitne multiplications lgenge uske liye fn call
        }
        return mini;
    }
    
  public:
    int matrixMultiplication(vector<int> &nums) {
        // code here
        int n = nums.size();
        return helper(1,n-1,nums);
    }
};

/*
DRY RUN => [10 20 30 40 50]

f(1, 4)
├── k = 1
│   ├─ f(1,1) = 0
│   └─ f(2,4)
│       ├── k = 2
│       │   ├─ f(2,2) = 0
│       │   └─ f(3,4)
│       │       ├── k = 3
│       │       │   ├─ f(3,3) = 0
│       │       │   └─ f(4,4) = 0
│       │       └─ cost = 30*40*50 = 60000
│       └─ cost = 20*30*50 + 60000 = 30000 + 60000 = 90000
├── total = 10*20*50 + 90000 = 10000 + 90000 = 100000

├── k = 2
│   ├─ f(1,2)
│   │   ├─ f(1,1) = 0
│   │   └─ f(2,2) = 0
│   │   └─ cost = 10*20*30 = 6000
│   └─ f(3,4)
│       ├─ f(3,3) = 0
│       └─ f(4,4) = 0
│       └─ cost = 30*40*50 = 60000
├── total = 6000 + 60000 + 10*30*50 = 6000 + 60000 + 15000 = 81000

├── k = 3
│   ├─ f(1,3)
│   │   ├── k = 1
│   │   │   ├─ f(1,1) = 0
│   │   │   └─ f(2,3)
│   │   │       ├── f(2,2) = 0
│   │   │       └─ f(3,3) = 0
│   │   │       └─ cost = 20*30*40 = 24000
│   │   └─ cost = 10*20*40 + 24000 = 8000 + 24000 = 32000
│   │
│   │   ├── k = 2
│   │   │   ├─ f(1,2)
│   │   │   │   ├─ f(1,1) = 0
│   │   │   │   └─ f(2,2) = 0
│   │   │   │   └─ cost = 10*20*30 = 6000
│   │   │   └─ f(3,3) = 0
│   │   │   └─ cost = 10*30*40 + 6000 = 12000 + 6000 = 18000
│   │
│   │   └─ f(1,3) = min(32000, 18000) = 18000
│   └─ f(4,4) = 0
├── total = 18000 + 10*40*50 = 18000 + 20000 = 38000

Final Minimum = min(100000, 81000, 38000) = ✅ **38000**

*/


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
Time Complexity: exponential
Space Complexity: O(n)
*/
