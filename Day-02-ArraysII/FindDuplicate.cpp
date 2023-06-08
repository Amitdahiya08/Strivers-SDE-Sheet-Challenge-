class Solution {
public:
    int floydSolution(vector<int>& nums) {
        int slow = nums[0], fast = nums[nums[0]];
        // occurence of duplicate in 1,n means there must be a cycle 
        // finding the cycle using slow and fast 
        while(slow!=fast){
            slow= nums[slow];
            fast=nums[nums[fast]];
        }
        // kept one pointer at the cross-section of both and reset second one to 0 
        fast=0;
        // now where they will meet again is the duplicate number 
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        // return slow or fast 
        return slow;
    }
    int findDuplicate(vector<int>& nums) {
        return floydSolution(nums);
    }
};