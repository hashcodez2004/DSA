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

struct Info{
    bool isBST;
    int sum;
    int mini;
    int maxi;
};

class Solution {
public:
    Info helper(TreeNode* root, int &maxSum){
        if(root == NULL) return {true, 0, INT_MAX, INT_MIN};
        if(root->left == NULL && root->right == NULL) return {true, root->val, root->val, root->val};
        
        Info left = helper(root->left, maxSum);
        Info right = helper(root->right, maxSum);

        maxSum = max({maxSum, left.sum, right.sum});

        if(left.isBST && right.isBST){
            if(root->val > left.maxi &&
               root->val < right.mini){
                return {
                    true,
                    left.sum + right.sum + root->val,
                    min(root->val, left.mini),
                    max(root->val, right.maxi)
                };
            }
        }
        return {false, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        int maxi = 0;
        auto ans = helper(root, maxi);
        maxi = max(maxi, ans.sum);
        return maxi;
    }
};