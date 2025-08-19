//Much Cleaner and Good Practices

class Solution {
private:
    void merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp; 
        int left = low, right = mid + 1;

        // merge two sorted halves
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left++]);
            } else {
                temp.push_back(arr[right++]);
            }
        }

        // leftover elements from left half
        while (left <= mid) {
            temp.push_back(arr[left++]);
        }

        // leftover elements from right half
        while (right <= high) {
            temp.push_back(arr[right++]);
        }

        // copy sorted elements back
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    int countPairs(vector<int> &arr, int low, int mid, int high) {
        int cnt = 0, right = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (right <= high && 1LL * arr[i] > 2LL * arr[right]) right++;
            cnt += (right - (mid + 1));
        }
        return cnt;
    }

    int mergeSort(vector<int> &arr, int low, int high) {
        if (low >= high) return 0;
        int mid = (low + high) / 2;

        int cnt = 0;
        cnt += mergeSort(arr, low, mid);       // left half
        cnt += mergeSort(arr, mid + 1, high);  // right half
        cnt += countPairs(arr, low, mid, high); // count reverse pairs
        merge(arr, low, mid, high);            // merge sorted halves
        return cnt;
    }

public:
    int reversePairs(vector<int> &arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};