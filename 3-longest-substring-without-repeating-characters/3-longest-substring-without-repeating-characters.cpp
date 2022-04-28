class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charMap;
        
        int windowStart = 0, count = 0, maxSubLength = 0, size = s.size();
        
        for(int windowEnd = 0; windowEnd < size; windowEnd++){
             int charIndex = s[windowEnd];
             charMap[charIndex] ++ ;
             
             while(charMap[charIndex] > 1){
                 int newCharIndex = s[windowStart] ;
                 charMap[newCharIndex] -- ;
                 windowStart ++ ;
             }
            
            maxSubLength = max(maxSubLength, windowEnd - windowStart + 1);
        }
        
        return maxSubLength;
    }
};