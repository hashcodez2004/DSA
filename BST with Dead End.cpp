class Solution {
  public:
    bool isLeaf(Node* root){
        return (root->left==NULL && root->right==NULL);
    }
  
    bool helper(Node* root, int lowerBound, int upperBound){
        if(root==NULL) return false;
        if(isLeaf(root)){
            if(root->data-lowerBound==1 && upperBound-root->data==1) return true;
            else return false;
        }
        return (helper(root->left,lowerBound,root->data) || helper(root->right,root->data,upperBound));
    }
  
    bool isDeadEnd(Node *root) {
        // Code here
        return helper(root,0,INT_MAX);
    }
};