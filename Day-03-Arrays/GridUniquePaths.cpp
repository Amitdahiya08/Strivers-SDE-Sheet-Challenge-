class Solution {
public: 
    // the below are both codes memo code and loop method 
    int helper(int m, int n, vector<vector<int>>& dp){
    //when we reach to destination
    if(m==0 && n==0) return 1;
    // if we go beyond the box
    if(m<0 || n<0) return 0;
    if(dp[m][n]!=-1)return dp[m][n];
    int path1= helper(m-1,n,dp);
    int path2= helper(m,n-1,dp);
    return dp[m][n]=path1+path2;
    }
    int uniquePaths(int m, int n) {
        //vector<vector<int>>dp(m,vector<int>(n,-1));
        // passing m-1 and n-1 as the 2d array starts from 0
        // return helper(m-1,n-1,dp);
        // |||||| The above code is memo code |||||||| 
       vector<int>dp(n,0);
        for(int i=0;i<m;i++){
            vector<int>curr(n,0);
            for(int j=0;j<n;j++){
                // marking the starting postion
                if(i==0 && j==0) curr[j]=1;
                else {
                    int up = 0 , down =0;
                    if(j>0) down = curr[j-1];
                    if(i>0) up = dp[j];
                    curr[j]= (down + up) ;
                }
            }
            dp=curr;
        }
        return dp[n-1];
    }
};
