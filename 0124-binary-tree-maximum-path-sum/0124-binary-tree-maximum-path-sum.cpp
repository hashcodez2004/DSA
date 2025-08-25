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
    int helper(TreeNode* root, int& sum){
        if(root==NULL) return 0;
        //left
        int leftSum = max(0, helper(root->left,sum));
        //right
        int rightSum = max(0 ,helper(root->right,sum));
        
        sum = max(sum, leftSum+rightSum+root->val);
        return root->val + max(leftSum,rightSum);
    }

public:
    int maxPathSum(TreeNode* root) {
        int sum = -1e9;
        helper(root,sum);
        return sum;
    }
};