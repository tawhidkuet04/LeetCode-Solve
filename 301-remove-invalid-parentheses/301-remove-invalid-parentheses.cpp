class Solution {
public:
    
    
    bool isLetter(char c){
        if( c >= 'a' && c <= 'z') return true;
        else return false;
    }
    
    int getMinRemoveParentheses(string &s){
        stack<char> st;
        for(auto &character: s){
            if(character == '('){
                st.push(character);
            }else if(character == ')'){
                if(!st.empty()){
                    if(st.top() == '(') st.pop();
                    else {
                        st.push(character);
                    }
                }else{
                    st.push(character);
                }
            }
        }
        
        return st.size();
        
    }
    
    void generateParenthases(string s,
                            vector<string> &ans, int minToRemove,
                            unordered_map<string,int> &mp){

        if(mp[s] != 0){
            return;
        }else{
           mp[s] ++;
        }
        if(  minToRemove  < 0){
            return;
        }
        
        if(minToRemove == 0){
            if(getMinRemoveParentheses(s) == 0){
                ans.push_back(s);
                return;
            }
            return;
        }
    
        
        for(int start = 0; start < s.size(); start ++ ){
            string left = s.substr(0, start);
            string right = s.substr(start+1);
            generateParenthases(left + right , ans, minToRemove - 1, mp);
        }

        
    }
    
    
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_map<string,int> mp;
        generateParenthases(s, ans, getMinRemoveParentheses(s), mp);
        
        return ans;
    }
};