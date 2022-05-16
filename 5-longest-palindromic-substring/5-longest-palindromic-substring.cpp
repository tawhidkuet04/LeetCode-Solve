class Solution {
public:
    string longestPalindrome(string s) {
       int sz = s.size();
       vector< vector<int> >dp(sz + 10, vector<int> (sz + 10, 0 ));
       int mx = 1, startIndex = 0;
        
       if(s.size() == 1) return s;
       for(int index = 0; index < sz - 1; index ++ ){
            dp[index][index] = 1;
            if(s[index] == s[index + 1]){
                dp[index][index + 1] = 1;
                mx = 2;
                startIndex = index;
             }
        }
        

        
       
        for(int length = 2; length < sz; length ++ ){
            for(int start = 0 ; start < sz; start ++ ){
                 int end = start + length;
                 if(end < sz){
                     if(s[start] == s[end] && dp[start + 1][end - 1] == 1){
                      if( (length + 1) > mx){
                          mx = length + 1;
                          startIndex = start;
                      }
                       dp[start][end] = 1;
                    }
                
                 }
                  
                
            }
        }
        
        cout << startIndex << " " << mx << endl;
        string ans = "";
        for(int start = startIndex; start < startIndex + mx; start ++ ){
            ans += s[start];
        }
        
        return ans;
        
    }
};

