int calculateMinPatforms(int arr[], int dep[], int n) {
    // Write your code here.
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int platform=1;
    	int i=1;
    	int j=0;
    	int count=1;
    	while(i<n && j<n){
    	    if(arr[i]<=dep[j]){
    	       // it means the prev train has not left yet we need another platform
    	       count++;
    	       i++;
    	    }
    	    else{
    	       // it means the prev train has left lets check if some more train has left or not 
    	       //one platform got empty
    	       count--;
    	       j++;
    	    }
    	    platform=max(count,platform);
    	}
    	return platform;
}