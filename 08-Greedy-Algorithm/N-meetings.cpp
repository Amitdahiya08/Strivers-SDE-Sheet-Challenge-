#include <bits/stdc++.h> 
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    int n=start.size();
     vector<pair<int , pair<int,int> >>set;
        for(int i=0;i<n;i++){
            // push both start and end inside it 
            // as of now we want to sort in on the basis of end-index-start so store it in that order
            set.push_back({end[i], {i+1,start[i]}});
        }
        sort(set.begin(),set.end());
        int ends= set[0].first;
        vector<int>meetings;
        meetings.push_back(set[0].second.first);
        for(int i=1;i<n;i++){
            int start=set[i].second.second;
            if(start > ends){
                // update the ends
                ends=set[i].first;
                meetings.push_back(set[i].second.first);
            }
        }
        return meetings;
}