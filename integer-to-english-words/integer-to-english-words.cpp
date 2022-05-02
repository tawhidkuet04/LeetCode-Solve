class Solution {
public:
    
    string digits[21] = {"saa", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", 
                        "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen","Sixteen",
                         "Seventeen", "Eighteen", "Nineteen"
                        };
    string tens[10] = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty",
                      "Ninety"};
    
    string intToString(int num){
        cout << num << endl;
        if( num >= 1000000000){
            return intToString(num/1000000000) + " Billion" +  intToString(num%1000000000);
        }else  if( num >= 1000000){ 
              return intToString(num/1000000) + " Million" +  intToString(num%1000000);
        }else  if( num >= 1000){ 
              return intToString(num/1000) + " Thousand" +  intToString(num%1000);
        }else  if( num >= 100){ 
              return intToString(num/100) + " Hundred" +  intToString(num%100);
        }else  if( num >= 20){ 
              return " "+ tens[num/10] + intToString(num%10);
        }else  if( num >= 1){ 
              return " " + digits[num%20];
        }else return "";
    }
    
    string numberToWords(int num) {
        if(num == 0 ) return "Zero";
        string ans =  intToString(num);
        return ans.substr(1, ans.length() - 1);
    }
};

// 123456789
    
//     1
//     2
//     3 --> 1 2
//     4 --> 1 (3)
//     5 --> 2 (3)
//     6 --> (3) (3)
//     7 -->  1 (6)
//     8 -->  2 (6)
//     9 -->  3 (6)
    