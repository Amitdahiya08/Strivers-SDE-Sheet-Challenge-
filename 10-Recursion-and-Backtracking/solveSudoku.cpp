class Solution {
public:
    int n=9;
    char arr[9]={'1','2','3','4','5','6','7','8','9'};
    bool pluscheck(vector<vector<char>>& board , int row , int col,char curr){
        // lets check in the row and colm
        for(int i=0;i<9;i++){
            // check current row
            if(board[i][col]==curr)return false;
            // current colm
            if(board[row][i]==curr)return false;
        }
        return true;
    }
    bool insideBox(vector<vector<char>>& board, int row , int col, char curr){
        // now we  need to find the box of current row and colm and then check init
        int boxRow= row/3;
        int boxCol= col/3;
        for(int i=boxRow*3;i<(boxRow+1)*3;i++){
            for(int j=boxCol*3;j<(boxCol+1)*3;j++){
                if(board[i][j]==curr)return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board, int row ,int col){
        // if we have filled all the rows
        if(row>=n)return true;
        // if we filled the current row 
        if(col>=n){
            return solve(board,row+1,0);
        }
        // check if the current cell is filled 
        if(board[row][col]!='.')return solve(board,row,col+1);

        // now we know the cell is in the range and empty lets try to fill it
        for(int i=0;i<9;i++){
            // before filling check if the number alredy exist or not 
            if( pluscheck(board,row,col,arr[i]) && insideBox(board,row,col,arr[i])){
                //  if we can use the number to fill lets fill and then try to solve further
                board[row][col]=arr[i];
                // if we are able to solve it then reaturn true else try with another number
                if(solve(board,row,col+1))return true;
                else board[row][col]='.';
             }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        // so the idea is to fill the empty cell with a number 
        // which is not present in the row colm and box
        // and then solve the sudoku further if we will not able to fill a cell 
        // we will backtrack and check the next number 
        bool a = solve(board,0,0);
        return;
    }
};