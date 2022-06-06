class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> mp;
        mp["M"] = 1000;
        mp["CM"] = 900;
        mp["D"] = 500;
        mp["CD"] = 400;
        mp["C"] = 100;
        mp["XC"] = 90;
        mp["L"] = 50;
        mp["XL"] = 40;
        mp["X"] = 10;
        mp["IX"] = 9;
        mp["V"] = 5;
        mp["IV"] = 4;
        mp["I"] = 1;
        
         int ans = 0;
        for(int index = 0; index < s.size(); index ++ ){
            cout << s[index] << endl;
            string curSymbol = "";
            curSymbol += s[index];
            if(index + 1 < s.size()){
                if(mp[curSymbol] < mp[curSymbol + s[index + 1]]){
                    curSymbol += s[index + 1];
                    index ++ ;
                }
            }
            ans += mp[curSymbol];
        }
        
        return ans;
           
    }
};

