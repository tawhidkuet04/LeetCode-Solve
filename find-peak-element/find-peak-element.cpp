class Solution {
public:
    int solve(int lo, int hi, vector<int>& nums){
        while(lo <= hi){
            int mid = (lo + hi)/2;
            
            if( (mid == 0 || (nums[mid] >= nums[mid - 1])) && ( mid == nums.size() - 1|| (nums[mid]>= nums[mid + 1]))){
                return mid;
            }
            
            if( mid != 0 && nums[mid - 1 ] > nums[mid]){
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }
        
        return -1;
    }
    
    int findPeakElement(vector<int>& nums) {
        return solve(0, nums.size() -1, nums);
    }
};