class Solution {
public:
    
    bool solve(int index, vector<int> &nums, vector<int> &dp){
        if(index >= nums.size() - 1){
            return true;
        }
        
        if(dp[index] != -1) return dp[index];
        
        for(int start = 1; start <= nums[index]; start ++ ){
            if(solve(index + start, nums, dp)){
                return dp[index] = true;
            }
        }
        
        return dp[index] = false;
    }
    
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), - 1);
        
        return solve(0, nums, dp);
    }
};