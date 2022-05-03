class Solution {
public:
    
    void twoSum(vector<int> &nums, int k, int left, int &ans){
        
        int size = nums.size(), right = size - 1;
        int cur = left - 1;
        
        while(left < right){
            int sum = nums[left] + nums[right] + nums[cur];
            
            if(sum >= k){
                right -- ;
            }else if(sum < k ){
                ans += (right - left);
                left ++;
            }
        }
        
    }
    
    
    int threeSumSmaller(vector<int>& nums, int target) {
   
        int size = nums.size();
        int ans = 0;
        
        if(size < 3) return ans;
        sort(nums.begin(), nums.end());
        for(int index = 0; index <= size - 3; index ++ ){
            // if(index > 0 && (nums[index] == nums[index - 1])) continue;
            twoSum(nums, target, index + 1, ans);
        }
        
        return ans;
    }
};

