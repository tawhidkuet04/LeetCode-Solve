class Solution {
public:
    
    int solve (int index1, int index2, string &text1, string &text2,
              vector< vector<int> > &dp){

        if(index1 >= text1.size() || index2 >= text2.size()){
            return 0;
        }
        
        
        if(dp[index1][index2] != -1 ) return dp[index1][index2];
        int take = -1e8 , takeFirst = -1e8, takeSecond = -1e8;
        if(text1[index1] == text2[index2]){
            take = 1 + solve(index1 + 1, index2 + 1, text1, text2, dp);
        }else{
            takeFirst = solve(index1 + 1, index2, text1, text2, dp);
            takeSecond = solve(index1, index2 + 1, text1, text2, dp);
        }
        
        
        return dp[index1][index2] = max(take, max(takeFirst, takeSecond));
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector< vector<int> > dp(text1.size(), vector<int> (text2.size(), -1));
        
        return solve(0,0, text1, text2, dp);
    }
};