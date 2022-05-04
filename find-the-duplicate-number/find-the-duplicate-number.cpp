class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int index = 0, size = nums.size();
        
       while(index < size){
           int j = nums[index] - 1;
           if(nums[index] != nums[j]){
               swap(nums[index], nums[j]);
           }else{
               index ++;
           }
       }
        
       int ans = 0;
        
       for(int index = 0; index < size; index ++ ){
           if((nums[index] - 1) != index){
               return nums[index];
           }
       }
        return ans;
        
    }
};