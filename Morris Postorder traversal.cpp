class Solution {
  public:
    vector<int> postOrder(Node* root) {
        // code here
        Node *curr=root;
        vector<int> ans;
        while(curr){
            //Right part don't exist
            if(curr->right==NULL){
                ans.push_back(curr->data);
                curr=curr->left;
            }
            
            //Right part exists
            else{
                Node* temp=curr->right;
                while(temp->left!=NULL && temp->left!=curr) temp=temp->left;
                
                //Right subtree not traversed
                if(temp->left!=curr){
                    ans.push_back(curr->data);
                    temp->left=curr;
                    curr=curr->right;
                }
                //Right subtree already traversed
                else{
                    temp->left==NULL;
                    curr=curr->left;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};