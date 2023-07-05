int singleNonDuplicate(vector<int>& nums)
{
	// 
	 // the binary search idea is input-> [1,1,2,2,3,4,4,5,5]
    //  we know that the even index (0,2,4,6,8) 
        // will be the number itself and the odd index (1,3,5,7) will its duplicate
        //  the only place from where this thing will not be followed is the unique number index
        int start=0;
        int end=nums.size()-2;
        while(start<=end){
            int mid= (start + end)/2;
            if(nums[mid]==nums[mid^1]){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        } 
        return nums[start];
}