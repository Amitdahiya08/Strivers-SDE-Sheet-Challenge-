#include <bits/stdc++.h> 
bool isPossible(vector<int> time, int k, long long int limit) {
    long long int days = 1;
    long long int chapters = 0;
    for (int i = 0; i < time.size(); i++) {
        if (chapters + time[i] > limit) {
            days++;
            chapters = time[i];
            if (time[i] > limit) return false;
        } else {
            chapters += time[i];
        }
    }
    return days <= k; 
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.
	long long int sum=0;
	for(int i=0;i<time.size();i++){
		sum+=time[i];
	}
	long long int high=sum;
	long long int low=0;
	long long int res=-1;
	while(low<=high){
		long long int mid= low + (high-low)/2;
		if(isPossible(time,n,mid)){
			res=mid;
			high=mid-1;
		}
		else low=mid+1;
	}
	return res;
}