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
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;
        traversal(root,0,view);
        return view;
    }

    void traversal(TreeNode* root, int level, vector<int> &view){
        if(root==NULL) return;
        if(level==view.size()) view.push_back(root->val);
        traversal(root->right,level+1,view);
        traversal(root->left,level+1,view);
    }
};