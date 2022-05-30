class Solution {
public:
    
    int solve(int index,  int prevBought, int canBuy,
              vector<int>& prices,    vector< vector<vector<int>> > &dp){
        
        if(index >= prices.size()){
            return 0;
        }        
        
        if(dp[index][prevBought][canBuy] != -1) return dp[index][prevBought][canBuy];
        
        int take = INT_MIN, notTake = INT_MIN;
        
        if(prevBought){
            take =  prices[index] + solve(index + 1, 0, 1, prices, dp);
          
        }else{
            if(!canBuy){
                take =  -1 * prices[index] + solve(index + 1, 1, 0, prices, dp);
            }else{
                if(index + 1 < prices.size()){
                     take =  -1 * prices[index + 1] + solve(index + 1, 1, 0, prices, dp);
                }
            }
            
        }
        notTake = solve(index + 1, prevBought,canBuy,  prices, dp);
        
        return dp[index][prevBought][canBuy] = max(take, notTake);
        
        
    }
    
    int maxProfit(vector<int>& prices) {
        vector< vector< vector<int> > > dp(prices.size(), vector<vector<int>> (3, vector<int>(3,-1)));
        
        return solve(0, 0, 0, prices, dp);
    }
};