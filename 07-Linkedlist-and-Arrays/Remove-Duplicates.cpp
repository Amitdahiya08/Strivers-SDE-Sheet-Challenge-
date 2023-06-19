class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0;
        for(int i=0;i<nums.size();i++){
            while(i+1 <nums.size() && nums[i]==nums[i+1]){
                i++;
            } 
            nums[k]=nums[i];
            k++;
        } return k;
    }
};