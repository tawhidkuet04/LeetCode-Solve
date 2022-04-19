class Solution {
public:
    
    
    string add(string n, string m){
            string res;
            int i=n.size()-1, j=m.size()-1, carry=0;
            while(i>=0 || j>=0){
                int sum=carry+(i>=0 ? (n[i--]-'0') : 0) + (j>=0?  (m[j--]-'0') : 0);
                res.push_back(sum%10+'0');
                carry=sum/10;
            }
            if(carry) res.push_back(carry+'0');
            reverse(res.begin(), res.end());
            return res;
        }
    
    
    
    bool isSumEqual(string first, string second, string third){
        if(first.size() != 0 && second.size() != 0 && third.size() != 0){
             if( add(first, second) == third){
                 // cout << first << " " << second << " sdsd" << third  << endl;
                    return true;
                }else{
                    return false;
                }
        }else{
            return false;
        }
       
    }
    
    bool isAdditive(int index, string firstNum, string secondNum, string thirdNum, int numberChoosed, string num){
         if (firstNum.size() > 1 && firstNum[0] == '0' ) return  false;
         if (secondNum.size() > 1 && secondNum[0] == '0' ) return  false;
         if (thirdNum.size() > 1 && thirdNum[0] == '0' ) return  false;
        if(index >= num.size()){
           if(isSumEqual(firstNum, secondNum, thirdNum)){
                return true;
            }else{
                return false;
            }
        }
      
        bool isValid = false;
        
        for(int start = index; start < num.size(); start ++ ){
            if(isValid){
                break;
            }
            if(numberChoosed == 0){
                firstNum += num[start];
                isValid |= isAdditive(start + 1, firstNum , secondNum, thirdNum, numberChoosed + 1, num);
            }else if(numberChoosed == 1){
                secondNum += num[start];
                isValid |= isAdditive(start + 1, firstNum, secondNum , thirdNum, numberChoosed + 1, num);
            }else{
                thirdNum += num[start];
                
                if(isSumEqual(firstNum, secondNum, thirdNum)){
                    if(start == num.size() - 1) {
                        return true;
                    }
                    isValid |= isAdditive(start + 1, secondNum, thirdNum, "", numberChoosed, num);
                }else if( thirdNum.size() > (firstNum.size() + secondNum.size())){
                    return isValid | false;
                }
                else{
                    isValid |= isAdditive(start + 1, firstNum, secondNum, thirdNum, numberChoosed, num);
                }
                
            }
        }
        return isValid;
        
        
        
    }
    
    
    bool isAdditiveNumber(string num) {
        return isAdditive(0, "", "" , "", 0, num);
    }
};