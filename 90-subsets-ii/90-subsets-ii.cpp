class Solution {
public:
    
    
    void findSubset(int index, vector<int> &nums, vector< vector<int> > &ans, vector<int> combination, int k){
        
        if(combination.size() >= k){
            ans.push_back(combination);
            return ;
        }
        for(int start = index; start < nums.size(); start ++ ){
            if(start > index && nums[start] == nums[start - 1]) continue;
            combination.push_back(nums[start]);
            findSubset(start + 1, nums, ans, combination, k);
            combination.pop_back();
        }
        
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector< vector<int> > ans ;
        vector<int> combination;
        sort(nums.begin(), nums.end());
        for(int index = 0 ; index <= nums.size(); index ++ ){
             findSubset(0, nums, ans, combination, index);
        }
       
        return ans;
    }
};