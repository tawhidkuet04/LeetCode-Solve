class Solution {
public:
    bool isPalindrome(int x) {
        if( x < 0 ) return false;
        
        int reverseNum = 0 ;
        int num = x;
        
        while(num){
            int dig = num % 10 ;
            if( reverseNum > INT_MAX / 10 ) return false;
            reverseNum = reverseNum * 10 + dig;
        
            num /= 10 ;
        }
        
        if( reverseNum == x) return true;
        else return false;
    }
};