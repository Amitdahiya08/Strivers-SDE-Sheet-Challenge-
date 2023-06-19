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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // iterative approach another approach is using recursion(similar to mergesort)
        // time complexity is O(m+n)
        ListNode* head;
        if(list1!=NULL && list2!=NULL){
            if(list1->val <= list2->val) {
                head=list1;
                list1=list1->next;
            }
            else {
                head= list2;
                list2=list2->next;
            }
        }
        else if(list1==NULL) return list2;
        else if(list2==NULL) return list1;
        ListNode* ans=head;
        head->next=NULL;
        while(list1 !=NULL && list2!=NULL){

            int a=list1->val;
            int b=list2->val;
            if(a<=b){
                head->next=list1;
                list1=list1->next;
            }
            else{
                head->next=list2;
                list2=list2->next;
            }
            head=head->next;
        }
        if(list1==NULL) head->next=list2;
        else if(list2==NULL) head->next=list1;
        return ans;
    }
};