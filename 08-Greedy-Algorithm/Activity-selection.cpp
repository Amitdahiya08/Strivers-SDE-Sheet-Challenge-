#include<bits/stdc++.h>
// The question is same as N meetings
int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    int n=start.size();
    vector<pair<int,int>>activity;
    // storing both in pair so that we can sort them according to finish time 
    for(int i=0;i<n;i++){
        activity.push_back({finish[i],start[i]});
    }
    sort(activity.begin(),activity.end());
    // atleast first activity can be done so count min will be 1
    int count=1;
    // storing the first activity ending
    int end=activity[0].first;
    for(int i=1;i<n;i++){
        // curr activity starting time
        int s=activity[i].second;
        // if its starting time is after or equal to prev activity than do it
        if(s>=end){
            count++;
            // update end time 
          end=activity[i].first;
        }
    }
    return count;
}
