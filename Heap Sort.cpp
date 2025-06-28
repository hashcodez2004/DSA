#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    //Heapify method to build a max heap
    void heapify(vector<int>& nums, int i, int n){
        int maxii=i;
        int left=2*i + 1;
        int right=2*i + 2;
        
        if(left<n && nums[maxii]<nums[left]) maxii=left;
        if(right<n && nums[maxii]<nums[right]) maxii=right;
        
        //If parent is not the larget
        if(maxii != i){
            swap(nums[maxii], nums[i]);
            heapify(nums,maxii,n);
        }
    }
  
  public:
    // Function to sort an array using Heap Sort.
    void heapSort(vector<int>& nums) {
        // code here
        int n = nums.size();
        //Build max heap
        for(int i=(n/2)-1; i>=0; i--) heapify(nums,i,n);
        //heap sort
        while(n>0){
            swap(nums[0],nums[n-1]);
            n--;
            heapify(nums,0,n);
        }
    }
};

void print(vector<int>& v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        Solution obj;
        obj.heapSort(v);
        print(v);
    }
    return 0;
}


/*
Time Complexity: O(n) + O(nlogn) = O(nlogn)
[n for building heap, nlogn for heap sort]

Space Complexity: O(log n)
[recursive heapify stack, in worst case]
*/
