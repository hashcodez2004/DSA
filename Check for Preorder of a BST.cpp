class Solution {
public:
    int idx = 0;

    void helper(int mini, int maxi, vector<int>& arr) {

        if(idx == arr.size())
            return;

        if(arr[idx] <= mini || arr[idx] >= maxi)
            return;

        int val = arr[idx];
        idx++;

        helper(mini, val, arr);
        helper(val, maxi, arr);
    }

    bool canRepresentBST(vector<int>& arr) {

        idx = 0;

        helper(INT_MIN, INT_MAX, arr);

        return idx == arr.size();
    }
};

//Previous ques logic used

/*
Construct Binary Search Tree from Preorder Traversal........

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int data) {
        val = data;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    int idx = 0;
  
    Node* helper(int mini, int maxi, vector<int>& arr){
        if(idx==arr.size()) return NULL;
        if(arr[idx]<=mini || arr[idx]>=maxi) return NULL;
        Node* root = new Node(arr[idx]);
        idx++;
        root->left = helper(mini,root->val,arr);
        root->right = helper(root->val,maxi,arr);
        return root;
    }
  
    bool canRepresentBST(vector<int> &arr) {
        // code here
        Node* root = helper(INT_MIN,INT_MAX,arr);
        return idx==arr.size();
    }
};
*/