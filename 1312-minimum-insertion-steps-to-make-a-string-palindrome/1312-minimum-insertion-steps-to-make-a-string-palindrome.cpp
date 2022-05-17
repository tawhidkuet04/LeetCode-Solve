class Solution {
public:
    int solve(int start, int end, string &s, vector< vector< int> > &dp){
        
        if(start >= end) return 0;

        if(dp[start][end] != -1 ) return dp[start][end]; 
        
        int notTake = 1e8, leftTake = 1e8, rightTake = 1e8;
        if(s[start] == s[end]){
            notTake = solve(start + 1, end - 1, s, dp);
        }else{
            leftTake = 1 + solve(start + 1, end, s, dp);
            rightTake = 1 + solve(start, end - 1, s, dp);
        }
        
        return dp[start][end] = min(notTake, min(leftTake, rightTake));
        
    }
    
    int minInsertions(string s) {
        
        vector<vector<int> > dp(s.size(), vector<int> (s.size(), - 1));
        
        return solve(0, s.size()-1, s, dp)  ;
    }
};

// mbadm
// bad