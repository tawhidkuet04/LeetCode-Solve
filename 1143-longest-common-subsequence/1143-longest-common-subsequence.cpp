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
    
    int solveTabulation(string &text1, string &text2,  vector< vector<int> > &dp){
        // string temp = text1;
        // text1 = text2;
        // text2 = temp;
        // cout << text1 << " " << text2 << endl;
        // if(text1[0] == text2[0])dp[0][0] = 1;
        // for(int index = 1 ; index < text2.size(); index ++ ){
        //     if(text1[0] == text2[index]){
        //          dp[0][index] = 1;
        //     }else{
        //         dp[0][index] = max(dp[0][index - 1], 0);
        //     }
        // }
        // for(int index = 1 ; index < text1.size(); index ++ ){
        //     if(text1[index] == text2[0]){
        //          dp[index][0]  = 1;
        //     }else{
        //       dp[index][0] = max(dp[index - 1][0], 0);
        //     }
        // }
        
        for(int index1 = 0; index1 < text1.size();  index1 ++ ){
            for(int index2 = 0; index2 < text2.size(); index2 ++ ){
                int take = 0 ,takeFirst = 0, takeSecond = 0;
                if(text1[index1] == text2[index2]){
                    if( index1 - 1 >= 0 && index2 - 1 >= 0){
                        take = 1 + dp[index1 - 1][index2 - 1];
                    }else{
                        take = 1 ;
                    }
                    
                }else{
                    if(index1 - 1 >= 0){
                         takeFirst = dp[index1 - 1][index2];
                    }
                    if(index2 - 1 >= 0){
                    takeSecond = dp[index1][index2 - 1];
                    }
                }
               dp[index1][index2] = max(take, max(takeFirst, takeSecond));
            }
        }
        
        //  for(int index1 = 0; index1 < text1.size();  index1 ++ ){
        //     for(int index2 = 0; index2 < text2.size(); index2 ++ ){
        //         cout <<  dp[index1][index2] << " ";
        //     }
        //      cout << endl;
        // }
        
        
        return dp[text1.size() - 1][text2.size() - 1];
        
        
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        vector< vector<int> > dp(text1.size() + 100, vector<int> (text2.size() + 100, 0));
        
        // return solve(0,0, text1, text2, dp);
        return solveTabulation(text1, text2, dp);
    }
};

//  a b c d e
// a 1 
// c
// e