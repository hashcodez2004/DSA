/*
TC: O(N)  SC: O(H)
*/

class Solution {
public:
    TreeNode* first=NULL;
    TreeNode* second=NULL;
    TreeNode* prev=NULL;
  
    void traversal(TreeNode* root){
        if(root==NULL) return;
        traversal(root->left);
        if(prev!=NULL && prev->val > root->val){
            if(first==NULL){
                first=prev;
                second=root;
            }
            else second=root;
        }
        prev=root;
        traversal(root->right);
    }
  
    void recoverTree(TreeNode* root) {
        traversal(root);
        swap(first->val,second->val);
    }
};

/*
TC: O(N)  SC: O(1) => Morris Inorder Traversal
*/


class Solution {
public:
    void process(TreeNode*& prev, TreeNode*& first, TreeNode*& second, TreeNode* root){
        if(prev!=NULL && prev->val > root->val){
            if(first==NULL){
                first=prev;
                second=root;
            }
            else second=root;
        }
        prev=root;
    }

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
                    temp->right=NULL;
                    process(prev,first,second,root);
                    root=root->right;
                }
            }

            //left doesn't exists
            else{
                process(prev,first,second,root);
                root=root->right;
            }
        }

        swap(first->val,second->val);
    }
};