class Solution {
public:
    void reverseArray(vector<int>& nums, int start , int end){
        
        int count = 0;
        
        for(int index = start; index < start + (end - start + 1) / 2; index ++ ){
            int temp = nums[index];
            nums[index] = nums[end - count];
            nums[end - count] = temp;
            count ++;
        }
        
    }
    
    
    void rotate(vector<int>& nums, int k) {
        int sz = nums.size();
        if(k > sz) {
            k = k % sz;
        }
        reverseArray(nums, 0, sz - 1);
        reverseArray(nums, 0, k - 1);
        reverseArray(nums, k, sz - 1);
        
    }
};