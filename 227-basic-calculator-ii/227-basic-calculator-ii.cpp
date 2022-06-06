class Solution {
public:
    
    bool isNum(char c){
        return (c >= '0' && c <= '9');
    }
    
    int calculate(string s) {
        stack<int> st;
        
        int curNum = 0;
        char operation = '+';
        
        for(int index = 0; index < s.size(); index ++ ){
            if(isNum(s[index])){
                curNum = curNum * 10 + (s[index] - '0');
            }
            
            if( !isNum(s[index])  &&  s[index] != ' ' || index == s.size() - 1){
                if(operation == '+'){
                    st.push(curNum);
                }else if(operation == '-'){
                    st.push( -1 *curNum);
                }else if(operation == '/'){
                    int top = st.top();
                    st.pop();
                    
                    st.push(top/curNum);
                }else{
                     int top = st.top();
                    st.pop();
                    
                    st.push(top*curNum);
                }
                operation = s[index];
                curNum = 0;
        }
        }
            
        int ans = 0;
            
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        return ans;
        
    }
};

// 3 + 4 / 2 * 5
    
// +/