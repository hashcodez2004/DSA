class Solution {
  private:
    int burn(Node* root, int& time, int target, Node* &tarNode){
        if(root==NULL) return 0;
        
        //updating the target node
        if(root->data==target){
            tarNode=root;
            return -1;
        }
        
        int lft=burn(root->left,time,target,tarNode);
        int rgt=burn(root->right,time,target,tarNode);
        
        //burn coming from left
        if(lft<0){
            time=max(time, abs(lft)+rgt);
            return lft-1;
        }
        
        //burn coming from right
        if(rgt<0){
            time=max(time, abs(rgt)+lft);
            return rgt-1;
        }
        
        //neither side burn
        return 1+max(lft,rgt);
    }
    
    int height(Node* root){
        if(root==NULL) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    
  public:
    int minTime(Node* root, int target) {
        // code here
        //MAIN IDEA IS TO FIND THE LONGEST LENGTH WHERE BURN HAS TO REACH
        int time=0;
        Node* tarNode; //avoiding separate computing tarNode
        burn(root,time,target,tarNode);
        int ht=height(tarNode);
        return max(time,ht-1);
    }
};



/*
 => No parent map and visited map used

 TC: O(N) + O(N)
 SC: O(N)
*/