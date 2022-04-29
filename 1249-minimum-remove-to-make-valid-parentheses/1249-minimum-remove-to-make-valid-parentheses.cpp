class Solution {
public:
    string minRemoveToMakeValid(string s) {
        unordered_set<int> charSet;
        
        stack<int> st;
        
        int size = s.size();
        
        for(int index = 0; index < size; index ++ ){
            if(s[index] == '('){
                st.push(index);
            }else if(s[index] == ')'){
                if(st.size() > 0){
                    charSet.insert(st.top());
                    st.pop();
                    charSet.insert(index);
                }
            }
        }
        
        string validStr = "";
        
        for(int index = 0; index < size; index ++){
            if(isalpha(s[index])){
                validStr += s[index];
            }else{
                if(charSet.find(index) != charSet.end()){
                    validStr += s[index];
                } 
            }
        }
        
        return validStr;
        
    }
};



