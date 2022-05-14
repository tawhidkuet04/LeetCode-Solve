class Solution {
public:
    
    bool solve(int index, int sum1, vector<int>& nums, int first , int second, int &sum,  vector< vector<int> > &dp){
        if(sum1 == (sum - sum1) && sum1 != 0 && (first + second) == nums.size()) {
            return true;
        }
        if(index >= nums.size()) return false;
        
        if(dp[index][sum1] != -1) return dp[index][sum1];
        
        bool takeAndNotTake = solve(index + 1, sum1 + nums[index], nums,  first + 1, second, sum, dp);
        bool notTakeAndTake = solve(index + 1, sum1, nums, first, second + 1, sum, dp);
        
        return dp[index][sum1] = (takeAndNotTake | notTakeAndTake);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int sz = nums.size();
        
        vector< vector<int> > dp(sz, vector<int> (20009, -1));
        for(int index = 0; index < sz; index ++ ){
            sum += nums[index];
        }
        return solve(0, 0 , nums, 0,0, sum, dp);
    }
};