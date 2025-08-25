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
    int maxDepth(TreeNode* root, int& maxii) {
        if(root==NULL) return 0;
        //left
        int lh = maxDepth(root->left,maxii);
        //right
        int rh = maxDepth(root->right,maxii);
        maxii=max(maxii,lh+rh);
        return 1 + max(lh,rh);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxii = 0;
        maxDepth(root,maxii);
        return maxii;
    }
};