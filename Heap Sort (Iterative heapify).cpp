class Solution {
  private:
    void heapify(vector<int> &arr, int idx, int n){
        while(true){
            int largest=idx;
            int left=2*idx+1;
            int right=2*idx+2;
            
            if(left<n && arr[left]>arr[largest]) largest=left;
            if(right<n && arr[right]>arr[largest]) largest=right;
            
            if(largest==idx) break;
            
            if(largest!=idx){
                swap(arr[largest],arr[idx]);
                heapify(arr,largest,n);
            }
        }
    }
    
    void buildMaxHeap(vector<int> &arr){
        int n=arr.size();
        for(int i=n/2-1;i>=0;i--) heapify(arr,i,n);
    }
    
  public:
    void heapSort(vector<int>& arr) {
        int n=arr.size();
        
        buildMaxHeap(arr);
        
        for(int i = n-1; i > 0; i--){
            swap(arr[0], arr[i]);
            heapify(arr, 0, i);
        }
    }
};


/*
Time Complexity: O(n) + O(nlogn) = O(nlogn)
[n for building heap, nlogn for heap sort]

Space Complexity: O(1)
*/