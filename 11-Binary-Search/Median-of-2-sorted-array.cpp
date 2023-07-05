 double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // so task is to only find median not to merge .
        // we have to know the first half elements only which is before median 
        // we want that nums1 stay smaller
        if(nums2.size() < nums1.size()) return findMedianSortedArrays(nums2,nums1);
        int n1=nums1.size();
        int n2=nums2.size();
        int low=0 , high=n1;
        while(low<=high){
            // half elements from nums1
            int cut1 = (low+high)/2;
            // remaining element from nums2
            int cut2 = ((n1+n2+1)/2) - cut1;
            // if we havent taken any elements form nums1 (left part)
            int left1= (cut1==0)? INT_MIN : nums1[cut1-1];
            // if we havent taken any elemenet from nums2-(left part)
            int left2= (cut2==0)? INT_MIN : nums2[cut2-1];
            // if we havent taken any element from nums1 - (right part)
            int right1= (cut1==n1)? INT_MAX : nums1[cut1];
            // if we havent taken any element from nums2 -(right part)
            int right2= (cut2==n2)? INT_MAX : nums2[cut2];
            // if the sequence is valid 
            if(left1<=right2 && left2<=right1){
                // let check if size is even(two median exist)
                if( (n1+n2)%2==0){
                    return (max(left1,left2) + min(right1,right2))/2.0;
                }
                // if odd
               else return max(left1,left2);
            }
            // if left1 > right2 (not valid sequence) 
            else if(left1 > right2){
                high = cut1-1;
            }
            // if left2 > right1
            else low= cut1 + 1;
        }
        return 0.0;
    }
double median(vector<int>& a, vector<int>& b) {
	// Write your code here.
	return findMedianSortedArrays(a, b);
}