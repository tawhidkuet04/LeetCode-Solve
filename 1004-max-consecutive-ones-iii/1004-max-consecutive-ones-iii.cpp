class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zero = 0, one = 0, ans = 0, windowStart = 0, sz = nums.size();
        
//         if(k == 0 ){
            
//         }
        
        for(int windowEnd = 0; windowEnd < sz; windowEnd ++ ){
             int val = nums[windowEnd];
            
             if(val == 0) zero ++ ;
            
            while(windowStart <= windowEnd && zero > k){
                if(nums[windowStart] == 0) zero -- ;
                windowStart ++ ;
            }
            
            ans = max(ans, windowEnd - windowStart + 1);
        }
        
        return ans;
    }
};