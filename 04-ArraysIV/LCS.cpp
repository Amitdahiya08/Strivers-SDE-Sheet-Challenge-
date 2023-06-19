class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        unordered_set<int>set;
        for(int i=0;i<nums.size();i++){
            set.insert(nums[i]);
        }
        int len=1;
        for(int i=0;i<nums.size();i++){
            if(set.find(nums[i]+1)!=set.end()){
                int num=nums[i]+1;
                int temp=1;
                while(set.find(num)!=set.end()){
                    temp++;
                    set.erase(num);
                    num++;
                }
                int back=nums[i]-1;
                while(set.find(back)!=set.end()){
                    temp++;
                    set.erase(back);
                    back--;
                }
                len=max(temp,len);
            }
        }
        return len;
        
    }
};