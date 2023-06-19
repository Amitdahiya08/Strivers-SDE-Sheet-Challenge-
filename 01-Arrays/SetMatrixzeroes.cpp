// question Link -> https://leetcode.com/problems/set-matrix-zeroes/
// 73- Leetcode
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
    // creating two set to store row and col
        set<int>row,col;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // storing the postion of zero 
                if(matrix[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(int i:row){
            for(int j=0;j<n;j++){
                matrix[i][j]=0;
            }
        }
         for(int j:col){
            for(int i=0;i<m;i++){
                matrix[i][j]=0;
            }
        }
    }
};
