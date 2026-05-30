class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> pq; // {val, pointer to current node}

        for(int i=0;i<k;i++){
            if(lists[i]!=NULL) pq.push({lists[i]->val, lists[i]});
        }

        ListNode *dummy = new ListNode(-1);
        ListNode *head=dummy;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();

            dummy->next=it.second;
            dummy=dummy->next;

            if(it.second->next!=NULL) pq.push({it.second->next->val,it.second->next});
        }

        return head->next;
    }
};

/*
TC: O(N log K)
SC: O(K)

N = total number of nodes across all linked lists
K = number of linked lists
*/