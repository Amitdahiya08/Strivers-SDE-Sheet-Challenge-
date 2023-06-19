class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        // so we know that at most there can be 2 elements which can appear more than n/3 times
        int x=INT_MIN ,y=INT_MIN,countX=0,countY=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=y && countX==0){
                x=nums[i];
                countX++;
            }
            else if(nums[i]!=x && countY==0){
                y=nums[i];
                countY++;
            }
            else if(nums[i]==x)countX++;
            else if(nums[i]==y)countY++;
            else {
                countX--;
                countY--;
            }
        }
        // now we have two most occuring elements check if their count is greater than n/3 or not
        // resetting thier count
        countX=0;
        countY=0;
        for(int i=0;i<n;i++){
            if(nums[i]==x)countX++;
            if(nums[i]==y)countY++;
        }
        if(countX>n/3)ans.push_back(x);
        if(countY>n/3)ans.push_back(y);
        return ans;
    }
};