class Solution {
public:
    

    
    int bin(int lo, int hi, vector<int>& nums, int target){
        int ans = -1;
        
        while(lo <= hi){
            int mid = (lo + hi )/2;
            if(nums[mid] == target) return mid;
            cout << lo << " " << hi << endl;
            if(nums[lo] <= nums[mid]){
                if (target >= nums[lo] && target <= nums[mid]){
                    hi = mid - 1;
                }else{
                    lo = mid + 1;
                }
            }else {
                if((target >= nums[mid] && target <= nums[hi])){
                    lo = mid + 1;
                }else{
                    hi = mid - 1;
                }
            }
        }
        return ans;
    }
    
    int search(vector<int>& nums, int target) {
        
       return bin(0, nums.size() - 1, nums, target);
    }
};

