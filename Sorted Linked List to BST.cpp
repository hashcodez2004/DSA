/* structure of Linked List Node
class LNode {
public:
    int data;
    LNode* next;

    LNode(int x) {
        data = x;
        next = nullptr;
    }
};

// Tree Node
class TNode {
public:
    int data;
    TNode* left;
    TNode* right;

    TNode(int x) {
        data = x;
        left = right = nullptr;
    }
};*/


//                    TC: O(NlogN) => computing mid for every recursive call    SC: O(logN) => recursion stack space
class Solution {
  public:
    TNode* helper(LNode* start, int n){
        if(n==1){
            TNode* root=new TNode(start->data);
            return root;
        }
        
        int mid=n/2 + 1;
        LNode* temp=start;
        for(int i=1;i<mid;i++) temp=temp->next;
        
        TNode* root=new TNode(temp->data);
        int left=mid-1;
        int right=n-mid;
        
        if(left!=0) root->left=helper(start,left);
        if(right!=0) root->right=helper(temp->next,right);
        
        return root;
    }
  
    TNode *sortedListToBST(LNode *head) {
        // code here
        int n=0;
        LNode* temp=head;
        while(temp){
            n++;
            temp=temp->next;
        }
        
        return helper(head,n);
    }
};




//            TC: O(N) => computing mid for every recursive call    SC: O(N + logN) => Vector + recursion stack space
class Solution {
  public:
    TNode* helper(vector<int>& v, int start, int end){
        if(start > end) return NULL;
    
        int mid = (start + end + 1) / 2;
    
        TNode* root = new TNode(v[mid]);
    
        root->left = helper(v, start, mid - 1);
        root->right = helper(v, mid + 1, end);
    
        return root;
    }
  
    TNode *sortedListToBST(LNode *head) {
        // code here
        vector<int> v;
        LNode* temp=head;
        while(temp){
            v.push_back(temp->data);
            temp=temp->next;
        }
        
        return helper(v,0,v.size()-1);
    }
};