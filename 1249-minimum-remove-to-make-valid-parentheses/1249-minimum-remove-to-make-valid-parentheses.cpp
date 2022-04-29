class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0;
        
        int size = s.size();
        
        for(int index = 0; index < size; index ++ ){
            if(s[index] == '('){
               open ++ ;
            }else if(s[index] == ')'){
                if( open == 0){
                    s[index] = '#';
                }else{
                    open -- ;
                }
            }
        }
        
        open = 0;
        
         for(int index = size - 1; index >= 0 ; index -- ){
            if(s[index] == ')'){
               open ++ ;
            }else if(s[index] == '('){
                if( open == 0){
                    s[index] = '#';
                }else{
                    open -- ;
                }
            }
        }
        
        // if(open > 0 ) return "";
        
        string validStr = "";
        
        for(int index = 0; index < size; index ++){
          if(s[index] != '#') validStr += s[index];
        }
        
        return validStr;
        
    }
};



