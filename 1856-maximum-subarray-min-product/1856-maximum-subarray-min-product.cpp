class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int previousLess[100005], nextLess[100005];
        
        stack<int> st;
        
        int size = nums.size();
        
        for(int index = 0; index < size; index ++){
            while(!st.empty() && nums[st.top()] >= nums[index]){
                st.pop();
            }
            
            if(!st.empty()){
                previousLess[index] = st.top() + 1;
            }else{
                previousLess[index] = 0;
            }
            
            st.push(index);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int index = size - 1; index >= 0; index --){
            while(!st.empty() && nums[st.top()] >= nums[index]){
                st.pop();
            }
            
            if(!st.empty()){
                nextLess[index] = st.top() - 1;
            }else{
                nextLess[index] = size - 1;
            }
            
            st.push(index);
        }
        
        int mod = 1000000000 + 7;
        
        long long  ans = 0;
        
        long long cum[100005] = {0};
        for(int index = 1; index <= size; index ++){
            cum[index] = (cum[index - 1]   + nums[index - 1] ) ;
        }
        
        for(int index = 0; index < size; index ++){
            // cout << (cum[nextLess[index] + 1] - cum[previousLess[index]])  << endl;
            long long int minProd = (cum[nextLess[index] + 1] - cum[previousLess[index]])  * (nums[index]);
            
            ans = max(ans, minProd  );
            
            
        }
        
        return ans % mod;
    }
};