class Solution {
public:
    void computeLCS(string str1, string str2,   vector< vector<int> > &dp){
        int str1Size = str1.size();
        int str2Size = str2.size();
        
        for(int index1= 1; index1 <= str1Size; index1 ++ ){
            for(int index2 = 1; index2 <= str2Size; index2 ++ ){
                if(str1[index1 - 1] == str2[index2 - 1]){
                    dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];
                }else{
                    dp[index1][index2] = max(dp[index1 - 1][index2], 
                                             dp[index1][index2 - 1]);
                }
            }
        }
    }
    
    
    string storeLCSPath(string str1, string str2,  vector< vector<int> > &dp){
        
        int str1Size = str1.size();
        int str2Size = str2.size();
        
        int i = str1Size, j = str2Size;
        string lcs = "";
        
        
        while( i > 0 && j > 0){
            if(str1[i - 1] == str2[j - 1]){
                lcs += str1[i - 1];
                
                i -- ;
                j --;
                
            }else{
                 
                
                 if(dp[i - 1][j] > dp[i][ j - 1]){
                    lcs += str1[i - 1];
                    i -- ;
                }else{
                    lcs += str2[j - 1];
                    j -- ;
                }
                
            }
        }
        
        while( i > 0 ){
            lcs += str1[i - 1];
            i -- ;
        }
    
        while( j > 0 ){
            lcs += str2[j - 1];
            j -- ;
        }
        
        reverse(lcs.begin(), lcs.end());
       // cout << lcs << endl;
        
        return lcs;
    }
    
    string shortestCommonSupersequence(string str1, string str2) {
        
        int str1Size = str1.size();
        int str2Size = str2.size();
        
        vector< vector<int> > dp(str1Size + 1, vector<int> (str2Size + 1, 0));
        
        
        computeLCS(str1, str2, dp);
        
        
        return storeLCSPath(str1, str2, dp);
        
        
    }
};

// das d as d asd
// das  as  asdsd

// ab acc


//     a b a c
   
//   c 0 0  0 1
  
//   a 1 1 1  1 
  
//   b 1 2 2  2
          
        
//       0 1 2 2 2 