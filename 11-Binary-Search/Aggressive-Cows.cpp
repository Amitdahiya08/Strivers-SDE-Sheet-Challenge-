#include<bits/stdc++.h>
bool possible(vector<int>& stalls, int n, int gap, int cows){
    // so we will place the first cow at stalls[0] and then check for others
    int lastCow=stalls[0];
    cows--;
    for(int i=1;i<n;i++){
        if(stalls[i] - lastCow >=gap){
            cows--;
            lastCow=stalls[i];
            if(cows<=0)return true;
        }
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    int n=stalls.size();
    sort(stalls.begin(),stalls.end());
    // maxgap we can have 
    int maxmgap=stalls[n-1] - stalls[0];
    // so we will try checking gap from 0 to maxmgap we can get
    int ans=0;
    int low=0;
    // using binary-search for getting ans
    while(low<=maxmgap){
        int mid= low + (maxmgap-low)/2;
        if(possible(stalls,n,mid,k)){
            low=mid+1;
            ans=max(mid,ans);
        }
        else maxmgap=mid-1;
    }
    return ans;
}