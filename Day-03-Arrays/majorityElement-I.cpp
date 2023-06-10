class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // it is given than majority element is present n/2 times atleast
        // so we can start finding it by assuming any no. major 
        // if it is major we can count it occurrence 
        // if not than count-- if curr major count becomes 0 than update the major
        // as we dont have to give count we are only focused in finding major not how many times it is present
        // so in this way we will be facing major elements maxm times and it will come in front as major 
        int major=nums[0],count=1;
        for(int i=1;i<nums.size();i++){
            // if count is 0 you are not major , check for next one
            if(count==0){
                count++;
                major=nums[i];
            }
            // count++ it can be major
            else if(nums[i]==major){
                count++;
            }
            // if neither it is major nor its count is 0 than reduce it count only 
            // it may or may not the major element
            else {
                 count--;
            }
           
        } return major;
       
    }
};