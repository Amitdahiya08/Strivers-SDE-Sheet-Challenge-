#include <bits/stdc++.h> 
void helper(string &s, vector<string>& ans, int ind){
    if(ind==s.size()){
        ans.push_back(s);
        return;
    }
    for(int i=ind; i<s.size();i++){
        // swapping s[i] with s[ind]
        // if they are equal mean no swapping happened
        swap(s[i],s[ind]);
        helper(s,ans,ind+1);
        // now reset it
        swap(s[i],s[ind]);
    }
    return ;
}
vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string>ans;
    helper(s,ans,0);
    return ans;
}