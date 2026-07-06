/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val>p->val && root->val<q->val) return root;
        if(root==p || root==q) return root;
        if(q->val<root->val) return helper(root->left,p,q);
        else return helper(root->right,p,q);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val<q->val) return helper(root,p,q);
        return helper(root,q,p);
    }
};