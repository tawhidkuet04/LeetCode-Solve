class Solution {
public:
    
//     bool solve(int index, int sum1, vector<int>& nums,  vector< vector<optional<bool>> > &dp){
//         if(sum1 == 0) {
//             return true;
//         }
//         if(index >= nums.size() || sum1 < 0) return false;
        
//         if(dp[index][sum1] != nullopt) {
//             return (dp[index][sum1] == true);
//         }
        
//         bool takeAndNotTake = solve(index + 1, sum1 - nums[index], nums, dp);
//         bool notTakeAndTake = solve(index + 1, sum1, nums, dp);
        
//       dp[index][sum1] = (takeAndNotTake | notTakeAndTake);
//       return (takeAndNotTake | notTakeAndTake);
//     }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int sz = nums.size();
        
       
        for(int index = 0; index < sz; index ++ ){
            sum += nums[index];
        }
        if(sum % 2 == 1) return false;
        int subsetSum = sum /2;
        vector< vector<bool> > dp(sz + 1, vector<bool> (subsetSum + 200, false));
        
        
        for(int index = 0; index < sz; index ++ ){
            dp[index][0] = true;
        }
        
        dp[0][nums[0]] = true;
        
        for(int index = 1; index < sz; index ++ ){
            for(int target = 1; target <= subsetSum; target++){
                bool take = false;
                if( (target - nums[index]) >= 0){
                    take = dp[index - 1][target - nums[index]];
                }
                bool notTake = dp[index - 1][target];
                dp[index][target] = take | notTake;
            }
        }
        
        return dp[sz - 1][subsetSum];
    }
};