class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0;
        int r=0;
        int maxi=0,cur=0;
        while(r<prices.size()){
            if(prices[l]<prices[r]){
                cur=prices[r]-prices[l];
                maxi=max(cur,maxi);
            }
            else{
                l=r;
            }
            r++;
        }
        return maxi;
    }
};