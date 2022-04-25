class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
         vector<int> ans;
        
        int index = 0, size = nums.size();
        
        while(index < size){
            int j = nums[index] - 1;
            if(nums[index] != nums[j]){
                swap(nums[index], nums[j]);
            }else{
                index ++;
            }
        }
        
        for(int index = 0; index < size; index ++ ){
            if( (nums[index] - 1) != index){
                ans.push_back(nums[index]);
            }
        }
        return ans;
    }
};