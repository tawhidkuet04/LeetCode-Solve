class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0) return 0;
        int product = 1, windowStart = 0, size = nums.size(), ans = 0 ;
        
        for(int windowEnd = 0; windowEnd < size; windowEnd ++ ){
            product *= nums[windowEnd];
            
            while(product >= k && windowStart <= windowEnd){
                product /= nums[windowStart];
                windowStart ++;
            }
            
            int range = windowEnd - windowStart + 1;
            ans += range;
        }
        
        return ans;
        
    }
};

// n + n - 1 + n - 2 + n - 3 + n - 4
    
// 5n - (1 + 2 + 3 + 4)
    
// 4 * 5 -   4 * ( 4 + 1) / 2