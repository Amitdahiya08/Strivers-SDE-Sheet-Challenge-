
class Solution {
public:
    void deleteNode(ListNode* Node) {
       Node->val=Node->next->val;
       Node->next=Node->next->next;
    }
};