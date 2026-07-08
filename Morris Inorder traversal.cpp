class Solution {
  public:
    vector<int> inOrder(Node* root) {
        // code here
        Node *curr=root;
        vector<int> ans;
        while(curr){
            //Left part don't exist
            if(curr->left==NULL){
                ans.push_back(curr->data);
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
                    ans.push_back(curr->data);
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};
