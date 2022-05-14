class Solution {
public:
    
    bool solve(int index, int sum1, vector<int>& nums, int first , int second, int &sum,  vector< vector<optional<bool>> > &dp){
        if(sum1 == (sum - sum1) && sum1 != 0 && (first + second) == nums.size()) {
            return true;
        }
        if(index >= nums.size()) return false;
        
        if(dp[index][sum1] != nullopt) {
            return (dp[index][sum1] == true);
        }
        
        bool takeAndNotTake = solve(index + 1, sum1 + nums[index], nums,  first + 1, second, sum, dp);
        bool notTakeAndTake = solve(index + 1, sum1, nums, first, second + 1, sum, dp);
        
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
        int subsetSum = sum + 100;
        vector< vector<optional<bool>> > dp(sz + 1, vector<optional<bool>> (subsetSum, nullopt));
        return solve(0, 0 , nums, 0,0, sum, dp);
    }
};