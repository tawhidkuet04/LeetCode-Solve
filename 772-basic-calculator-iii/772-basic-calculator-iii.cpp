class Solution {
public:
    
    bool isNum(char c){
        return (c >= '0' && c <= '9');
    }
    
    int solve(string s){
        int curVal = 0;
        char operation = '+';
        
        stack<int> st;
        
        for(int index = 0; index < s.size(); index ++ ){
           
            if( isNum(s[index])){
                curVal = curVal * 10 + (s[index] - '0');
            }
            
            int cnt = 0;
            if(s[index] == '('){
                index ++;
                cnt ++;
                string bracketExpression = "";
                while(cnt){
                    if(s[index] == '(') cnt ++;
                    else if(s[index] == ')') cnt --;
                    if(cnt == 0) break;
                    bracketExpression += s[index];
                    index ++;
                }
                
                 curVal = solve(bracketExpression);
                
            }
            
            if(!isNum(s[index]) || index == s.size() - 1){
                if(operation == '+'){
                    st.push(curVal);
                }else if(operation == '-'){
                    st.push(-1 * curVal);
                }else if(operation == '/'){
                    int top = st.top();
                    st.pop();
                    st.push(top/curVal);
                }else if(operation == '*'){
                     int top = st.top();
                     st.pop();
                     st.push(top*curVal);
                    cout << top*curVal << endl;
                }
                curVal = 0;
                operation = s[index];
            }
            
            
        }
        
        int ans = 0;
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
    
    int calculate(string s) {
        return solve(s);
    }
};


// +2 * (5