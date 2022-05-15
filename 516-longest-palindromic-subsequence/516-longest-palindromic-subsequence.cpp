class Solution {
public:
    int solve(int start, int end, string &s, vector< vector<int> > &dp){
        if( start > end){
            return 0;
        }
        
        if(start == end){
            if(s[start] == s[end]) return 1;
            else return 0;
        }
        
        
        if(dp[start][end] != -1 ) return dp[start][end];
        
        int take = 0, takeFirst = 0, takeSecond = 0;
        if( s[start] == s[end]){
            take = 2 + solve(start + 1, end - 1, s, dp);
        }
        
        takeFirst = solve(start + 1, end, s, dp);
        takeSecond = solve(start, end - 1, s, dp);
        
        
        return dp[start][end] = max(take, max(takeFirst, takeSecond));
        
    }
    
   
    int longestPalindromeSubseq(string s) {
        vector< vector< int > > dp(s.size() + 1, vector<int> (s.size() + 1, - 1));
        
        // reverse and lcs
        // return solveTabulation(s);
        
        return solve(0, s.size() - 1, s, dp);
    }
};