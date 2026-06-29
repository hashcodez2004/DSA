class Solution {
  private:
    int helper(Node* root, int &maxi){
        if(root==NULL) return 0;
        
        int left=helper(root->left,maxi);
        int right=helper(root->right,maxi);
        
        //No special node on one of the side
        if(root->left==NULL || root->right==NULL) return left+right+root->data;
        //Special node on both sides
        if(root->left!=NULL && root->right!=NULL) maxi=max(maxi, left+right+root->data);
        return max(left+root->data,right+root->data);
    }
    
  public:
    int maxPathSum(Node* root) {
        // code here
        if(root==NULL) return 0;
        int maxi=INT_MIN;
        int ans = helper(root,maxi);
        //if root itself is special node
        if(root->left==NULL || root->right==NULL) return max(maxi,ans);
        return maxi;
    }
};