class Solution {
public:
    int solve(int index, vector<int>& coins, int amount, int sum,    vector< vector<int> > &dp){
        if(index >= coins.size()){
            return 1e7;
        }
        
        if(sum > amount){
            return 1e7;
        }
        
        if(sum == amount){
            return 0;
        }
        

        
        if(dp[index][sum] != -1) return dp[index][sum];
        
        int take = 1e7;
        if( sum < INT_MAX - coins[index]){

            take = 1 + solve(index, coins, amount, sum + coins[index], dp);
        }
        int notTake = solve(index + 1,  coins, amount, sum, dp);
        
        return dp[index][sum] = min(take, notTake);
        
    }
    
    int solve2(vector<int>& coins, int amount){
         vector< int> prev(amount + 10, 1e8);
        
         int sz = coins.size();
        
         for(int limit = 0; limit <= amount ; limit ++){
             if( limit % coins[0] == 0){
                 prev[limit] = limit / coins[0];
             }else{
                 prev[limit] = 1e8;
             }
         }
        
        for(int index = 1; index < sz; index ++ ){
              vector< int> cur(amount + 10, 1e8);
            for(int limit = 0; limit <= amount; limit ++){
                 int take = 1e8;
                 if(limit - coins[index] >= 0){
                      take = 1 + cur[limit - coins[index]];
                 }
                 int notTake = prev[limit];
                 cur[limit] = min(take, notTake);
            }
            prev = cur;
        }
        
        if(prev[amount] == 1e8) return -1;
        else return prev[amount]; 
        
    }
    
    int solve3(vector<int>& coins, int amount){
        int sz = coins.size();
        vector< vector<int> > dp(sz, vector<int>(amount + 10, -1));
        
        for(int limit = 0; limit <= amount ; limit ++ ){
            if(limit % coins[0] == 0){
                 dp[0][limit] = limit / coins[0];
            }else{
                 dp[0][limit] = 1e8;
            }
           
        }
        
        for(int index = 1; index < sz; index ++ ){
            for(int limit = 0; limit <= amount ; limit ++ ){
                int take = 1e8, notTake = 1e8;
                
                if( (limit - coins[index]) >= 0){
                    take = 1 + dp[index][limit - coins[index]];
                }
                notTake = dp[index - 1][limit];
                dp[index][limit] = min(take, notTake);
            }
        }
        
        if(dp[sz - 1][amount] == 1e8) return -1;
        return dp[sz - 1][amount];
        
        
    }
    
    int coinChange(vector<int>& coins, int amount) {
        vector< vector<int> > dp(coins.size(), vector<int> (amount + 1, -1));
        int ans =   solve(0, coins, amount, 0, dp);
        
        return solve3(coins, amount);
        
        
//         return solve2(coins, amount);

//         return (ans == 1e7) ? -1 : ans;
        
    }
};