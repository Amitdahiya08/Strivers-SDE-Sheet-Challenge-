
/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
   vector<int>nums;
   Node* head=root;
   while(head!=NULL){
       Node* temp=head;
       while(temp!=NULL){
           nums.push_back(temp->data);
           temp=temp->bottom;
       }
       head=head->next;
   }
   sort(nums.begin(),nums.end());
	Node* ans = new Node(nums[0]);
	Node* current = ans;
	for (int i = 1; i < nums.size(); i++) {
		current->bottom = new Node(nums[i]);
		current = current->bottom;
	}

	return ans;

}