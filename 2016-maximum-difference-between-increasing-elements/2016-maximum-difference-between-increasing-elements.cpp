class Solution {
public:
    int maximumDifference(vector<int>& nums) {

        int maxAns = 0, maxDiff = 0;
        for(int i =  nums.size() - 2 ; i >= 0; i -- ){
            maxDiff = max(maxDiff, nums[i + 1]);
            if((maxDiff - nums[i]) > maxAns){
                maxAns = (maxDiff - nums[i]);
            }
        }
        return (maxAns == 0) ? -1 : maxAns;
    }
};