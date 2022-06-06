class Solution {
public:
    int getVal( string str, string roman[], int num[]){
        for(int index = 0; index < 13; index ++ ){
            if(str == roman[index]){
                return num[index];
            }
        }
        return 0;
    }
    
    int romanToInt(string s) {
          string roman[13] = {"M", "CM","D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
          int num[13] = { 1000, 900 , 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
          
         int ans = 0;
        for(int index = 0; index < s.size(); index ++ ){
            cout << s[index] << endl;
            string curSymbol = "";
            curSymbol += s[index];
            if(index + 1 < s.size()){
                if(getVal(curSymbol, roman, num) < getVal(curSymbol + s[index + 1], roman, num)){
                    curSymbol += s[index + 1];
                    index ++ ;
                }
            }
            cout << curSymbol << endl;
            ans += getVal(curSymbol, roman, num);
        }
        
        return ans;
           
    }
};

