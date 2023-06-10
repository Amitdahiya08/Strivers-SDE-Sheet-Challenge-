class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
            int start=intervals[0][0];
            int end=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if( end < intervals[i][0])
             {  
                //  if we cant merge then
                //  add previous {start,end} to ans and update start,end
                 ans.push_back({start,end});
                 start=intervals[i][0];
                 end=intervals[i][1];
             }
            else{
                // if we can merge them just update start , end
                start=min(start,intervals[i][0]);
                end=max(end,intervals[i][1]);
            }
        }
        // push the last pair of start,end to ans as it was not added 
        ans.push_back({start,end});
        return ans;
    }
};