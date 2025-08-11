/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* KthNode(ListNode* head, int k) {
        while(--k){
            if(head==NULL) return NULL;
            head=head->next;
        }
        return head;
    }

    ListNode* reverse(ListNode* head) {
        ListNode *prevNode=NULL, *temp=head;
        while(temp!=NULL){
            ListNode* nextNode=temp->next;
            temp->next=prevNode;
            prevNode=temp;
            temp=nextNode;
        }
        return prevNode;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            ListNode* kNode=KthNode(temp,k);  //finding the Kth node (null if not exists)
            if(kNode==NULL){
                if(prev!=NULL) prev->next=temp;
                return head;
            }
            if(temp==head) head=kNode;     //first set (here mark newHead of the linked list)
            ListNode* front=kNode->next;
            kNode->next=NULL;
            ListNode* newHead=reverse(temp);   //reversing the newly made linked list;
            if(prev!=NULL) prev->next=newHead;
            prev=temp;
            temp=front;
        }
        return head;
    }
};