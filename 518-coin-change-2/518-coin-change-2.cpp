class Solution {
public:
    int solve(int index, int amount, vector<int> &coins,  vector< vector<int> > &dp){
        
       
        if(amount < 0 ) return 0;
        if(amount == 0 ) return 1;
        if(index == coins.size() - 1){
            if(amount  % coins[index] == 0 ) return 1;
            else return 0;
        }
         
        if(index >= coins.size()) return 0;
        
        if(dp[index][amount] != - 1) return dp[index][amount];
        
        int take =  solve(index, amount - coins[index], coins, dp);
 
        int notTake = solve(index + 1, amount, coins, dp);
        
        return dp[index][amount] = take + notTake;
        
    }
    int change(int amount, vector<int>& coins) {
        int sz = coins.size();
        vector< vector<int> > dp(sz, vector<int>(amount + 100, 0));
        
        for(int index = 0; index < sz; index ++ ){
            dp[index][0] = 1;
        }
        
        for(int target = 1; target <= amount; target ++ ){
            if( target % coins[0] == 0){
                 dp[0][target] = 1;
            }
           
        }
        
        
        for (int index = 1; index < sz; index ++ ){
            for(int target = 0; target <= amount ; target ++ ){
                int take = 0 ;
                if( (target - coins[index]) >= 0 ){
                    take = dp[index][target - coins[index]];
                }
                int notTake = dp[index - 1][target];
                dp[index][target] = take + notTake;
            }
        }
        
        
        
        return dp[sz - 1][amount];
        
        
        
    }
};