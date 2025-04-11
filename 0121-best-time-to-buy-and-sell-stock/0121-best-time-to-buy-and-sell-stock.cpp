class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyp = prices[0];
        int profit = 0;
        for(int i=1;i<prices.size();i++){
            int sp = prices[i];
            if(sp>buyp){
                profit = max(profit,sp-buyp);
            }
            buyp = min(buyp,prices[i]);

        }
        return profit;
    }
};