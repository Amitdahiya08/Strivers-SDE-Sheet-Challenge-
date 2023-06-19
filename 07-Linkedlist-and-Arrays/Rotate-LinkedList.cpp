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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0)return head;
        ListNode* temp=head;
        int len=0;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        while(k>len){
            k-=len;
        }
        if(k==len)return head;
        cout<<k;
        //  now we need to shift k elements from back to front 
        //  or you can say the kth element will be head and the last element will connect to prevhead
        ListNode* temp2=head;
        // total elements from first we need to travel to reach the afterhead
        int n=len-k-1;
        while(n>0){
            temp2=temp2->next;
            n--;
        }
        // saving new head to return in ans
        ListNode* ans=temp2->next;
        temp2->next=NULL;
        temp2=ans;
        // now travelling to the end node so that we can connect the front part at end
        while(temp2->next!=NULL){
            temp2=temp2->next;
        }
        temp2->next=head;
        return ans;
    }
};