class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        stack<int> st ;
        int size = arr.size();
        
        int mod = 1000000000 + 7, ans = 0 ;
        
        int previousLess[30000+10] = {0};
        
        for(int index = 0; index < size; index ++ ){
            while(!st.empty() && arr[st.top()] >= arr[index]){
                st.pop();
            }
            
            
            int curAns = 0 ;
            if(!st.empty()){
                int topIndex = st.top();

                curAns =  (arr[index]  % mod * (index - topIndex) % mod) % mod; 
                curAns  = (curAns % mod + (previousLess[topIndex] % mod) ) % mod;
            }else{
                 curAns  = (arr[index] % mod * (index + 1)  % mod) % mod;
            }
            ans = (ans % mod + curAns % mod ) % mod;
            previousLess[index] = curAns;
        
            st.push(index);
        }
        
        return ans;
        
    }
};


// 0 1 2 3 4
// 3 1 2 2 4
    
// 0  1  2  3  4
// 11 81 94 43 3

// 3 + 2 + 2 + 2 + 4 + 2 + 