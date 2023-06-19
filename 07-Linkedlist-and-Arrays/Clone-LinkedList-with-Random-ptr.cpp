/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       Node*temp=head;
       unordered_map<Node*,Node*>set;

       while(temp!=NULL){
        //    creating a deep copy of node
           Node* curr= new Node(temp->val);
        //    storing it into hashmap as key to temp node
           set[temp]=curr;
           temp=temp->next;
       } 
       //  now all deep copies are created lets link them 
         temp=head;
         Node* ans= set[head];
        while(temp!=NULL){
            ans=set[temp];
            ans->next=set[temp->next];
            if(temp->random!=NULL)ans->random=set[temp->random];
            temp=temp->next;
            ans=ans->next;
        }
        return set[head];
    }
};