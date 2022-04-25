class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
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
                ans.push_back(index + 1);
            }
        }
        return ans;
    }
};

// 1 2 3 4 3 2 7 8
    