class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int size = heights.size();
        int previousGreater[100005];

        // st.push(0);
        for(int index = 0; index < size ; index ++ ){
            while(!st.empty() && heights[st.top()] >= heights[index]){
                st.pop();
            }
            
            if(!st.empty()){
                previousGreater[index] = st.top() + 1;
            }else{
                previousGreater[index] = 0;
            }
            st.push(index);
            
        }
        
        int ans = 0 ;
        while(!st.empty()) {
            st.pop();
        }
        
        // 1 4 3 4 1
        
        // st.push(size - 1);
        
        for(int index = size - 1; index >= 0 ; index -- ){
            while(!st.empty() && heights[st.top()] >= heights[index]){
                st.pop();
            } 
            int leftRange = previousGreater[index];
            if(!st.empty()){
                
                 int rightRange = (st.top() - 1);
                 ans = max(ans, heights[index] * (rightRange - leftRange + 1));
                
            }else{
               
                 ans = max(ans, heights[index] * (size - 1 - leftRange + 1));
            }
            
            st.push(index);
        }
        return ans;
    }
};