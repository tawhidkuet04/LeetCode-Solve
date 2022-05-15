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
    
    int solveTabulation(string &text1, string &text2){

        vector<int> dp(text2.size() + 10, 0);
        
        
        for(int index1 = 1; index1 <= text1.size();  index1 ++ ){
             vector<int> tempDp(text2.size() + 10, 0);
            for(int index2 = 1; index2 <= text2.size(); index2 ++ ){
                int take = 0 ,takeFirst = 0, takeSecond = 0;
                if(text1[index1 - 1] == text2[index2 - 1]){
                    if( index1 - 1 >= 0 && index2 - 1 >= 0){
                        take = 1 + dp[index2 - 1];
                    }else{
                        take = 1 ;
                    }
                    
                }else{
                    if(index1 - 1 >= 0){
                        takeFirst = dp[index2];
                    }
                    if(index2 - 1 >= 0){
                        takeSecond = tempDp[index2 - 1];
                    }
                }
               tempDp[index2] = max(take, max(takeFirst, takeSecond));
            }
            dp = tempDp;
        }
        
        return dp[text2.size()];
        
        
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        vector< vector<int> > dp(text1.size() + 100, vector<int> (text2.size() + 100, 0));
        
        // return solve(0,0, text1, text2, dp);
        return solveTabulation(text1, text2);
    }
};

//  a b c d e
// a 1 
// c
// e