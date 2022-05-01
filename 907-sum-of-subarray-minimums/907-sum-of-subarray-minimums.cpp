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

                curAns =  (arr[index] * (index - topIndex)) % mod; 
                curAns  = (curAns + (previousLess[topIndex]) ) % mod;
            }else{
                 curAns  = (arr[index] * (index + 1)) % mod;
            }
            ans = (ans + curAns ) % mod;
            
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