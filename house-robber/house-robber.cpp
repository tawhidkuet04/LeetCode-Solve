class Solution {
public:
    int solve(int index, int prevTaken, vector<int> &nums,  vector< vector<int> > &dp){
        if(index >= nums.size()) return 0;
        
        if(dp[index][prevTaken]!= - 1) return dp[index][prevTaken];
        
        int take = 0;
        if(prevTaken == 0){
             take = nums[index] + solve(index + 1, 1, nums, dp);
        }
        int notTake = solve(index + 1,0, nums, dp);
        
        return dp[index][prevTaken] = max(take, notTake);
        
    }
    
    int rob(vector<int>& nums) {
        vector< vector<int> > dp(nums.size() + 1 , vector<int> (3, -1));
        return solve(0,0, nums, dp);
    }
};