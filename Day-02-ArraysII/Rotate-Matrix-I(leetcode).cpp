class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    // first transpose the matrix 
        for (int i = 0; i < matrix.size(); ++i){
            for (int j = i + 1; j < matrix[i].size(); ++j){
                 swap(matrix[i][j], matrix[j][i]);
            }
        }
        // than reverse the each row
        for(int i=0;i<matrix.size(); i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};