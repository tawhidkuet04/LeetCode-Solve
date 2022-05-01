class Solution {
public:
    string smallestSubsequence(string s) {
        int charMap[150] = {0};
        int charMapForStack[150] = {0};
        stack<int> st;
        int size = s.size();
        
        for( int index = 0; index < size; index ++ ){
            charMap[s[index]] = index  ;
        }
        for(int index = 0; index < size; index ++ ){
         
            if( charMapForStack[s[index]] == 0){
                
            while(!st.empty() && s[st.top()] >= s[index] && charMap[s[st.top()]] > index){
               
                    charMapForStack[s[st.top()]] --;
                    st.pop();
                }
                
                  charMapForStack[s[index]] ++;
                  st.push(index);
                
            }
                
               
            }
        
        string ans = "";
        
        while(!st.empty()){
            ans += s[st.top()];
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
       
        return ans;
    }
};