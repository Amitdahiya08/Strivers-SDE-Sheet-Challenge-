class Solution {
public:
    int helper(vector<int>& nums, int master, int ind){
        int ans=ind;
        for(int i=ind+1;i<nums.size();i++){
            if(nums[i]>master && nums[i]<nums[ans] )ans=i;
        }
        return ans;
    }
    void nextPermutation(vector<int>& nums) {
        // starting from back and checking for the break point
        for(int i=nums.size()-1;i>=1;i--){
            // if such place exist where we can interchange digits
            if(nums[i]>nums[i-1]){
                // find the suitable ind where element is ->JUST<-  bigger than nums[i-1]
                int ind=helper(nums,nums[i-1],i);
                // swap both
                swap(nums[ind],nums[i-1]);
                // sort remaining array to get min possible no.
                sort(nums.begin()+i,nums.end());
                return ;
            }
        }
        // if the no. is itself max and no rearraning letters can make it bigger
        // make it min(given in question )
        sort(nums.begin(),nums.end());
        return;
    }
};