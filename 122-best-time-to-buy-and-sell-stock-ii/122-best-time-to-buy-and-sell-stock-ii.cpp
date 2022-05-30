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
    
    int iterativeDp(vector<int> &prices){
         vector< int> dp(2, 0), cur(2, 0);
         dp[1] = - prices[0];
        
        int sz = prices.size();
        
        for(int index = 1; index < sz; index ++ ){
            for(int buy = 0; buy < 2; buy ++ ){
                int take = 0 ;
                if(buy){
                    take = - prices[index] + dp[0]; 
                }else{
                    take =  prices[index] + dp[1];
                }
                int notTake = dp[buy];
                cur[buy] = max(take, notTake);
            }
            dp = cur;
            
        }
        
        return dp[0];
    }
    
    int maxProfit(vector<int>& prices) {
       // return recursicveDp(prices);
       return iterativeDp(prices);
    }
};