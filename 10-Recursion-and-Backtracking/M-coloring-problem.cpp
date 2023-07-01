bool check(bool graph [101][101],vector<int>& color, int m, int n,int node,int CurrColor){
        
        for(int i=0;i<n;i++){
            if(graph[node][i]==1){
                // it means the i is sibling of node check color of i
                // check its color if it has same color than we cant color node now 
                if(color[i]==CurrColor)return false;
            }
        }
        return true;
        
    }
    bool solve(bool graph[101][101],vector<int>& color, int m, int n,int curr){
        
        if(curr>=n)return true;
            for(int j=1;j<=m;j++){
                // now lets check if we can color the curr node with jth color or not
                // check if siblings of current node is colored with same color
                if(check(graph,color,m,n,curr,j)){
                    color[curr]=j;
                    if(solve(graph,color,m,n,curr+1)) return true;
                }
            }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // color vector to store corresponding color of node
        vector<int>color(n,-1);
        return solve(graph,color,m,n,0);
    }