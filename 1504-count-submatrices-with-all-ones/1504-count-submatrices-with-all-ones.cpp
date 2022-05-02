class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int h[155] = {0};
        int rowSize = mat.size();
        int colSize = mat[0].size();
        
        int ans = 0 ;
        
        for(int row = 0; row < rowSize; row ++){
            for(int col = 0; col < colSize; col ++){
                if(mat[row][col]) h[col] += 1;
                else h[col] = 0; 
            }
            
            stack<int> st;
            int sum[150] = {0};
            for(int index = 0; index < colSize; index ++ ){
                while(!st.empty() && h[st.top()] >= h[index]){
                    st.pop();
                }
                
                if(!st.empty()){
                    sum[index] = (index - st.top()) * h[index];
                    sum[index] += sum[st.top()];
                }else{
                     sum[index] = (index + 1) * h[index];
                }
                ans += sum[index];
                st.push(index);
            }
            
        }
        
        return ans;
    }
};

//   1  1     2
//   2  2 1   2 + 4 + 3
// 1 3  3 0  1 + 3 + 6