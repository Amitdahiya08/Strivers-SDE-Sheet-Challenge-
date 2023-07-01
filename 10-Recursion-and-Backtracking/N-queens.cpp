class Solution {
public:
    // the idea his simple we need to palce a queen and check all the upper sides 
     // 2d vector to store all possibilites
        vector<vector<string>>ans;
        bool isvalid(vector<string>& temp, int row, int col){
            // check  the upper colm
            for(int i=0;i<row;i++){
                if(temp[i][col]=='Q')return false;
            }
            // check the left diagnoal 
              for(int i=row,j=col;i>=0 && j>=0;--i,--j)
                {
                     if(temp[i][j] == 'Q') return false;
                }
            //check right diagonal
           for(int i=row,j=col;i>=0 && j<temp.size();--i,++j)
              {
                  if(temp[i][j] == 'Q') return false;
              }
           return true;
        }
    void helper(vector<string>& temp, int n, int row){
        if(row==n){
            ans.push_back(temp);
            return;
        }
        // now check all the colm of current row and place the queen
        for(int j=0;j<n;j++){
            if(isvalid(temp,row,j)){
                // if it is valid than put Queen and now check next row
                temp[row][j]='Q';
                helper(temp,n,row+1);
                temp[row][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        // to store the current solution
        vector<string>board(n,string(n,'.'));
        helper(board,n,0);
        return ans;
    }
};