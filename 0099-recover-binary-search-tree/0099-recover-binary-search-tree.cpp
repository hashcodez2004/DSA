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
    void recoverTree(TreeNode* root) {
        TreeNode* first=NULL;
        TreeNode* second=NULL;
        TreeNode* prev=NULL;

        while(root){
            //left exists
            if(root->left!=NULL){
                TreeNode* temp=root->left;
                while(temp->right!=NULL && temp->right!=root) temp=temp->right;

                //not traversed
                if(temp->right==NULL){
                    temp->right=root;
                    root=root->left;
                }

                //already traversed
                else{
                    if(prev!=NULL && prev->val > root->val){
                        if(first==NULL){
                            first=prev;
                            second=root;
                        }
                        else second=root;
                    }
                    prev=root;
                    root=root->right;
                    temp->right=NULL;
                }
            }

            //left doesn't exists
            else{
                if(prev!=NULL && prev->val > root->val){
                    if(first==NULL){
                        first=prev;
                        second=root;
                    }
                    else second=root;
                }
                prev=root;
                root=root->right;
            }
        }

        swap(first->val,second->val);
    }
};