class Solution {
public:
    
    bool solve(int index, int sum1, vector<int>& nums,  vector< vector<optional<bool>> > &dp){
        if(sum1 == 0) {
            return true;
        }
        if(index >= nums.size() || sum1 < 0) return false;
        
        if(dp[index][sum1] != nullopt) {
            return (dp[index][sum1] == true);
        }
        
        bool takeAndNotTake = solve(index + 1, sum1 - nums[index], nums, dp);
        bool notTakeAndTake = solve(index + 1, sum1, nums, dp);
        
      dp[index][sum1] = (takeAndNotTake | notTakeAndTake);
      return (takeAndNotTake | notTakeAndTake);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int sz = nums.size();
        
       
        for(int index = 0; index < sz; index ++ ){
            sum += nums[index];
        }
        if(sum % 2 == 1) return false;
        int subsetSum = sum /2;
        vector< vector<optional<bool>> > dp(sz + 1, vector<optional<bool>> (subsetSum + 1, nullopt));
        return solve(0, subsetSum , nums, dp);
    }
};