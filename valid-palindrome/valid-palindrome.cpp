class Solution {
public:
    
    bool isPalindrome(string s) {
        int size = s.size();
        int left = 0, right = size -1 ;
        while( left < right){
            if( !isalnum(s[left])){
                left ++;
                continue;
            }
            if(!isalnum(s[right])){
                right --;
                continue;
            }
            if(tolower(s[left]) == tolower(s[right])){
                left ++ ;
                right --;
            }else{
                return false;
            }
        }
        return true;
    }
};