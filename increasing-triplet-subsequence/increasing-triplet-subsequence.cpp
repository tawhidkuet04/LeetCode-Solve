class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int firstMn = INT_MAX, secondMin = 0;
        
        bool flag = false;
        
        for(int index = 0; index < nums.size(); index ++ ){
            if(flag){
                if(nums[index] >secondMin ) return true;
            }
            if(nums[index] > firstMn){
                secondMin = nums[index];
                flag = true;
            }else{
                firstMn = min(firstMn, nums[index]);
            }
            
        }
        
        return false;
    }
};

// 2 10 1 3