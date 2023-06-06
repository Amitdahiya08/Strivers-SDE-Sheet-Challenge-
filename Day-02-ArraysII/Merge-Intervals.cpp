class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<intervals.size();i++){
            int start=intervals[i][0];
            int end=intervals[i][1];
            bool merge=0;
            while( i<intervals.size() && end>=intervals[i][0]){
                start=min(start,intervals[i][0]);
                end=max(end,intervals[i][1]);
                i++;
                merge=1;
            }
            if(merge==1)i--;
            ans.push_back({start,end});
        }
        return ans;
    }
};