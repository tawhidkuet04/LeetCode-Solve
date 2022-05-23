class Solution {
public:
    int solve(int index, int prevTaken, vector<int> &nums,  vector< vector<int> > &dp){
        if(index >= nums.size()) return 0;
        
        if(dp[index][prevTaken]!= - 1) return dp[index][prevTaken];
        
        int take = 0;
        if(prevTaken == 0){
             take = nums[index] + solve(index + 1, 1, nums, dp);
        }
        int notTake = solve(index + 1, 0 , nums, dp);
        
        return dp[index][prevTaken] = max(take, notTake);
        
    }
    
    int rob(vector<int>& nums) {
        
        int sz = nums.size();
        
        vector< vector<int> > dp(sz + 1 , vector<int> (3, 0));
        
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        int takenPrev = nums[0];
        int notTakenPrev = 0;
        
        for(int index = 1; index < sz; index ++ ){
            int curTaken = 0, curNotTaken = 0;
            for(int prevTaken = 0; prevTaken < 2; prevTaken ++ ){
                int take = 0, notTake = 0;
                    if(prevTaken == 1){
                      take = nums[index] + notTakenPrev;
                    }
                     notTake = takenPrev;
                
                   if(prevTaken == 0 ){
                       curNotTaken = max(take, notTake);
                   }else{
                       curTaken = max(take, notTake);
                   }
                   // dp[index][prevTaken] = max(take, notTake);
            }
            
            notTakenPrev = curNotTaken;
            takenPrev = curTaken;
        }
        
        return max(takenPrev, notTakenPrev);
    }
};