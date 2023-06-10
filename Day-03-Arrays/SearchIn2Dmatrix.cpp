class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // using binary search method as matrix is sorted 
       int low=0;
    //    if it is empty
       if(!matrix.size()) return false;
       int m=matrix[0].size();
       int high= (matrix.size() * matrix[0].size()) -1;
       while(low<=high){
           int mid= low + (high -low)/2;
        //    row = mid / m  & colm = mid%m
        //  now you wonder why we only divide it with col size bt not with row size to find row and colm
        //  so let take e.g :- mid=17 and rowsize=5 colm size=4 so in this case 
        //  dividing the with row with row size and colm with colm size 
        //  17/5=3; 17/4=4; now it means arr[3][4]=mid but colm are only {0,1,2,3}
        //  check for reminders 17%5=2 , 17%4=1 now it means= arr[2][1]=mid but it is 10th element
        // check for dividng it by colm 17/4=4 , 17%4=1 it means arr[4][1] it means last row 2nd elem
        //  which is 17th
        //    checking at mid if it is equal to target or not
           if(matrix[mid/m][mid % m]==target){
               return true;
           }
           else if(matrix[mid/m][mid %m]<target){
               low= mid+1;
           }
           else{
               high=mid-1;
           }
       }
       return false;
    }
};