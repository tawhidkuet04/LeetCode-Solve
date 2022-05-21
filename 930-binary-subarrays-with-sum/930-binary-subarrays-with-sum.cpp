class Solution {
public:
    
    
    int solve( vector<int> & nums, int goal){
        
        int windowStart = 0, sz = nums.size(), sum = 0 , ans = 0;
        
        for(int windowEnd = 0; windowEnd < sz; windowEnd ++ ){
            sum += nums[windowEnd];
            
            while( windowStart < windowEnd && sum > goal){
                sum -= nums[windowStart];
                windowStart ++ ;
            }
            
            if(sum <= goal){
                ans += windowEnd - windowStart + 1;
            }
        }
        
    
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       return solve(nums, goal) - solve(nums, goal - 1);
    }
};