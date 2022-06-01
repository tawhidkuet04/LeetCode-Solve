class Solution {
public:
    
    int solve(int index, int buy, int count,
             vector<int>& prices, vector< vector< vector<int> > > & dp, int limit){
        
        if(count == limit){
            return 0;
        }
        
        if(index >= prices.size()){
              if(count <= limit) return 0;
              else return -1e8;
        }
        
        if(dp[index][buy][count]  != -1) return dp[index][buy][count] ;
        
        int take = 0;
        
        if(buy){
            take = prices[index] + solve(index + 1, 0, count + 1, prices, dp, limit);
        }else{
            take = -prices[index] + solve(index + 1, 1, count, prices, dp, limit);
        }
        
        int notTake = solve(index + 1, buy, count, prices, dp, limit);
        
        return dp[index][buy][count] = max(take, notTake);
        
        
    }
    
    int dpIterative(vector<int>& prices){
         vector< vector< vector<int> > > dp(prices.size() + 2, vector<vector<int> > (2, vector<int>(4,0)));
        


        for(int index = prices.size() - 1 ; index >= 0 ; index -- ){
            for(int buy = 0; buy < 2; buy ++ ){
                for(int count = 1; count <= 2; count ++ ){
                    int take = 0;
                    if(buy){
                        take = prices[index] + dp[index + 1][0][count - 1];
                    }else{
                        take = -prices[index] + dp[index + 1][1][count];
                    }
                    
                    int notTake = dp[index + 1][buy][count];
                    dp[index][buy][count] = max(take, notTake);
                }
            }
        }
        
        return dp[0][1][2];
        
        
        
    }
    
    int maxProfit(vector<int>& prices) {
        
        
         vector< vector< vector<int> > > dp(prices.size() + 1, vector<vector<int> > (2, vector<int>(3,-1)));
        
        
        
        return solve(0, 0, 0, prices, dp, 2);
        
        return dpIterative(prices);
    }
};