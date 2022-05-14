class Solution {
public:
    
    int solve(int i, int j, vector<vector<int>>& matrix, vector< vector<int> > &dp){
        
        if(i >= matrix.size() || j >= matrix[0].size() || j < 0)  return 10000000;
        
        if( i == matrix.size() - 1) return matrix[i][j];
        
        if(dp[i][j] != - 1) return dp[i][j];
        
        int left = matrix[i][j] +  solve(i + 1, j - 1, matrix, dp);
        int right = matrix[i][j] + solve( i + 1, j + 1, matrix, dp);
        int below = matrix[i][j] + solve( i + 1, j , matrix, dp);
        
        return dp[i][j] = min( left, min(right, below));
        
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        
        vector< vector<int> > dp(rowSize, vector<int> (colSize, - 1));
        
        int ans = INT_MAX;
        
        for(int i = 0 ; i < colSize; i ++ ){
            ans = min(ans, solve(0, i, matrix, dp));
        }
        
        return ans;
        
    }
};