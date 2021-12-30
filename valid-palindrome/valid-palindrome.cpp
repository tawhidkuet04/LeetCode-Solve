class Solution {
public:
    
    char makeLowerCase(char c){
        if(c >= 'A' && c <= 'Z'){
            c = c - 'A' + 'a';
        }
        return c;
    }
    bool checkIfValidCharecter(char lowerChar){
        lowerChar = makeLowerCase(lowerChar);
        if( (lowerChar >= '0' && lowerChar <= '9') || (lowerChar >= 'a' && lowerChar <= 'z')){
            return true;
        }else{
            return false;
        }
    }
    
    bool isPalindrome(string s) {
        int size = s.size();
        int left = 0, right = size -1 ;
        while( left < right){
            if( !checkIfValidCharecter(s[left])){
                left ++;
                continue;
            }
            if(!checkIfValidCharecter(s[right])){
                right --;
                continue;
            }
            if( makeLowerCase(s[left]) == makeLowerCase(s[right])){
                left ++ ;
                right --;
            }else{
                return false;
            }
        }
        return true;
    }
};