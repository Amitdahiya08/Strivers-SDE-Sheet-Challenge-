#include<bits/stdc++.h>
void helper(vector<int>& arr, int n, int k,int sum,int i, vector<int>& temp ,vector<vector<int>>& ans ){
    if(i>=n){
        if(sum==k){
            ans.push_back(temp);
        }
        return;
    }
    // not select current item 
    helper(arr,n,k,sum,i+1,temp,ans);
    // select curr item
    temp.push_back(arr[i]);
    helper(arr,n,k,sum+arr[i],i+1,temp,ans);
    temp.pop_back();
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<int>temp;
    vector<vector<int>>ans;
     helper(arr,n,k,0,0,temp,ans);
     return ans;
}