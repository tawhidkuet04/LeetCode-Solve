class Solution {
public:
    
    bool isPerfectSquare(int n){
        int square = sqrt(n);
        if((square * square) == n){
            return true;
        }
        return false;
    }

    
    int solve(int index, int sum, vector<int> &squares,   vector< vector<int> > &dp){
        
        if(index >= squares.size() - 1) {
            if( (sum % squares[index]) == 0){
                cout << sum / squares[index] << endl;
                return sum / squares[index];
            }else return 1e8;
        }
        
        
        if(dp[index][sum] != -1) return dp[index][sum] ;
        
        int take = 1e8;
        
        if( (sum - squares[index]) >= 0){
            take = 1 + solve(index, sum - squares[index], squares, dp);
        }
        int notTake = solve(index + 1, sum, squares, dp);
        // cout << take << " " << notTake << endl;
        return dp[index][sum] = min(take, notTake);
    }
    
    
    int numSquares(int n) {
        vector<int> squares;
       
        for(int index = 1; index <= n; index ++ ){
            if(isPerfectSquare(index)){
                squares.push_back(index);
            }
        }
        
        // cout << squares.size() << endl;
        
        // for(int index = 0; index < squares.size(); index ++ ){
        //     cout << squares[index] << endl;
        // }
         vector< vector<int> > dp(squares.size(), vector<int>(n + 1, -1));
        
        return solve(0, n, squares, dp);
    }
};