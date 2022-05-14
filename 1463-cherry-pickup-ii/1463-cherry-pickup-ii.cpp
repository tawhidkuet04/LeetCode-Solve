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
        
        vector< vector<vector<int>>  > dp(rowSize, vector<vector<int> >(colSize,  vector<int>(colSize, -1e8)));
        
        dp[0][0][colSize - 1] = ( 0 == colSize - 1) ? grid[0][0] : grid[0][0] + grid[0][colSize - 1];
        
        
        for(int row = 1; row < rowSize; row ++ ){
            for(int j1 = 0; j1 < colSize; j1 ++ ){
                for(int j2 = 0; j2 < colSize; j2 ++ ){
                    
                    int maxi = -1e8;
                    
                    for(int i = -1; i <= 1 ; i ++ ){
                        for(int j = -1 ; j <= 1; j ++ ){
                            
                            int val = grid[row][j1];
                            
                            if( j1 != j2){
                                val += grid[row][j2];
                            }
                            
                            if( (j1 + i ) < 0 || (j1 + i) >= colSize || (j2 + j) >= colSize || (j2 + j) < 0) {
                                val = -1e8;
                                continue;
                            }
                            maxi = max(maxi, val + dp[row - 1][j1 + i][j2 + j]);
                            
                        }
                    }
                    
                    dp[row][j1][j2] = maxi ;
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < colSize; i ++ ){
            for(int j = 0; j < colSize; j ++ ){
                ans = max(ans, dp[rowSize - 1][i][j]);
            }
        }
        return ans;
        
        // return solve(0, 0 , 0, grid[0].size() - 1, grid, dp);
    }
};