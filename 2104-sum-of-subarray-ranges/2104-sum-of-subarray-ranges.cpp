class Solution {
public:
    
    long long getSubArrayMaxMinSum(vector<int>& nums, int isMin){
        stack<int> st;
        int sz = nums.size();
        vector<long long> cum(sz, 0);
        
        long long totSum = 0 ;
        
        for(int index = 0; index < sz; index ++ ){
            while(!st.empty() && ((!isMin) ? nums[st.top()] <= nums[index] :
                                           nums[st.top()] >= nums[index]  ) ){
                st.pop();
            }
            long long sum = 0;
            if(!st.empty()){
                int topIndex = st.top();
                sum = (long long)(index - topIndex) * (long long)nums[index];
                sum += cum[topIndex];
            }else{
                 sum = (long long)(index + 1) * (long long)nums[index];
            }
            cum[index] = sum;
            totSum += sum;
            
            st.push(index);
        }
        
        return totSum;
        
        
    }
    
    long long subArrayRanges(vector<int>& nums) {
        long long minSum = getSubArrayMaxMinSum(nums, true);
        long long maxSum = getSubArrayMaxMinSum(nums, false);
        return maxSum - minSum;
    }
};



// 1 2 3 4 5
    

    
// 1 2 3 
    
//     min = 2 * 1 + 2 * 1 + 
//     max = 2 * 1 + 3 * 2
    
//     6 + 2 --     2 + 2 
    
//     2 
//    3 * 2
    
    
//     3 4 1
    
    