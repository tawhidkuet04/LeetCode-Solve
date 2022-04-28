class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int index = 0 ;
        
        while(index < nums.size()){
            if (nums[index] != 0){
                   int j = nums[index] - 1;
                   if(nums[index] != nums[j]){
                       swap(nums[index], nums[j]);
                   }else{
                       index ++ ;
                   }
            }else{
                index ++;
            }
        }
        
        int ans = 0;
        for(int index = 0; index < nums.size(); index ++ ){
            if( nums[index] == 0){
                ans = index + 1;
                break;
            }
        }
        return ans;
        
    }
};

