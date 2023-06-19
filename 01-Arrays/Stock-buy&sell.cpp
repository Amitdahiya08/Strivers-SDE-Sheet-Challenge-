class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit1 =0; int buy=INT_MAX;
        for(int i=0;i<prices.size();i++){
            // buy will be min cost available till now 
             buy=min(prices[i],buy);
            // if we sell at this min price the max profit we can get is
             profit1=max(profit1,prices[i]-buy);
            }
         return profit1;
    }
};