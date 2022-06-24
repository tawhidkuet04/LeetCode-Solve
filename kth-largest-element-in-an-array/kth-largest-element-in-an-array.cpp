class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());
        
        return nums[nums.size() - k];
    }
};



// [3,2,1,5,6,4]
// [1,2,3,4,5,6]


// [3,2,3,1,2,4,5,5,6]
// 1 2 2 3 3 4 5 5 6
// 4