void helper(vector<vector<int>>& board, vector<string>& ans, string temp, int n, int i, int j){
        // check if it is out of bound or not ,also
        // check if current cell is blocked for moving init
        if(i>=n || j>=n || i<0 || j<0 || board[i][j]!=1)return;
        // check if we have reached at the end 
        if(i==n-1 && j==n-1){
            ans.push_back(temp);
            return;
        }
        // mark the current cell as visited so that we dont find duplicate path
        board[i][j]=2;
        // now lets move in all 4 direction and find the solution
        helper(board,ans,temp + "U",n,i-1,j);
        helper(board,ans,temp + "D",n,i+1,j);
        helper(board,ans,temp + "L",n,i,j-1);
        helper(board,ans,temp + "R",n,i,j+1);
        // remove the visited mark so that we can reach on it via other path 
        board[i][j]=1;
        return;
    }
    vector<string> findPath(vector<vector<int>> &board, int n) {
        // Your code goes here
        vector<string>ans;
        string temp="";
         helper(board,ans,temp,n,0,0);
         return ans;
    }