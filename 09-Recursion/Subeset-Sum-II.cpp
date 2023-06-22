class Solution {
public:
    void helper(vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans, int ind){
        // push the curr subset store in temp to ans
        ans.push_back(temp);
        for(int i=ind;i<nums.size();i++){
            // check if the no. has alredy appeared in the loop before 
            // if yes than it will create duplicate to so skip it 
            if(i!=ind && nums[i]==nums[i-1])continue;
            // making subset including curr element
            temp.push_back(nums[i]);
            helper(nums,temp,ans,i+1);
            // making subset without it 
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
         helper(nums,temp,ans,0);
         return ans;
    }
};