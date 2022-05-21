class Solution {
public:
    int solve(vector<int> &nums, int k){
      
        int windowStart = 0, sz = nums.size(), odd = 0, ans = 0;
        
        for(int windowEnd = 0; windowEnd < sz; windowEnd ++ ){
            if(nums[windowEnd] % 2 == 1){
                odd ++ ;
            }
            
            while( windowStart <= windowEnd && odd > k){
                 if(nums[windowStart] % 2 == 1){
                    odd -- ;
                }
                windowStart ++ ;
            }
            
            ans += windowEnd - windowStart + 1;
        }
        return ans;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k ) - solve(nums, k - 1);
    }
};