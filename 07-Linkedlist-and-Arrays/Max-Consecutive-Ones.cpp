class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count1=0,count2=0;
       for(int i=0;i<nums.size();i++){
           if(nums[i]==1){
               count1++;
           }
           else {
               count2=max(count2,count1);
               count1=0;
           }
       }return max(count2,count1);
    }
};