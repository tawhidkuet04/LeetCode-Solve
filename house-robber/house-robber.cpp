class Solution {
public:
    int solve(int index, int prevTaken, vector<int> &nums,  vector< vector<int> > &dp){
        if(index >= nums.size()) return 0;
        
        if(dp[index][prevTaken]!= - 1) return dp[index][prevTaken];
        
        int take = 0;
        if(prevTaken == 0){
             take = nums[index] + solve(index + 1, 1 - prevTaken, nums, dp);
        }
        int notTake = solve(index + 1, 0 , nums, dp);
        
        return dp[index][prevTaken] = max(take, notTake);
        
    }
    
    int rob(vector<int>& nums) {
        
        int sz = nums.size();
        
        vector< vector<int> > dp(sz + 1 , vector<int> (3, -1));
        
        
//         for(int index = 0; index < sz; index ++ ){
//             for(int prevTaken = 0; prevTaken < 2; prevTaken ++ ){
//                 int take = 0, notTake = 0;
//                 if( (index - 1) >= 0){
//                     if(prevTaken == 0){
//                       take = nums[index] + dp[index - 1][1- prevTaken];
//                     }
//                      notTake = dp[index - 1][prevTaken];
                
//                    dp[index][prevTaken] = max(take, notTake);
//                 }
                
//             }
//         }
        
        // return max(dp[sz - 1][0], dp[sz - 1][1]);
        return solve(0, 0, nums, dp);
    }
};