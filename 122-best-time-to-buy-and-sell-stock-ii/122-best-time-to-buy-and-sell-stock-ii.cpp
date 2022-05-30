class Solution {
public:
    
    
    int solve(int index, int buy, vector<int>& prices, vector< vector<int> > &dp){
        
        if(index >= prices.size()){
            return 0;
        }
        
        if(dp[index][buy] != -1) return dp[index][buy];
        
        int take = 0;
        if(buy){
            take = prices[index] + solve(index + 1, 0, prices, dp);
        }else{
             take = -prices[index] + solve(index + 1, 1, prices, dp);
        }
        int notTake = solve(index + 1, buy, prices, dp);
        
        return dp[index][buy] = max(take, notTake);
    }
    
    int recursicveDp(vector<int>& prices){
         vector< vector<int> > dp(prices.size(), vector<int> (2, -1));
         return solve(0, 0, prices, dp);
    }
    
    int maxProfit(vector<int>& prices) {
       return recursicveDp(prices);
    }
};