#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    // Write your code here
    vector<int>arr ={1000,500,100,50,20,10,5,2,1};
    int i=0;
    int n=arr.size();
    int coins=0;
    while(i<n && amount >0){
        // if amount can be divided by current coin
        if(amount/arr[i] > 0){
            // how many coins did we used
            coins +=amount/arr[i];
            // the cash still left which is not converted to coins
            amount %=arr[i];
        }
        // else move to next coin and than check again
        i++;
    }
    return coins;
}
