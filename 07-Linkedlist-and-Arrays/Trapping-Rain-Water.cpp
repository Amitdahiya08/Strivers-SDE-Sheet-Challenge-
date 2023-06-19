class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        long long ans=0;
        int maxleft=0,maxright=0;
        int left=0,right=n-1;
        while(left<=right){
            // we will store water in left if we are sure that right side is bigger or equal to left
            // means we have a support from right
            if(height[left]<=height[right]){
                // it means we are sure from right side that water can be stored 
                // now check left side
                if(maxleft<=height[left]){
                    // we cant store water as there is no support from left 
                    maxleft=height[left];
                    left++;
                }
                else{
                    // maxleft is bigger , it means we can store water
                    ans+= maxleft - height[left];
                    left++;
                }

            }
            else{
                // now if right side is small , so we know that left(bigger side) side will support us 
                // lets check support from right side
                if(maxright<=height[right]){
                    // maxright is  not able to support us so change maxright
                    maxright=height[right];
                    right--;
                }
                else{
                    // if maxright is able to support us lets trap the water 
                    ans += maxright - height[right];
                    right--;
                }
            }
        }
        return ans;
    }
};