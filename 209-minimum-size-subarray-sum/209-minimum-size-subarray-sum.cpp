class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX, windowStart = 0, sz = nums.size(), rangeSum = 0;
        
        for(int windowEnd = 0; windowEnd < sz; windowEnd ++ ){
            rangeSum += nums[windowEnd];
            
            while(rangeSum >= target){
                ans = min(ans, windowEnd - windowStart + 1);
                rangeSum -= nums[windowStart];
                windowStart ++ ;
            }
        }
        
        return (ans == INT_MAX) ? 0 : ans;
        
    }
};