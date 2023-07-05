class Solution {
public:
   int search(vector<int>& arr, int k) {
    //    the idea is we know that we have 2 parts sorted 
    // and we need to apply binary search in that sorted part
    
       int n=arr.size();
       int low = 0, high = n - 1;
       while (low <= high) {
        int mid = (low + high) / 2;

        //if mid points the target
        if (arr[mid] == k) return mid;

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
                //if element exists:
            if (arr[low] <= k && k <= arr[mid]) {
                high = mid - 1;
            }
            else {
                // if element does not exist in this sorted part
                low = mid + 1;
            }
        }
        //if right part is sorted:
        else { 
                //element exists:
            if (arr[mid] <= k && k <= arr[high]) {
                low = mid + 1;
            }
            else {
                //element does not exist:
                high = mid - 1;
            }
        }
    }
    return -1;
}
};