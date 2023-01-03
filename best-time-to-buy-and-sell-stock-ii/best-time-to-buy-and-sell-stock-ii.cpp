class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0 ;
        int sz = prices.size();
        
        for(int index = 0; index < sz - 1; index ++ ){
            if(prices[index + 1] > prices[index]){
                profit += prices[index + 1] - prices[index];
            }
        }
        
        return profit;
    }
};