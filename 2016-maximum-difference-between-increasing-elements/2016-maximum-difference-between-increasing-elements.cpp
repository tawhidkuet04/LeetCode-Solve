class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        vector<int> maxArr(nums.size() + 1);
        for(int i = nums.size() - 1 ; i >= 0 ; i -- ){
            maxArr[i] = max(nums[i],maxArr[i + 1]);
        }
        
        int max = 0;
        for(int i = 0 ; i < nums.size() - 1; i ++ ){
            if((maxArr[i + 1] - nums[i]) > max){
                max = (maxArr[i + 1] - nums[i]);
            }
        }
        return (max == 0) ? -1 : max;
    }
};