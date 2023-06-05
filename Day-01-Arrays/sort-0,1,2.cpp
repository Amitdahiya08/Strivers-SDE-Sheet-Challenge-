class Solution {
public:
    void sortColors(vector<int>& nums) {
       // BRUTE FORCE -> just count 0,1,2 
       // or 3 pointer (dutch flag algorithm)
    //     if found 0 shift it to start and start++
    //  if found 2 shift it to end and end--
    //  1 will be arranged automatcially
       int i=0; 
       int low=0; 
       int high=nums.size()-1;
         while(i<=high){
           if(nums[i]==0){
               swap(nums[i],nums[low]);
               low++;
               i++;
           }
           else if(nums[i]==2){
               swap(nums[i],nums[high]);
               high--;
           }
           else i++;
       }
    }
};