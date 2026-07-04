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
    int idx=0;

    TreeNode* helper(int mini, int maxi, vector<int>& preorder){
        if(idx==preorder.size()) return NULL;
        if(preorder[idx]<=mini || preorder[idx]>=maxi) return NULL;
        TreeNode* root = new TreeNode(preorder[idx]);
        idx++;
        root->left = helper(mini,root->val,preorder);
        root->right = helper(root->val,maxi,preorder);
        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = helper(INT_MIN,INT_MAX,preorder);
        return root;
    }
};