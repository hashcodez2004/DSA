/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  private:
    TreeNode* helper(int idx, int start, int end, vector<int> &inorder, vector<int> &postorder, unordered_map<int,int>& mpp){
        if(start>end) return NULL;
        TreeNode* root = new TreeNode(postorder[idx]);
        int pos = mpp[postorder[idx]];
        root->left = helper(idx-(end-pos)-1,start,pos-1,inorder,postorder,mpp);
        root->right = helper(idx-1,pos+1,end,inorder,postorder,mpp);
        return root;
    }
    
  public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // code here
        int n=inorder.size();
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++) mpp[inorder[i]] = i;
        TreeNode* root = helper(n-1,0,n-1,inorder,postorder,mpp);
        return root;
    }
};