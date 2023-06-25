#include <bits/stdc++.h> 
  bool isPalindrome(string s, int start, int end) {
    while (start <= end) {
      if (s[start++] != s[end--])
        return false;
    }
    return true;
  }
   void helper(string s, int ind, int n, vector<string>& temp, vector<vector<string>>& ans){
       if(ind==n){
           ans.push_back(temp);
           return;
       }
       for(int i=ind;i<n;i++){
        //   check if the partition we are making at is palindrome or not 
           if( isPalindrome(s,ind,i)){
            //    if yes than store the substring in temp vector of partition of string
            temp.push_back(s.substr(ind,i-ind+1));
            // now check if the selected string's substring is a palindrome(given condition)
            helper(s,i+1,n,temp,ans);
            // remove it from temp so that duplicate dont occur
            temp.pop_back();
           }
       }
   }
    vector<vector<string>> partition(string s) {

        vector<vector<string>>ans;
        vector<string>temp;
        int n=s.size();
        helper(s,0,n,temp,ans);
        return ans;
    }