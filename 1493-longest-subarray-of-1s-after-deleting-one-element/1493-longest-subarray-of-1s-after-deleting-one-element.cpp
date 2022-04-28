class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxSubCount = 0 , windowStart = 0, size = nums.size(), cnt = 0, zeroCount = 0;
        int oneCount = 0;
        
        for(int windowEnd = 0; windowEnd < size; windowEnd ++){
            
            if( nums[windowEnd] == 1 ){
                cnt ++ ;
                oneCount ++;
            }else{
                zeroCount++;
            }
            
            while( zeroCount > 1 && windowStart < windowEnd){
                if(nums[windowStart] == 1) cnt --;
                else zeroCount --;
                windowStart ++;
            }
            maxSubCount = max(maxSubCount, cnt);
        }
        if(oneCount == size) return oneCount - 1;
        return maxSubCount;
    }
};