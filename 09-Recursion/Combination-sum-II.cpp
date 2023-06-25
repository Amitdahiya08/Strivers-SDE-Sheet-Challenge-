  #include<bits/stdc++.h>
   void helper(vector<int>& nums, vector<int>& temp,int target, int sum, vector<vector<int>>& ans, int ind){
        // push the curr subset store in temp to ans
        if(sum==target){
			sort(temp.begin(),temp.end());
			ans.push_back(temp);
		}
        for(int i=ind;i<nums.size();i++){
            // check if the no. has alredy appeared in the loop before 
            // if yes than it will create duplicate to so skip it 
            if(i!=ind && nums[i]==nums[i-1])continue;
            // making subset including curr element
			sum+=nums[i];
            temp.push_back(nums[i]);
            helper(nums,temp,target,sum,ans,i+1);
            // making subset without it 
			sum-=nums[i];
            temp.pop_back();
        }
        return;
    }
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	// Write your code here.
	sort(arr.begin(),arr.end());
	vector<int>temp;
	vector<vector<int>>ans;
	helper(arr,temp,target,0,ans,0);
	return ans;
}
