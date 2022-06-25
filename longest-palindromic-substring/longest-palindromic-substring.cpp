class Solution {
public:
    string longestPalindrome(string s) {
        int sz = s.size();
        int plStart = -1, plEnd  = -1, mx = 0;
        for(int index = 0; index < sz; index ++){
            int start = -1, end = -1;
            
            getPalindromeFromThisIndex(s, index - 1, index + 1, start, end);
            
            if(start != -1){
                if(end - start + 1 > mx){
                    mx = end - start + 1;
                    plStart = start;
                    plEnd = end;
                }
            }
            
            start = -1, end = -1;
            
            getPalindromeFromThisIndex(s, index, index + 1, start, end);
            
          
            
            if(start != -1){
                if(end - start + 1 > mx){
                    mx = end - start + 1;
                    plStart = start;
                    plEnd = end;
                }
            }
            
            
        }
       
        
        string ans = "";
        
         if(plStart == -1) {
             ans += s[0];
             return ans;
         }
        
        for(int index = plStart; index <= plEnd; index ++ ) ans += s[index];
        
        return ans;
        
        
    }
    
    void getPalindromeFromThisIndex(string &s, int startIndex, int endIndex, int &start, int &end){
        while(startIndex >= 0 && endIndex < s.size()){
            if(s[startIndex] != s[endIndex]){
                return;
            }else{
                start = startIndex;
                end = endIndex;
            }
            startIndex -- ;
            endIndex ++; 
        }
    }
};