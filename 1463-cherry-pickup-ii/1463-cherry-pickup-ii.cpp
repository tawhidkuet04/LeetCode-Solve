class Solution {
public:
    
    int solve(int fi, int fj, int si, int sj,
             vector<vector<int>>& grid,
             vector< vector<vector<int>>  > & dp
             ){
        if( fi >= grid.size() || fj >= grid[0].size() || fj < 0) return -1e8;
        if( si >= grid.size() || sj >= grid[0].size() || sj < 0) return -1e8;
        
        if( fi == grid.size() - 1) {
            if( fi == si && fj == sj) return grid[fi][fj];
            else {
                return  grid[fi][fj] + grid[si][sj];
            }
        }
        
        
        if(dp[si][fj][sj] != - 1) return dp[si][fj][sj];
        
        int maxi = 0 ;
        
        for(int i = -1; i < 2; i ++ ){
            for(int j = - 1; j < 2; j ++ ){
                int val = 0;
                if( fi == si && fj == sj){
                    val = grid[fi][fj];
                }else{
                    val = grid[fi][fj] + grid[si][sj];
                }
                maxi = max(maxi, val + solve(fi + 1, fj + i, si + 1, sj + j, grid, dp ));
            }
        }
        
        
        return  dp[si][fj][sj] =  maxi;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int rowSize = grid.size();
        int colSize = grid[0].size();
        
        vector< vector<vector<int>>  > dp(rowSize, vector<vector<int> >(colSize,  vector<int>(colSize, - 1)));
        

        return solve(0, 0 , 0, grid[0].size() - 1, grid, dp);
    }
};