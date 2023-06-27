class Solution {
public:
    // so the idea to find the permutaion using math approach
    // for more  explaination look at the solution with title explained like I am 5 
    // the apporach is similar to that
    string getPermutation(int n, int k) {
        vector<int>nums;
        int fact=1;
        // storing 1 to n set into vector and side by side calculating factorial 
        for(int i=1;i<=n;i++){
            fact *=i;
            nums.push_back(i);
        }
        // now we have our numbers and the fact contains total permuations count
        // reduce k by 1 as 0 based indexing 
        k--;
        // now we will pick all the numbers one by one and till all the elements are taken 
        // or you can say till the vector is not empty
        string ans=""; 
        while(!nums.empty()){
            int n=nums.size();
            // we will pick the k/(n-1)! index element
            // (n-1)! can be written as n!/n or fact/n
            int index= k/(fact/n);
            ans += to_string(nums[index]);
            // erase the number from vector
            nums.erase(nums.begin() + index);
            // now update the k 
            k %=(fact/n);
            // now permuation left are n-1! so reduece the fact too
            fact/=n;
        }
        return ans;

    }
};