class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=0;
        int sell=1;
        int maxP=0;
        while(sell<prices.size()){
            if(prices[sell]>prices[buy]){
                int profit=prices[sell]-prices[buy];
                if(profit>maxP) maxP=profit;
            }
            else buy=sell;
            sell+=1;
        }
        
        return maxP;
    }
};