class Solution {
public:
    string countAndSay(int n) {
       
        string base = "11";
        
        if( n == 1) return "1";
        else if(n == 2) return base;
      
        
        for(int index = 3; index <= n ; index ++ ){
            string newBase = "";
            
            int cnt = 1;
            
            for(int i = 1; i < base.size(); i ++ ){
                if(base[i] != base[i - 1]){
                    newBase += to_string(cnt) + base[i - 1];
                    cnt = 1;
                }else{
                    cnt ++;
                }
            }
            
            newBase += to_string(cnt) + base[base.size() - 1];
            
            base = newBase;
            
        }
        
        return base;
        
        
        
    }
};