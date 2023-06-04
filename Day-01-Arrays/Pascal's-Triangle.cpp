

class Solution {
public:
    vector<vector<int>> generate(int n) {
        /*  //T.C-> O(n*n) space- O(n)
        vector<vector<int>>ans;
        vector<int>storage;
        for(int i=0;i<n;i++){
            vector<int>temp;
            for(int j=0;j<i+1;j++){
                int curr=1;
                if(storage.size()>j && j>0){
                    curr=storage[j] + storage[j-1];
                }
                temp.push_back(curr);
            }
            ans.push_back(temp);
            storage=temp;
        }
        return ans; */
    //    without using extra space
        vector<vector<int>> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[i].resize(i+1);
        //starts with 1  
        ans[i][0] = 1;
        //middle 
        for (int j = 1; j < i; j++) ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
        //ends with 1 
        ans[i][i] = 1;
    }
    return ans;
    }
};