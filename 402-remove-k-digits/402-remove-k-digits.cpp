class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        int size = num.size();
        
        for(int index = 0; index < size; index ++ ){
            while(!st.empty() && num[st.top()] > num[index] && k ){
                  k -- ;
                  st.pop();
            }
             st.push(index);
            
        }
        while(k && !st.empty()){
            st.pop();
            k -- ;
        }
        string ans = "";
        
        while(!st.empty()){
            ans += num[st.top()];
            st.pop();
        }
        // cout << ans << endl;
         while(!ans.empty() && ans.back() == '0'){
             ans.pop_back();
         }
        reverse(ans.begin(), ans.end());
        
       
        if(ans.size() == 0 ) return "0";
        return ans;
    }
};
