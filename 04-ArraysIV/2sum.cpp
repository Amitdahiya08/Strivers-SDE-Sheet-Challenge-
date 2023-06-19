class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>set;
        vector<int>temp;
        // here we are not pushing all element at once
        // checking for the complement if it exist in set return both pair indexes
        // else we are pushing it into the set with its index
        // this way we are using less space and less time too 
         for(int i=0;i<nums.size();i++){
             if(set.find(target-nums[i])!=set.end() ){
                temp.push_back(set[target-nums[i]]);
                temp.push_back(i);
                return temp;
             }
             set[nums[i]]=i;
         }
         return temp;
    }
};