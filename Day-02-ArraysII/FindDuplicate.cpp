class Solution {
public:
    int floydSolution(vector<int>& nums) {
         int slow = nums[0];
         int fast = nums[0];
    // we are intilalisng both from same points 
    // so to execute first loop either start them from diffrent points 
    // or use do while loop , otherwise the loop will not execute as the are already equal
    // Cycle detection phase
    while (true) {
        slow = nums[slow];
        fast = nums[nums[fast]];
        if (slow == fast)
            break;
    }

    fast = nums[0];

    // Finding intersection point
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
    }
    int findDuplicate(vector<int>& nums) {
        return floydSolution(nums);
    }
};