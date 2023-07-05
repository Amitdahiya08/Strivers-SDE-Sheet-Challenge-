#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.
	priority_queue<int>res;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			// storing every combination
			res.push(a[i]+b[j]);
		}
	}
	vector<int>ans;
	while(k>0){
		ans.push_back(res.top());
		res.pop();
		k--;
	}
	return ans;
}