class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            int temp=1; 
            unordered_map<char,int>hashmap;
            for(int j=i+1;j<s.size();j++){
                if(s[j]!=s[i] && hashmap[s[j]]<1){
                    temp++;
                    hashmap[s[j]]++;
                }
                else break;
            }
            if(temp>ans) ans=temp;
        }
        return ans;
    }
};