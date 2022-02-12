class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        unordered_map<int,int> sumOccurrencesMap;
        int sum = 0, ans = 0, cnt = 0 ;
        sumOccurrencesMap[0] = 1;
        for(int i = 0 ; i < size; i ++ ){
            sum += nums[i];
            ans += sumOccurrencesMap[sum-k];
            sumOccurrencesMap[sum]++;  
        }

        return ans;
        
    }
};

