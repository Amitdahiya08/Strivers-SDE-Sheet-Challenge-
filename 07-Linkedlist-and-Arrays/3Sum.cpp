class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            // fixing ith element and than creating a window from start to end to find pair
            int start=i+1;
            int end=n-1; 
            if(i>0 && nums[i]==nums[i-1])continue;
            while(start<end){
                long long sum= nums[i] + nums[start] +  nums[end];
                if(sum==0){
                    ans.push_back({nums[i],nums[start],nums[end]});
                    // now skip all duplicate elements which are same as start and end
                    while(start<end && nums[start]==nums[start+1])start++;
                    while(start<end && nums[end]==nums[end-1])end--;
                    // also this start and end has been added 
                    start++;end--;
                }
                else if(sum>0)end--;
                else start++;
            }
        }
        return ans;
    }
};