class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sz = nums.size();
        int start = 1;
        for(int index = 1; index < sz; index ++ ){
            if(nums[index] != nums[index - 1]){
                nums[start++] = nums[index];
            }
        }
        
        return start;
    }
};