class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            // we need to take unique pairs only 
            if(i>0 && nums[i]==nums[i-1]) continue;
            // fixing first element
            for(int j=i+1;j<n;j++){
                // again check if the last elem was same as curr
                if(j>i+1 && nums[j]==nums[j-1])continue;
                // fixing 2nd element 
                int left=j+1;
                int right=n-1;
                while(left<right){
                    // to avoid integer flow either add them one by one or long 
                    long long sum  = (long)nums[i] +(long) nums[j] + (long)nums[left] + (long)nums[right];
                    // if sum of all 4 the first 2 fixed element and element from left and right
                    if(sum==target){
                        // push them into 2d ans vector 
                        ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                        // move both by one place
                        left++; right--;
                    // check if the curr element of left or right is same as prev pair
                    while(left<right && nums[left]==nums[left-1])left++;
                    while(left<right && nums[right]==nums[right+1])right--;
                    }
                    else if(sum<target)left++;
                    else right--;
                }
            }
        }
        return ans;
    }
};