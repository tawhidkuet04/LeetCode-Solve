class Solution {
public:
    
    bool checkIfInRange(int &num, int numToAdd){
        if( (num > (INT_MAX/10)) || ( (num == (INT_MAX/10)) && numToAdd > (INT_MAX %10))){
            return false;
        }
        return true;
        
    }
    
    int myAtoi(string s) {
        int sign = 1;
        
        int index = 0, size = s.size();
        
        int num = 0;
        
        while(index < size && s[index] == ' '){
            index ++ ;
        }
        
        if(index < size  && s[index] == '+'){
            index ++ ;
        }else  if(index < size && s[index] == '-'){
            sign = -1;
            index ++;
        }
        
        
        while(index < size && isdigit(s[index])){
            // cout << s[index] << endl;
            int dig = s[index] - '0';
            if(checkIfInRange(num, dig)){
                num = num * 10 + dig;
            }else{
                if(sign == 1){
                    return INT_MAX;
                }else return INT_MIN;
            }
            index ++;
            
        }
        
         return num * sign;
    }
};