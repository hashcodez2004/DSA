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
    TreeNode* helper(int idx, int start, int end, vector<int> &inorder, vector<int> &preorder, unordered_map<int,int>& mpp){
        if(start>end) return NULL;
        TreeNode* root = new TreeNode(preorder[idx]);
        int pos = mpp[preorder[idx]];
        root->left = helper(idx+1,start,pos-1,inorder,preorder,mpp);
        root->right = helper(idx+pos-start+1,pos+1,end,inorder,preorder,mpp);
        return root;
    }
    
  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // code here
        int n=inorder.size();
        unordered_map<int,int> mpp;
        for(int i=0;i<n;i++) mpp[inorder[i]] = i;
        TreeNode* root = helper(0,0,n-1,inorder,preorder,mpp);
        return root;
    }
};