#include <bits/stdc++.h> 
bool comp(pair<int,int>a,pair<int,int>b)
{
    double r1=(double)a.second/a.first;
    double r2=(double)b.second/b.first;
    return r1>r2;
}
double maximumValue (vector<pair<int, int>>& arr, int n, int W)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(arr.begin(),arr.end(),comp);
    double ans=0;
    int i=0;
     while(W>0 && i<n){
            // if W is mroe than curr item weight so we can take its full value
            if(W > arr[i].first){
                ans+= arr[i].second;
                W -=arr[i].first;
                i++;
            }
            else{
                //  else take it in fraction
                ans+= ((double) arr[i].second / (double) arr[i].first)* (double) W;
                i++;
                // in other words W will become zero only
                break;
            }
        }
        return ans;

}