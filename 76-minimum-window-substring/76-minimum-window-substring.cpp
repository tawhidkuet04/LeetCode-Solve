class Solution {
public:
    
    bool isValid(int sMap[], int tMap[]){
        
        for(char ch = 'A'; ch <= 'Z'; ch ++ ){
            if(sMap[ch] < tMap[ch]){
                return false;
            }
        }
        for(char ch = 'a'; ch <= 'z'; ch ++ ){
            if(sMap[ch] < tMap[ch]){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        // if(t.size() > s.size()) return "";
        int sMap[200] = {0};
        int tMap[200] = {0};
        
        for(char &ch : t){
            tMap[ch] ++ ;
        }
        
        int windowStart = 0, size = s.size();
        int left = -1, right = -1, mn = INT_MAX;
        
        for(int windowEnd = 0; windowEnd < size; windowEnd ++ ){
            sMap[s[windowEnd]] ++ ;
            
            while(isValid(sMap, tMap) && windowStart <= windowEnd){
                int range = windowEnd - windowStart + 1;
                if(mn > range ){
                    mn = range;
                    left = windowStart;
                    right = windowEnd;
                }
                sMap[s[windowStart]] -- ;
                windowStart ++ ;
            }
        }
        if(left == -1) return "";
        string ans = "";
        for(int index = left; index <= right; index ++ ){
            ans += s[index];
        }
        
        return ans;
        
    }
};