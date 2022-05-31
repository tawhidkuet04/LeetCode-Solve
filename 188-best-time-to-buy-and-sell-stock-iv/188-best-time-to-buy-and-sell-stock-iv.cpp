class Solution {
public:
    
    int solve(int index, int buy, int didTransaction, int limit,
             vector<int>& prices,   vector< vector<vector<int> > > &dp){
        
        if(didTransaction >= limit){
            return 0;
        }
        
        if(index >= prices.size()){
             if(didTransaction >= limit){
                return 0;
             }else{
                 return -1e8;
             }
        }
        
        if(dp[index][buy][didTransaction] != -1) return dp[index][buy][didTransaction];
        
        int take = 0;
        
        if(buy){
            take = prices[index] + solve(index + 1, 0, didTransaction + 1, limit, prices, dp);
        }else{
             take = -1 * prices[index] + solve(index + 1, 1 , didTransaction, limit, prices, dp);
        }
        
        int notTake = solve(index + 1, buy, didTransaction, limit, prices, dp);
        
        return dp[index][buy][didTransaction] = max(take, notTake);
            
        
    }
    
    
    int maxProfit(int k, vector<int>& prices) {
        vector< vector<vector<int> > > dp(prices.size(), vector< vector<int> > (2, vector<int>(k + 1,-1)));
        
        int ans = 0;
        
        for(int index = 1; index <= k; index ++){
            for(int dpIndex = 0; dpIndex < prices.size(); dpIndex ++ ){
                for(int buy = 0; buy < 2; buy ++){
                    for(int count = 0; count <= k ; count ++ ){
                        dp[dpIndex][buy][count] = -1;
                    }
                }
            }
           
            ans = max(ans, solve(0, 0, 0, index, prices, dp));
        }
        
        return ans;
    }
};