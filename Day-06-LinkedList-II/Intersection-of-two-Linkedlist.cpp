/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* l1=headA;
        ListNode* l2=headB;
        if(l1==NULL || l2==NULL)return NULL;
        // if lengths of lists are not equal the loop will execute once until 
        //  both the var list switch their respective lists and starts from same point 
        // for eg both l2 starts from a1 and l1 starts from b2 ( (see in pic of ques)they have switched )
        while(l1!=l2){
            l1= (l1==NULL)? headB : l1->next;
            l2 = (l2==NULL)? headA : l2->next;
        }
        return l1;
    }
};