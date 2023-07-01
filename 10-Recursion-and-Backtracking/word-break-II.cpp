#include <bits/stdc++.h> 
void solve(int idx,string& s, map<string,bool>& mp,string cur, vector<string>& res){
    if(idx==s.size()){
        res.push_back(cur);
        return;
    }
    for(int i=idx;i<s.size();i++){
        string tmp=s.substr(idx,i-idx+1);
        if(mp[tmp]){
            solve(i+1,s,mp,cur+tmp+" ",res);
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary){
    map<string,bool> mp;
    for(auto& x:dictionary) mp[x]=true;
    vector<string> res;
    solve(0,s,mp,"",res);
    return res;
}