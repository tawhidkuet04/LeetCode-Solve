class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        unordered_map <int, int> hashMap;
        vector<int> ans;
        for(int i = 0 ; i < size; i ++ ){
            auto it = hashMap.find(target - nums[i]);
             if( it != hashMap.end() ){
                 ans.push_back(i);
                 ans.push_back(it->second);
                 break;
             }
             hashMap[nums[i]] = i;
           } 
        
        return ans;

    }
};