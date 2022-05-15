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
        vector< vector<int> > dp(sz, vector<int>(amount + 100, -1));
        
        return solve(0, amount, coins, dp);
        
        
        
    }
};