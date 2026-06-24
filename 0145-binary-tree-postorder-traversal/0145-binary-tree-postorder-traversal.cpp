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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        stack<TreeNode*> st;
        st.push(root);
        vector<int> traversal;
        while(!st.empty()){
            TreeNode* node=st.top();
            st.pop();
            traversal.push_back(node->val);
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }
        reverse(traversal.begin(),traversal.end());
        return traversal;
    }
};