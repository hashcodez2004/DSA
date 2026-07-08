class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node *curr=root;
        vector<Node*> ans(2);
        ans[0]=NULL;
        ans[1]=NULL;
        while(curr){
            //Left part don't exist
            if(curr->left==NULL){
                if(curr->data < key) ans[0] = curr;
                if(ans[1] == NULL && curr->data > key) ans[1] = curr;
                curr=curr->right;
            }
            
            //Left part exists
            else{
                Node* temp=curr->left;
                while(temp->right!=NULL && temp->right!=curr) temp=temp->right;
                
                //Left subtree not traversed
                if(temp->right!=curr){
                    temp->right=curr;
                    curr=curr->left;
                }
                //Left subtree already traversed
                else{
                    temp->right=NULL;
                    if(curr->data < key) ans[0] = curr;
                    if(ans[1] == NULL && curr->data > key) ans[1] = curr;
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};