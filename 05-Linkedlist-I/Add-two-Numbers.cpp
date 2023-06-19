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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // if any of node is null return 2nd one
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        ListNode* temp = new ListNode(0);
        ListNode* ans=temp;
        int carry=0;
        while(l1!=NULL || l2!=NULL){
            int sum=0;
            if(l1!=NULL) sum +=l1->val;
            if(l2!=NULL) sum +=l2->val;
            if(carry!=0) sum +=carry;
            if(sum>9) {
                carry =sum/10;
                sum =sum%10;
            }
            else carry=0;
            temp->next= new ListNode(sum%10);
            temp=temp->next;
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }
        // if after addtion of both numbers carry!=0
        if(carry!=0) temp->next=new ListNode(carry);
        return ans->next;
    }
};