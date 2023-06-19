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
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || n==0)return head;
        ListNode * start = new ListNode();
        start -> next = head;
        ListNode* fast = start;
        ListNode* slow = start; 
        // lets move the fast n steps from start
        for(int i=0;i<n;++i){
            fast=fast->next;
        }
        // now they have gap of n nodes in between them move them till the fast meets the end node
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        // now have to delete the next node of slow 
        slow->next=slow->next->next;
        // return head stored in start->next
        return start->next;
    }
};