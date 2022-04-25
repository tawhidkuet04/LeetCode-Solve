class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        
        int oneCount = 0 ;
        
        
        for(int index = 0; index < size; index ++){
            if(nums[index] == 1) oneCount ++;
            if(nums[index] <= 0 || nums[index] > size) nums[index] = 1;
        }
        
        if(oneCount == 0) return 1;
        int index = 0 ;
        
        while(index < size){
            int j = nums[index] - 1;
            if(nums[index] != nums[j]){
                swap(nums[index], nums[j]);
            }else{
                index ++;
            }

        }
        int ans = size + 1;
        for(int index = 0; index < size; index ++ ){
            if( (nums[index] - 1) != index ){
                return index + 1;
            }
        }
        return ans;
    }
};


