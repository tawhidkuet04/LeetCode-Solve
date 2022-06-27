class Solution {
public:
    
    string makeRange(int a, int b){
        if(a > b) return "";
        if(a == b) return to_string(a);
        else {
            string str = to_string(a) + "->" + to_string(b);
            return str;
        }
    }
    
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        
        int sz = nums.size();
        
        if(sz == 0){
            string range = makeRange(lower, upper);
            
            return {range};
        }
        
        if(nums[0] > lower){
            string range = makeRange(lower, nums[0] - 1);
            if(range != ""){
                ans.push_back(range);
            }
            
        }
        
        for(int index = 1; index < sz; index ++ ){
            string range = makeRange(nums[index - 1] + 1, nums[index] - 1);
            if(range != ""){
                ans.push_back(range);
            }
        }
        
         if(nums[sz - 1] < upper){
            string range = makeRange(nums[sz - 1]  + 1,  upper);
            if(range != ""){
                ans.push_back(range);
            }
            
        }
        
        return ans;
    }
};