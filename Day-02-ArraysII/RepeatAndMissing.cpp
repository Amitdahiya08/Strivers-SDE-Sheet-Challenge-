#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    long long sum1= (n * (n+1))/2;
	long long sum2= accumulate(arr.begin(),arr.end(),0);
    // using long long while calculating the sumOfSquares 
    long long sum3= (n * 1LL * (n + 1) * (2 * n + 1)) / 6;
    long long sum4=0;
    for(int i=0;i<n;i++)sum4+=(long long) arr[i] * (long long) arr[i];
    // x-y
    long long diffOfBoth= (sum2-sum1);
    // x+y
    long long sumofboth =  (sum4-sum3)/diffOfBoth;
    // x
    long long missing= (diffOfBoth + sumofboth)/2;
    // y
    long long duplicate  =  abs((diffOfBoth-sumofboth)/2);
    return {(int)duplicate,(int)missing};
	
}
