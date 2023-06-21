#include <bits/stdc++.h> 
 void helper(vector<int>& arr, int n, vector<int>& ans, int i,int sum){
        if(i>=n){
            ans.push_back(sum);
            return;
        }
        // not select current
        int curr=sum;
        helper(arr,n,ans,i+1,curr);
        // select current 
        sum+=arr[i];
        helper(arr,n,ans,i+1,sum);
        return ;
        
    }
    vector<int> subsetSums(vector<int>& arr, int N)
    {
         vector<int>ans;
         helper(arr,N,ans,0,0);
         sort(ans.begin(),ans.end());
         return ans;
    }
vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    return subsetSums(num,num.size());
}