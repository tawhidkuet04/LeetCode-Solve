class Solution {
public:
    
//     int solve(int i, int j, vector<vector<int>>& matrix, vector< vector<int> > &dp){
        
//         if(i >= matrix.size() || j >= matrix[0].size() || j < 0)  return 10000000;
        
//         if( i == matrix.size() - 1) return matrix[i][j];
        
//         if(dp[i][j] != - 1) return dp[i][j];
        
//         int left = matrix[i][j] +  solve(i + 1, j - 1, matrix, dp);
//         int right = matrix[i][j] + solve( i + 1, j + 1, matrix, dp);
//         int below = matrix[i][j] + solve( i + 1, j , matrix, dp);
        
//         return dp[i][j] = min( left, min(right, below));
        
//     }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        
        vector< int > dp(colSize, 0);
        
        int ans = INT_MAX;
        
//         for(int i = 0 ; i < colSize; i ++ ){
//             ans = min(ans, solve(0, i, matrix, dp));
//         }
        
        for(int index = 0; index < colSize; index ++ ){
            dp[index] = matrix[0][index];
        }
        
        for(int row = 1; row < rowSize; row ++){
            
             vector< int > tempDp(colSize, 0);
            
            for(int col = 0 ; col < colSize; col ++ ){
                int left = INT_MAX, right = INT_MAX, up = INT_MAX;
                
               if(col > 0 )left = matrix[row][col] + dp[col - 1];
               if( col < colSize - 1)right = matrix[row][col] + dp[col + 1];
                up = matrix[row][col] + dp[col];
                
                tempDp[col] = min(left, min(up, right));
            }
            dp = tempDp;
        }
        
        for(int index = 0; index< colSize; index ++ ){
            ans = min(ans, dp[index]);
        }
        
        
        return ans;
        
    }
};