class Solution {
public:
    TreeNode* prev = nullptr;

    bool isBST(TreeNode* root) {
        if(root == nullptr)
            return true;

        if(!isBST(root->left))
            return false;

        if(prev != nullptr && root->val <= prev->val)
            return false;

        prev = root;

        return isBST(root->right);
    }

    bool isValidBST(TreeNode* root) {
        return isBST(root);
    }
};