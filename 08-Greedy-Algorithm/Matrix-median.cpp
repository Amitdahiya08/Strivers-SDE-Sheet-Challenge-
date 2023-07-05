#include<bits/stdc++.h>
int helper(vector<vector<int>>& matrix, int k , int row){
    // now we know that each row is sorted 
    //  so we can again use binary search to know the value smaller than or equal to mid
    int low=0,high=matrix[row].size()-1;
    while(low<=high){
         int mid= low + (high-low)/2;
         if(matrix[row][mid]>k){
             high=mid-1;
         }
         else{
             low=mid+1;
         }
    }
    return low;
}
int getMedian(vector<vector<int>> &matrix)
{
    // we need median (a number which is greater than (n*m)/2 numbers )
    // so lets use binary search to get median as all the rows are sorted
    // elements can be from 1 to 1e9 
    int low=1;
    int high=1e9;
    int n=matrix.size();
    int m=matrix[0].size();
    int half = (n*m)/2;
    while(low<=high){
        int mid= low + (high-low)/2;
        // now lets count how many numbers are smaller and equal to numbers if they are equal to (n*m)/2
        // then mid might be the answer we are searching for
        int count=0;
        for(int i=0;i<matrix.size();i++){
            // counting numbers in each row one by one 
            count+= helper(matrix,mid,i);
        }
        if(count > half ) high=mid-1;
        else low=mid+1;
    }
    return low;
}