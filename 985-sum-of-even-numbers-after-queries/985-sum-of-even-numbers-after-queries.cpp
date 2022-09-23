class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int evenSum = 0 ;
        
        vector<int> ans;
        
        for(int num: nums){
            if(num % 2 == 0)
            {
                 evenSum += num;
            }           
        }
        
        for(vector<int> vec : queries){
            int val = vec[0];
            int index = vec[1];
            
            if(nums[index] % 2 == 0){
                evenSum -= nums[index];    
            }
            
             nums[index] += val;
            
            if(nums[index] % 2 == 0){
                evenSum += nums[index];
            }
            
            ans.push_back(evenSum);
        }
        
        return ans;
    }
};