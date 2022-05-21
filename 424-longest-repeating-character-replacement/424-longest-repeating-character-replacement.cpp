class Solution {
public:
    bool isValid(string s, unordered_map<char, int >& mp, int range, int k){
        
        int mx = 0;
        
        for(char ch = 'A'; ch <= 'Z'; ch ++ ){
            if(mp[ch] >=  mx){
                mx = mp[ch];
            }
        }
        
        if( (range - mx)  <= k) return true;
        else return false;
        
    }
    
    
    int characterReplacement(string s, int k) {
        unordered_map<char, int > mp;
        
        int ans = 0, windowStart = 0, sz = s.size() ;
        
        
        for(int windowEnd = 0; windowEnd < sz; windowEnd ++ ){
             char curChar = s[windowEnd];
             mp[curChar]++;
            
            int range = windowEnd - windowStart + 1;
            
            while(windowStart < windowEnd && !isValid(s, mp, range, k)){
                char prevChar = s[windowStart];
                mp[prevChar] -- ;
                windowStart ++ ;
                range = windowEnd - windowStart + 1;
            }
            
            ans = max(ans, windowEnd - windowStart + 1);
        }
        
        return ans;
        
        
    }
};


// C

// 1BBBA