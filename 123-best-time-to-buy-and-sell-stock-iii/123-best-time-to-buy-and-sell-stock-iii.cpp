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
    
    int maxProfit(vector<int>& prices) {
        
        vector< vector< vector<int> > > dp(prices.size(), vector<vector<int> > (2, vector<int>(2,-1)));
        
        // int one = solve(0, 0, 0, prices, dp, 1);
        // for(int index = 0; index < prices.size(); index ++){
        //     for(int buy = 0; buy < 2; buy ++ ){
        //         for(int count = 0; count < 2; count ++){
        //             dp[index][buy][count] = -1;
        //         }
        //     }
        // }
        // int two = solve(0, 0, 0, prices, dp, 2);
//         int ans = solve(0, 0, 0, prices, dp, 2);
        
//         if( ans < 0){return 0;}
        return solve(0, 0, 0, prices, dp, 2);
    }
};