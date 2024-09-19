class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int min = INT_MAX;
        for(int i=0;i<prices.size();i++){
            for(int j=i+1;j<prices.size();j++){
                int cost = prices[i]+prices[j];
                if(cost < min){
                    min = cost;
                }
            }
        }
        if(min<=money){
            return money-min;
        }
        return money;
    }
};