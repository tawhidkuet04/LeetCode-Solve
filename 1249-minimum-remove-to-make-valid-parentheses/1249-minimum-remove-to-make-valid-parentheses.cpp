class Solution {
public:
    
    
    string removeInvalidClosing(string &s, char open, char close){
         int balance = 0;
         int size = s.size();
         string sb = "";
        for(int index = 0; index < size; index ++ ){
            if(s[index] == open){
               balance ++ ;
            }else if(s[index] == close){
                if( balance == 0){
                    continue;
                }else{
                    balance -- ;
                }
            }
            sb += s[index];
        }
        return sb;
    }
    string minRemoveToMakeValid(string s) {
       
      string ans = removeInvalidClosing(s, '(', ')');
    reverse(ans.begin(), ans.end());
    ans = removeInvalidClosing(ans, ')', '(');
    reverse(ans.begin(), ans.end());
    return ans;
        
    }
};



